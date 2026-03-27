#include "UIManager.hpp"
#include "resources/UI.hpp"
#include <wx/log.h>

namespace UIManager {

    wxFrame* LoadFrame(const wxString& frameName, const wxString& xrcFile) {
        wxXmlResource::Get()->InitAllHandlers();
        if (!xrcFile || xrcFile == "") {
            InitXmlResource();
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
