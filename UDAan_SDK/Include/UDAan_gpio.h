#pragma once
#include <cstdint>
#include <utility>
#include "stm32h7xx_hal.h"

#ifdef __cplusplus
extern "C"
{
#endif

    typedef void (*UDAan_gpio_callback_t)(void *context, int pin);

#ifdef __cplusplus
}
#endif

namespace UDAan
{
    enum class PinLevel : uint8_t
    {
        LOW = GPIO_PIN_RESET,
        HIGH = GPIO_PIN_SET
    };

    enum class PinMode : uint8_t
    {
        INPUT = GPIO_MODE_INPUT,
        OUT_PP = GPIO_MODE_OUTPUT_PP,
        OUT_OD = GPIO_MODE_OUTPUT_OD,
        ALTERNATE_PP = GPIO_MODE_AF_PP,
        ANALOG = GPIO_MODE_ANALOG
    };

    enum class PinPull : uint8_t
    {
        NOPULL = GPIO_NOPULL,
        PULLUP = GPIO_PULLUP,
        PULLDOWN = GPIO_PULLDOWN
    };

    enum class PinSpeed : uint8_t
    {
        LOW = GPIO_SPEED_FREQ_LOW,
        MEDIUM = GPIO_SPEED_FREQ_MEDIUM,
        HIGH = GPIO_SPEED_FREQ_HIGH,
        VERY_HIGH = GPIO_SPEED_FREQ_VERY_HIGH
    };

    enum class InterruptTrigger : uint8_t
    {
        RISING,
        FALLING,
        RISING_FALLING
    };

    class GPIO
    {
    public:
        GPIO(GPIO_TypeDef *port, uint16_t pin) noexcept;
        ~GPIO();

        GPIO(const GPIO &) = delete;
        GPIO &operator=(const GPIO &) = delete;
        GPIO(GPIO &&) noexcept = default;
        GPIO &operator=(GPIO &&) noexcept = default;
    };
}