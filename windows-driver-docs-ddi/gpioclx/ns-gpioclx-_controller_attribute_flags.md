# _CONTROLLER_ATTRIBUTE_FLAGS structure

## Description

The **CONTROLLER_ATTRIBUTE_FLAGS** structure describes the hardware attributes of the general-purpose I/O (GPIO) controller device.

## Members

### `MemoryMappedController`

Whether the GPIO controller is memory-mapped. If this flag is set, the hardware registers of the GPIO controller are mapped to memory addresses, and can be directly accessed by a GPIO controller driver routine that is running at DIRQL. Otherwise, the registers of the GPIO controller can be accessed only by means of I/O requests, which the GPIO controller driver sends at IRQL = PASSIVE_LEVEL. For more information, see Remarks.

### `ActiveInterruptsAutoClearOnRead`

Whether active interrupts are automatically cleared when the GPIO controller driver reads them. If this flag is set, GpioClx assumes that interrupts are automatically cleared when they are read and, therefore, does not explicitly request that the driver clear active interrupts during interrupt processing. Otherwise, GpioClx explicitly requests that active interrupts be cleared. For more information, see the discussion of the **ActiveInterruptsAutoClearOnRead** flag bit in [GPIO_CLIENT_REGISTRATION_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_gpio_client_registration_packet).

### `FormatIoRequestsAsMasks`

Whether callback functions that read from or write to GPIO pins should specify read and write values as 64-bit masks. If this flag is set, GpioClx uses [CLIENT_ReadGpioPinsUsingMask](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_read_pins_mask) callbacks that read GPIO pin values into masks, and [CLIENT_WriteGpioPinsUsingMask](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_write_pins_mask) callbacks that use masks to designate GPIO pins to set and clear. Otherwise, GpioClx uses [CLIENT_ReadGpioPins](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_read_pins) and [CLIENT_WriteGpioPins](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_write_pins) callbacks that use arrays of pin numbers to specify which GPIO pins to access. For more information, see the discussion of the **FormatIoRequestsAsMasks** flag bit in [GPIO_CLIENT_REGISTRATION_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_gpio_client_registration_packet).

### `DeviceIdlePowerMgmtSupported`

Whether the GPIO controller supports device-level power management. If this flag is set, the GPIO controller can be put into a low-power (D3) state when it is idle (that is, when there are no active connections to the controller). Otherwise, the GPIO controller remains in the fully on (D0) power state any time the controller is turned on.

### `BankIdlePowerMgmtSupported`

Whether the GPIO controller supports component-level power management. If this flag is set, one or more banks in the GPIO controller can be put into a low-power state independently of the other banks in the GPIO controller. Otherwise, the power states of the banks cannot be individually controlled. This flag can be set only for a GPIO controller whose registers are memory-mapped, as indicated by the **MemoryMappedController** flag. Typically, only a GPIO controller that is an integrated part of a SoC module is memory-mapped. A GPIO controller that is external the SoC module is typically not memory-mapped.

### `EmulateDebouncing`

Whether debouncing of input signals to GPIO pins is performed by software or by hardware. If this flag is set, the GPIO controller requires debouncing to be emulated in software by the GPIO framework extension (GpioClx). Otherwise, debouncing is performed by hardware, and software-emulated debouncing is unnecessary.

### `EmulateActiveBoth`

Whether the GPIO controller driver requires GpioClx to emulate active-both interrupts in software. If this flag is set, GpioClx emulates active-both interrupts in software. Otherwise, GpioClx does not emulate active-both interrupts. For more information, see Remarks.

### `IndependentIoHwSupported`

### `Reserved`

Reserved for system use.

### `AsULONG`

## Remarks

The **Flags** member of the [CLIENT_CONTROLLER_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_client_controller_basic_information) structure is a **CONTROLLER_ATTRIBUTE_FLAGS** structure.

GpioClx implements an interrupt service routine (ISR) to service interrupts from the GPIO controller. If the **MemoryMappedController** flag bit is set, this ISR directly accesses the hardware registers of the GPIO controller. Otherwise, the ISR schedules a worker thread to handle the interrupt, and this worker thread, which runs at IRQL = PASSIVE_LEVEL, calls the driver's interrupt-related callback functions to handle the interrupt. These functions use I/O requests to transfer data and control information to and from the GPIO controller's registers. Because these I/O requests are sent from a passive-level thread, they can be sent synchronously.

For more information about the **MemoryMappedController** flag bit, see [Interrupt-Related Callbacks](https://learn.microsoft.com/windows-hardware/drivers/gpio/interrupt-related-callbacks).

An active-both interrupt is an edge-triggered interrupt for which an interrupt request is indicated by a low-to-high or a high-to-low transition on the interrupt line. After a low-to-high transition signals an interrupt request, the interrupt line remains high until a high-to-low transition signals the next interrupt request. Similarly, after a high-to-low transition signals an interrupt request, the interrupt line remains low until a low-to-high transition signals the next interrupt request.

A push-button device is typically connected to an active-both interrupt. An interrupt is generated when the user presses the button, and another interrupt is generated when the button is released. If a device driver's ISR is connected to an active-both interrupt, the ISR is called on both rising and falling edges of the signal line.

Some GPIO controllers implement active-both interrupt inputs in hardware. However, if the hardware does not support active-both interrupts, the GPIO controller driver sets the **EmulateActiveBoth** flag to request that GpioClx emulate active-both interrupts in software. A driver that sets this flag must implement a [CLIENT_ReconfigureInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_reconfigure_interrupt) callback function. To emulate an active-both interrupt pin, GpioClx calls this function to alternately configure a GPIO pin for active-high and active-low level-mode interrupts.

## See also

[CLIENT_CONTROLLER_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_client_controller_basic_information)

[CLIENT_QueryActiveInterrupts](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_query_active_interrupts)

[CLIENT_ReadGpioPins](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_read_pins)

[CLIENT_ReadGpioPinsUsingMask](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_read_pins_mask)

[CLIENT_ReconfigureInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_reconfigure_interrupt)

[CLIENT_WriteGpioPins](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_write_pins)

[CLIENT_WriteGpioPinsUsingMask](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_write_pins_mask)

[GPIO_CLIENT_REGISTRATION_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_gpio_client_registration_packet)