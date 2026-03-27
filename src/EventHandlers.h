#ifndef EVENTHANDLERS_H
#define EVENTHANDLERS_H

#include <wx/wx.h>

namespace EventHandlers {
    void OnOpen(wxCommandEvent& event);
    void OnSave(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnCut(wxCommandEvent& event);
    void OnCopy(wxCommandEvent& event);
    void OnPaste(wxCommandEvent& event);
}

#endif // EVENTHANDLERS_H
