#include <Spydr.h>
#include <imgui/imgui.h>

class ExampleLayer : public Spydr::Layer
{
public:
	ExampleLayer() : Layer("Example")
	{
	}

	void OnUpdate() override
	{
		//SP_INFO("ExampleLayer::Update");
		if (Spydr::Input::IsKeyPressed(SP_KEY_TAB)) {
			SP_TRACE("Tab key is pressed!");
		}
	}

	void OnEvent(Spydr::Event& event) override
	{
		if (event.GetEventType() == Spydr::EventType::KeyPressed) {
			Spydr::KeyPressedEvent& e = (Spydr::KeyPressedEvent&)event;
			if (e.IsAlphaNumericKey()) {
				SP_TRACE("'{0}' is pressed", (char)e.GetKeyCode());
			}
		}
	}

	void OnImGuiRender()
	{
		ImGui::Begin("Sandbox");
		ImGui::Text("Hello from Sandbox");
		ImGui::End();
	}
};

class Sandbox : public Spydr::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}
};

Spydr::Application* Spydr::CreateApplication()
{
	return new Sandbox();
}