#include "pch.h"
#include "GameObject.h"
#include "Components/Component.h"
#include "Components/Render.h"

namespace sn {
	bool GameObject::Create(void* data)
	{
		return false;
	}

	void GameObject::Destroy()
	{
		RemoveAllComponents();
	}

	void GameObject::Update()
	{
		for (auto component : m_components) {
			component->Update();
		}
	}
	void GameObject::Draw()
	{
		Render* rComp = GetComponent<Render>();
		if (rComp) {
			rComp->Draw();
		}
	}

	void GameObject::AddComponent(Component* component)
	{
		component->m_owner = this;
		m_components.push_back(component);
	}

	void GameObject::RemoveComponent(Component* component)
	{
		auto iter = std::find(m_components.begin(), m_components.end(), component);
		if (iter != m_components.end()) {
			(*iter)->Destroy();
			delete (*iter);
		}
	}

	void GameObject::RemoveAllComponents()
	{
		for (auto component : m_components) {
			component->Destroy();
			delete component;
		}
		m_components.clear();
	}
}