//{{{  includes
#include <SDL.h>

#include "display/gldisplay.h"
#include "imgui.h"

#include "render_embree.h"
#include "render_plugin.h"

using namespace std;
//}}}

//{{{
uint32_t get_sdl_window_flags()
{
    return SDL_WINDOW_OPENGL;
}
//}}}

//{{{
void set_imgui_context (ImGuiContext* context)
{
    ImGui::SetCurrentContext(context);
}
//}}}
//{{{
unique_ptr<Display> make_display (SDL_Window* window)
{
    return make_unique<GLDisplay>(window);
}
//}}}
//{{{
unique_ptr<RenderBackend> make_renderer (Display*)
{
    return make_unique<RenderEmbree>();
}
//}}}

POPULATE_PLUGIN_FUNCTIONS(get_sdl_window_flags, set_imgui_context, make_display, make_renderer)
