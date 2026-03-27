#ifndef FILEOPERATIONS_HPP
#define FILEOPERATIONS_HPP

#include <wx/wx.h>
#include <wx/textfile.h>
#include <wx/filedlg.h>
#include <wx/msgdlg.h>
#include <wx/textctrl.h>

namespace FileOperations {
    void OpenFile(wxTextCtrl* textCtrl);
    void SaveFile(wxTextCtrl* textCtrl);
}

#endif // FILEOPERATIONS_HPP
