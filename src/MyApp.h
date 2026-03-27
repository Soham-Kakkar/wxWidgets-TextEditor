#ifndef MYAPP_H
#define MYAPP_H

#include <wx/wx.h>
#include <wx/xrc/xmlres.h>
#include "EventHandlers.h"

class MyApp : public wxApp
{
private:
    wxFrame* frame;
    wxTextCtrl* m_textCtrl;

public:
    wxFrame* getMainFrame();
    virtual bool OnInit() override;

    // Event handlers
    void OnOpen(wxCommandEvent& event);
    void OnSave(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnCut(wxCommandEvent& event);
    void OnCopy(wxCommandEvent& event);
    void OnPaste(wxCommandEvent& event);
};

#endif // MYAPP_H
