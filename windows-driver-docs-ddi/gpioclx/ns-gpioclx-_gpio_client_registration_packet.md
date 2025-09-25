# _GPIO_CLIENT_REGISTRATION_PACKET structure

## Description

The **GPIO_CLIENT_REGISTRATION_PACKET** structure contains registration information that the general-purpose I/O (GPIO) controller driver passes to the GPIO framework extension (GpioClx).

## Members

### `Version`

The version number for the GPIO interface that the GPIO controller driver supports. Set this member to the value GPIO_CLIENT_VERSION, which is defined in the Gpioclx.h header file.

### `Size`

The size, in bytes, of this structure. Set this member to **sizeof**(**GPIO_CLIENT_REGISTRATION_PACKET**).

### `Flags`

A set of flags that indicate which registration options are selected. No flags are currently defined for registration options. Set this member to zero.

### `ControllerContextSize`

The required device context size, in bytes. The [GPIO_CLX_RegisterClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nf-gpioclx-gpio_clx_registerclient) method allocates a device context of this size. When GpioClx calls any registered callback function in the **GPIO_CLIENT_REGISTRATION_PACKET** structure, GpioClx passes this device context to the callback function as a parameter. The callback functions use this context to access and update the driver's information about the state of the GPIO controller device. For more information, see [GPIO Device Contexts](https://learn.microsoft.com/windows-hardware/drivers/gpio/gpio-device-contexts).

### `Reserved`

Reserved for future use. Set this member to zero.

### `CLIENT_PrepareController`

A pointer to the GPIO controller driver's [CLIENT_PrepareController](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_prepare_controller) event callback function.

### `CLIENT_ReleaseController`

A pointer to the GPIO controller driver's [CLIENT_ReleaseController](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_release_controller) event callback function.

### `CLIENT_StartController`

A pointer to the GPIO controller driver's [CLIENT_StartController](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_start_controller) event callback function.

### `CLIENT_StopController`

A pointer to the GPIO controller driver's [CLIENT_StopController](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_stop_controller) event callback function.

### `CLIENT_QueryControllerBasicInformation`

A pointer to the GPIO controller driver's [CLIENT_QueryControllerBasicInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_query_controller_basic_information) event callback function.

### `CLIENT_QuerySetControllerInformation`

A pointer to the GPIO controller driver's [CLIENT_QuerySetControllerInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_query_set_controller_information) event callback function.

### `CLIENT_EnableInterrupt`

A pointer to the GPIO controller driver's [CLIENT_EnableInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_enable_interrupt) event callback function.

### `CLIENT_DisableInterrupt`

A pointer to the GPIO controller driver's [CLIENT_DisableInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_disable_interrupt) event callback function.

### `CLIENT_UnmaskInterrupt`

A pointer to the GPIO controller driver's [CLIENT_UnmaskInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_unmask_interrupt) event callback function.

### `CLIENT_MaskInterrupts`

A pointer to the GPIO controller driver's [CLIENT_MaskInterrupts](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_mask_interrupts) event callback function.

### `CLIENT_QueryActiveInterrupts`

A pointer to the GPIO controller driver's [CLIENT_QueryActiveInterrupts](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_query_active_interrupts) event callback function.

### `CLIENT_ClearActiveInterrupts`

A pointer to the GPIO controller driver's [CLIENT_ClearActiveInterrupts](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_clear_active_interrupts) event callback function.

### `CLIENT_ConnectIoPins`

A pointer to the GPIO controller driver's [CLIENT_ConnectIoPins](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_connect_io_pins) event callback function.

### `CLIENT_DisconnectIoPins`

A pointer to the GPIO controller driver's [CLIENT_DisconnectIoPins](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_disconnect_io_pins) event callback function.

### `CLIENT_ReadGpioPins`

A pointer to the GPIO controller driver's [CLIENT_ReadGpioPins](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_read_pins) event callback function.

### `CLIENT_ReadGpioPinsUsingMask`

A pointer to the GPIO controller driver's [CLIENT_ReadGpioPinsUsingMask](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_read_pins_mask) event callback function.

### `CLIENT_WriteGpioPins`

A pointer to the GPIO controller driver's [CLIENT_WriteGpioPins](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_write_pins) event callback function.

### `CLIENT_WriteGpioPinsUsingMask`

A pointer to the GPIO controller driver's [CLIENT_WriteGpioPinsUsingMask](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_write_pins_mask) event callback function.

### `CLIENT_SaveBankHardwareContext`

A pointer to the GPIO controller driver's [CLIENT_SaveBankHardwareContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_save_bank_hardware_context) event callback function.

### `CLIENT_RestoreBankHardwareContext`

A pointer to the GPIO controller driver's [CLIENT_RestoreBankHardwareContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_restore_bank_hardware_context) event callback function.

### `CLIENT_PreProcessControllerInterrupt`

A pointer to the GPIO controller driver's [CLIENT_PreProcessControllerInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_pre_process_controller_interrupt) event callback function.

### `CLIENT_ControllerSpecificFunction`

A pointer to the GPIO controller driver's [CLIENT_ControllerSpecificFunction](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_controller_specific_function) event callback function.

### `CLIENT_ReconfigureInterrupt`

A pointer to the GPIO controller driver's [CLIENT_ReconfigureInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_reconfigure_interrupt) event callback function.

### `CLIENT_QueryEnabledInterrupts`

A pointer to the GPIO controller driver's [CLIENT_QueryEnabledInterrupts](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_query_enabled_interrupts) event callback function. This member is supported starting with Windows 8.1.

### `CLIENT_ConnectFunctionConfigPins`

### `CLIENT_DisconnectFunctionConfigPins`

## Remarks

The GPIO controller driver passes a pointer to a **GPIO_CLIENT_REGISTRATION_PACKET** structure as an input parameter to the [GPIO_CLX_RegisterClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nf-gpioclx-gpio_clx_registerclient) method. This method registers the driver to use the services provided by GpioClx. Typically, the driver calls this method from its [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine.

The **GPIO_CLIENT_REGISTRATION_PACKET** structure contains two unnamed unions. Each union can contain a pointer to one of two alternative types of event callback functions. In each case, your GPIO controller driver should implement the type of callback function that is best suited to the GPIO controller hardware. The GPIO controller driver's *CLIENT_QueryControllerBasicInformation* callback function informs GpioClx which callback functions are implemented.

After the GPIO controller driver calls **GPIO_CLX_RegisterClient** to register a set of callbacks, GpioClx calls the driver's *CLIENT_QueryControllerBasicInformation* callback function to obtain a [CLIENT_CONTROLLER_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_client_controller_basic_information) structure that contains GPIO controller hardware attributes and configuration data. GpioClx uses this information to determine which callback functions the GPIO controller driver has implemented.

If the GPIO controller driver implements *CLIENT_ReadGpioPins* and *CLIENT_WriteGpioPins* callback functions, the *CLIENT_QueryControllerBasicInformation* callback function should set the **FormatIoRequestsAsMasks** flag bit in the **Flags** member of this **CLIENT_CONTROLLER_BASIC_INFORMATION** structure to 0.

If the *CLIENT_QueryControllerBasicInformation* callback function sets the **FormatIoRequestsAsMasks** flag bit to 1, this value indicates that the driver implements *CLIENT_ReadGpioPinsUsingMask* and *CLIENT_WriteGpioPinsUsingMask* callback functions.

GpioClx requires a GPIO controller driver to implement certain callback functions, but support for other callback functions is optional. For more information, see [Optional and Required GPIO Callback Functions](https://learn.microsoft.com/windows-hardware/drivers/gpio/optional-and-required-gpio-callback-functions).

## See also

[CLIENT_CONTROLLER_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_client_controller_basic_information)

[CLIENT_ClearActiveInterrupts](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_clear_active_interrupts)

[CLIENT_ConnectIoPins](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_connect_io_pins)

[CLIENT_ControllerSpecificFunction](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_controller_specific_function)

[CLIENT_DisableInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_disable_interrupt)

[CLIENT_DisconnectIoPins](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_disconnect_io_pins)

[CLIENT_EnableInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_enable_interrupt)

[CLIENT_MaskInterrupts](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_mask_interrupts)

[CLIENT_PreProcessControllerInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_pre_process_controller_interrupt)

[CLIENT_PrepareController](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_prepare_controller)

[CLIENT_QueryActiveInterrupts](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_query_active_interrupts)

[CLIENT_QueryControllerBasicInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_query_controller_basic_information)

[CLIENT_QueryEnabledInterrupts](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_query_enabled_interrupts)

[CLIENT_ReadGpioPins](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_read_pins)

[CLIENT_ReadGpioPinsUsingMask](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_read_pins_mask)

[CLIENT_ReconfigureInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_reconfigure_interrupt)

[CLIENT_ReleaseController](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_release_controller)

[CLIENT_RestoreBankHardwareContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_restore_bank_hardware_context)

[CLIENT_SaveBankHardwareContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_save_bank_hardware_context)

[CLIENT_StartController](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_start_controller)

[CLIENT_StopController](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_stop_controller)

[CLIENT_UnmaskInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_unmask_interrupt)

[CLIENT_WriteGpioPins](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_write_pins)

[CLIENT_WriteGpioPinsUsingMask](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_write_pins_mask)

[DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver)

[GPIO_CLX_RegisterClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nf-gpioclx-gpio_clx_registerclient)