# GPIO_CLIENT_PRE_PROCESS_CONTROLLER_INTERRUPT callback function

## Description

The *CLIENT_PreProcessControllerInterrupt* event callback function performs any pre-processing of a general-purpose I/O (GPIO) interrupt that must be done immediately if the ISR is scheduled to run at a later time.

## Parameters

### `Context` [in]

A pointer to the GPIO controller driver's [device context](https://learn.microsoft.com/windows-hardware/drivers/gpio/gpio-device-contexts).

### `BankId` [in]

The bank that contains the interrupting GPIO pin. If N is the number of banks in the GPIO controller, **BankId** is an integer in the range 0 to N–1. The GPIO framework extension previously obtained the number of banks in the controller from the [CLIENT_QueryControllerBasicInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_query_controller_basic_information) event callback function. For more information, see Remarks in [CLIENT_CONTROLLER_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_client_controller_basic_information).

### `EnabledMask`

## Return value

The *CLIENT_PreProcessControllerInterrupt* function returns STATUS_SUCCESS if the call is successful. Otherwise, it returns an appropriate error code.

## Remarks

This callback function is optional. A GPIO controller driver implements this function only if it performs most of its interrupt handling at PASSIVE_LEVEL, but must do some initial processing of an interrupt at DIRQL.

Typically, a GPIO controller driver can access a memory-mapped GPIO controller at DIRQL, but can access a serially connected GPIO controller only at PASSIVE_LEVEL. However, some serially connected GPIO controllers might lose interrupt status data if they delay capture of the interrupt status bits until the IRQL drops to PASSIVE_LEVEL. When the IRQL later drops to PASSIVE_LEVEL, the GPIO framework extension (GpioClx) can call the driver's [CLIENT_QueryActiveInterrupts](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_query_active_interrupts) callback function to retrieve the register contents.

The GPIO controller driver indicates whether it must handle interrupts at PASSIVE_LEVEL in the device information that it passes to GpioClx during the [CLIENT_QueryControllerBasicInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_query_controller_basic_information) callback. If the GPIO controller is memory-mapped, so that the driver can access the controller's registers at DIRQL, the driver sets the **MemoryMappedController** flag bit in the **Flags** member of the [CLIENT_CONTROLLER_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_client_controller_basic_information) structure that the driver passes to GpioClx. Otherwise, the driver sets **MemoryMappedController** = 0 to indicate that the driver must handle interrupts at PASSIVE_LEVEL. For more information, see [Passive-Level ISRs](https://learn.microsoft.com/windows-hardware/drivers/gpio/passive-level-isrs).

To register your driver's *CLIENT_PreProcessControllerInterrupt* callback function, call the [GPIO_CLX_RegisterClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nf-gpioclx-gpio_clx_registerclient) method. This method accepts, as an input parameter, a pointer to a [GPIO_CLIENT_REGISTRATION_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_gpio_client_registration_packet) structure that contains a *CLIENT_PreProcessControllerInterrupt* function pointer.

#### Examples

To define a *CLIENT_PreProcessControllerInterrupt* callback function, you must first provide a function declaration that identifies the type of callback function you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *CLIENT_PreProcessControllerInterrupt* callback function that is named `MyEvtGpioPreProcessInterrupt`, use the GPIO_CLIENT_PRE_PROCESS_CONTROLLER_INTERRUPT function type, as shown in this code example:

```
GPIO_CLIENT_PRE_PROCESS_CONTROLLER_INTERRUPT MyEvtGpioPreProcessInterrupt;
```

Then, implement your callback function as follows:

```
_Use_decl_annotations_
NTSTATUS
  MyEvtGpioPreProcessInterrupt(
    PVOID Context
    )
{ ... }
```

The GPIO_CLIENT_PRE_PROCESS_CONTROLLER_INTERRUPT function type is defined in the Gpioclx.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the GPIO_CLIENT_PRE_PROCESS_CONTROLLER_INTERRUPT function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for KMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-kmdf-drivers). For more information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[GPIO_CLIENT_REGISTRATION_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_gpio_client_registration_packet)

[GPIO_CLX_RegisterClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nf-gpioclx-gpio_clx_registerclient)