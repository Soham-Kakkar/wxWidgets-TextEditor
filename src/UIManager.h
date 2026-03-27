#ifndef UIMANAGER_H
#define UIMANAGER_H

#include <wx/wx.h>
#include <wx/xrc/xmlres.h>

namespace UIManager {
    wxFrame* LoadFrame(const wxString& frameName, const wxString& xrcFile = "");
}

#endif // UIMANAGER_H
