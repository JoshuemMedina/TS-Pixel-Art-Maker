#include "ofMain.h"
#include "ofApp.h"
#include <GLFW/glfw3.h>
#include <memory>

int main() {
    ofSetFrameRate(60);

    // Settings
    ofGLFWWindowSettings settings;
    settings.setSize(1720, 920);
    settings.resizable = false;
    settings.windowMode = OF_WINDOW;
    settings.setGLVersion(3, 2);
    auto window = ofCreateWindow(settings);

    // Icon
    ofImage icon;
    icon.load("Icon.ico");

    GLFWimage images[1];
    images[0].width = icon.getWidth();
    images[0].height = icon.getHeight();
    images[0].pixels = icon.getPixels().getData();

    auto glfwWindow = std::dynamic_pointer_cast<ofAppGLFWWindow>(window);
    GLFWwindow* nativeWindow = glfwWindow->getGLFWWindow();

    glfwSetWindowIcon(nativeWindow, 1, images);

    // Run
    ofRunApp(new ofApp());
}