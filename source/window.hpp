// dsk

#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>

namespace dsk
{
    class DskWindow
    {
        public:
            DskWindow(int w, int h, std::string name);
            ~DskWindow();

            DskWindow(const DskWindow &) = delete;
            DskWindow &operator=(const DskWindow &) = delete;

            bool shouldClose() { return glfwWindowShouldClose(window); }

            VkExtent2D getExtent()
            {
                return
                {
                    static_cast<uint32_t>(width),
                    static_cast<uint32_t>(height)
                }; 
            }

            bool wasWindowResized() { return framebufferResized; }

            void resetWindowResizedFlag() { framebufferResized = false; }

            GLFWwindow *getGLFWwindow() const { return window; }

            void createWindowSurface(VkInstance instance, VkSurfaceKHR *surface);

        private:
            static void framebufferResizeCallback
            (
                GLFWwindow *window,
                int width,
                int height
            );

            void initWindow();

            int width;
            int height;
            bool framebufferResized = false;

            std::string windowName;
            GLFWwindow *window;
    };
}