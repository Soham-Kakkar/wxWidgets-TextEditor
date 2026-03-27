#include "UIManager.hpp"
#ifndef DEBUG
#include "resources/UI.hpp"
#endif
#include <wx/log.h>

namespace UIManager {

    wxFrame* LoadFrame(const wxString& frameName, const wxString& xrcFile) {
        wxXmlResource::Get()->InitAllHandlers();
        if (!xrcFile || xrcFile == "") {
            #ifndef DEBUG
            InitXmlResource();
            #else
            wxLogWarning("Release mode expected for embedded resources.");
            #endif
        } else {
            if (!wxXmlResource::Get()->Load(xrcFile)) {
                wxLogError("Failed to load XRC resource.");
                return nullptr;
            }
        }

        wxFrame* frame = wxXmlResource::Get()->LoadFrame(nullptr, frameName);
        if (!frame) {
            wxLogError("Failed to load frame from XRC.");
        }
        return frame;
    }

} // namespace UIManager
