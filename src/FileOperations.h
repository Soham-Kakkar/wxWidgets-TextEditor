#ifndef FILEOPERATIONS_H
#define FILEOPERATIONS_H

#include <wx/wx.h>
#include <wx/textfile.h>
#include <wx/filedlg.h>
#include <wx/msgdlg.h>
#include <wx/textctrl.h>

namespace FileOperations {
    void OpenFile(wxTextCtrl* textCtrl);
    void SaveFile(wxTextCtrl* textCtrl);
}

#endif // FILEOPERATIONS_H
