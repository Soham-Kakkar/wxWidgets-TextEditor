#ifndef EVENTHANDLERS_HPP
#define EVENTHANDLERS_HPP

#include <wx/wx.h>

namespace EventHandlers {
    void OnOpen(wxCommandEvent& event);
    void OnSave(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnCut(wxCommandEvent& event);
    void OnCopy(wxCommandEvent& event);
    void OnPaste(wxCommandEvent& event);
}

#endif // EVENTHANDLERS_HPP
