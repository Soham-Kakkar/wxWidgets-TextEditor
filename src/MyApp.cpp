#include "MyApp.hpp"
#include "FileOperations.hpp"
#include "UIManager.hpp"
#include "EventHandlers.hpp"

wxFrame* MyApp::getMainFrame() {
    frame = UIManager::LoadFrame("MainFrame");  // Specify absolute path of XRC file to enable UI 'hot' reload
    return frame;
}

bool MyApp::OnInit() {
    wxFrame* frame = getMainFrame();
    frame->Show(true);

    wxMenuBar* menuBar = frame->GetMenuBar();
    if (menuBar) {
        wxMenu* fileMenu = menuBar->GetMenu(0);
        fileMenu->Bind(wxEVT_MENU, &MyApp::OnOpen, this, XRCID("Open"));
        fileMenu->Bind(wxEVT_MENU, &MyApp::OnSave, this, XRCID("Save"));
        fileMenu->Bind(wxEVT_MENU, &MyApp::OnExit, this, XRCID("Exit"));
        
        wxMenu* editMenu = menuBar->GetMenu(1);
        editMenu->Bind(wxEVT_MENU, &MyApp::OnCut, this, XRCID("Cut"));
        editMenu->Bind(wxEVT_MENU, &MyApp::OnCopy, this, XRCID("Copy"));
        editMenu->Bind(wxEVT_MENU, &MyApp::OnPaste, this, XRCID("Paste"));
    }

    m_textCtrl = XRCCTRL(*frame, "TextArea", wxTextCtrl);
    return true;
}

void MyApp::OnOpen(wxCommandEvent& event) {
    FileOperations::OpenFile(m_textCtrl);
}

void MyApp::OnSave(wxCommandEvent& event) {
    FileOperations::SaveFile(m_textCtrl);
}

void MyApp::OnExit(wxCommandEvent& event) {
    if (wxMessageBox("Are you sure you want to exit?", "Confirm Exit", wxYES_NO | wxICON_QUESTION) == wxYES) {
        wxApp::GetInstance()->ExitMainLoop();
    }
}

void MyApp::OnCut(wxCommandEvent& event) {
    m_textCtrl->Cut();
}

void MyApp::OnCopy(wxCommandEvent& event) {
    m_textCtrl->Copy();
}

void MyApp::OnPaste(wxCommandEvent& event) {
    m_textCtrl->Paste();
}
