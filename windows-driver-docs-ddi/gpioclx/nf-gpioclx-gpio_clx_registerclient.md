# GPIO_CLX_RegisterClient function

## Description

The **GPIO_CLX_RegisterClient** method registers a general-purpose I/O (GPIO) controller driver as a client of the GPIO framework extension (GpioClx).

## Parameters

### `Driver` [in]

A WDFDRIVER handle to the framework driver object for the GPIO controller driver.

### `RegistrationPacket` [in, out]

A pointer to a caller-allocated [GPIO_CLIENT_REGISTRATION_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_gpio_client_registration_packet) structure that contains the caller's registration information. This structure contains pointers to the event callback functions that the GPIO controller driver implements. Additionally, this structure specifies the size of the device context that the GPIO controller driver requires for its internal configuration data and state information.

### `RegistryPath` [in]

A pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that contains the path name of the registry key for the GPIO controller driver. This parameter should be the registry path name that was passed to the driver's [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine. For more information about driver registry keys, see [Registry Trees for Devices and Drivers](https://learn.microsoft.com/windows-hardware/drivers/install/overview-of-registry-trees-and-keys).

## Return value

**GPIO_CLX_RegisterClient** returns STATUS_SUCCESS if the call is successful. Possible return values include the following error codes.

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | The *Driver*, *RegistrationPacket*, or *RegistryPath* parameter is NULL. |
| **STATUS_GPIO_INVALID_REGISTRATION_PACKET** | The specified registration packet is not valid. |
| **STATUS_INSUFFICIENT_RESOURCES** | Out of memory. |

## Remarks

The GPIO controller driver calls this method to register its event callback functions with GpioClx. Typically, the driver calls this method from its **DriverEntry** routine, which runs shortly after the driver is loaded into memory.

Later, just before the GPIO controller driver unloads, the driver calls the [GPIO_CLX_UnregisterClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nf-gpioclx-gpio_clx_unregisterclient) method to cancel its registration with GpioClx.

## See also

[DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver)

[GPIO_CLIENT_REGISTRATION_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_gpio_client_registration_packet)

[GPIO_CLX_UnregisterClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nf-gpioclx-gpio_clx_unregisterclient)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)