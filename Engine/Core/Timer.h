#pragma once
#include <chrono>

namespace sn {
	class Timer {
	public:
		using clock = std::chrono::high_resolution_clock;
		using clock_duration = std::chrono::duration<clock::rep, std::nano>;

	public:
		Timer() : m_timePoint(clock::now()) {}

		void Reset();
		clock::rep GetElapsedTicks();
		clock::rep TicksPerSecond();

		double GetElapsedSeconds();

	protected:
		clock::time_point m_timePoint;
	};

	class FrameTimer : public Timer {
	public:
		void Tick();
		float DeltaTime() {return m_dt;}

	protected:
		float m_dt{ 0 };
	};
}