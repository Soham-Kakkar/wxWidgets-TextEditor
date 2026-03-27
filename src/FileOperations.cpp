#include "FileOperations.h"

namespace FileOperations {

    void OpenFile(wxTextCtrl* textCtrl) {
        wxFileDialog openFileDialog(nullptr, "Open text file", "", "", 
            "Text files (*.txt)|*.txt|Markdown files (*.md)|*.md|All files (*.*)|*.*",
            wxFD_OPEN | wxFD_FILE_MUST_EXIST);

        if (openFileDialog.ShowModal() == wxID_OK) {
            wxString filePath = openFileDialog.GetPath();
            wxTextFile file;
            if (file.Open(filePath)) {
                wxString content;
                for (size_t i = 0; i < file.GetLineCount(); ++i) {
                    content += file.GetLine(i) + "\n";
                }
                textCtrl->SetValue(content);
            } else {
                wxLogError("Failed to open file for reading.");
            }
        }
    }

    void SaveFile(wxTextCtrl* textCtrl) {
        wxFileDialog saveFileDialog(nullptr, "Save text file", "", "", 
            "Text files (*.txt)|*.txt|Markdown files (*.md)|*.md|All files (*.*)|*.*", 
            wxFD_SAVE | wxFD_OVERWRITE_PROMPT);

        if (saveFileDialog.ShowModal() == wxID_OK) {
            wxString filePath = saveFileDialog.GetPath();
            wxTextFile file;
            if (file.Create(filePath)) {
                wxString content = textCtrl->GetValue();
                file.AddLine(content);
                file.Write();
            } else {
                wxLogError("Failed to save file.");
            }
        }
    }

} // namespace FileOperations
