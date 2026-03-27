#ifndef UIMANAGER_HPP
#define UIMANAGER_HPP

#include <wx/wx.h>
#include <wx/xrc/xmlres.h>

namespace UIManager {
    wxFrame* LoadFrame(const wxString& frameName, const wxString& xrcFile = "");
}

#endif // UIMANAGER_HPP
