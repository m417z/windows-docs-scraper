# GPIO_CLIENT_DISCONNECT_IO_PINS callback function

## Description

The *CLIENT_DisconnectIoPins* event callback function closes a logical connection to a set of general-purpose I/O (GPIO) pins that are configured for data read or write operations.

## Parameters

### `Context` [in]

A pointer to the GPIO controller driver's [device context](https://learn.microsoft.com/windows-hardware/drivers/gpio/gpio-device-contexts).

### `DisconnectParameters` [in]

A pointer to a [GPIO_DISCONNECT_IO_PINS_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_gpio_disconnect_io_pins_parameters) structure that describes the set of GPIO pins that are to be disconnected.

## Return value

The *CLIENT_DisconnectIoPins* function returns STATUS_SUCCESS if the call is successful. Otherwise, it returns an appropriate error code.

## Remarks

This callback function is implemented by the GPIO controller driver. The GPIO framework extension (GpioClx) calls this function to close a connection that was previously opened by a call to the [CLIENT_ConnectIoPins](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_connect_io_pins) callback function.

To register your driver's *CLIENT_DisconnectIoPins* callback function, call the [GPIO_CLX_RegisterClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nf-gpioclx-gpio_clx_registerclient) method. This method accepts, as an input parameter, a pointer to a [GPIO_CLIENT_REGISTRATION_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_gpio_client_registration_packet) structure that contains a *CLIENT_DisconnectIoPins* function pointer.

#### Examples

To define a *CLIENT_DisconnectIoPins* callback function, you must first provide a function declaration that identifies the type of callback function you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *CLIENT_DisconnectIoPins* callback function that is named `MyEvtGpioDisconnectIoPins`, use the GPIO_CLIENT_DISCONNECT_IO_PINS function type, as shown in this code example:

```
GPIO_CLIENT_DISCONNECT_IO_PINS MyEvtGpioDisconnectIoPins;
```

Then, implement your callback function as follows:

```
_Use_decl_annotations_
NTSTATUS
  MyEvtGpioDisconnectIoPins(
    PVOID Context,
    PGPIO_DISCONNECT_IO_PINS_PARAMETERS DisconnectParameters
    )
{ ... }
```

The GPIO_CLIENT_DISCONNECT_IO_PINS function type is defined in the Gpioclx.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the GPIO_CLIENT_DISCONNECT_IO_PINS function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for KMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-kmdf-drivers). For more information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[CLIENT_ConnectIoPins](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_connect_io_pins)

[GPIO_CLIENT_REGISTRATION_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_gpio_client_registration_packet)

[GPIO_CLX_RegisterClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nf-gpioclx-gpio_clx_registerclient)

[GPIO_DISCONNECT_IO_PINS_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_gpio_disconnect_io_pins_parameters)