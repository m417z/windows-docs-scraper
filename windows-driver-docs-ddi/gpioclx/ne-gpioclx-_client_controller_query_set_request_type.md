# _CLIENT_CONTROLLER_QUERY_SET_REQUEST_TYPE enumeration

## Description

The **CLIENT_CONTROLLER_QUERY_SET_REQUEST_TYPE** enumeration type indicates what type of attribute information the GPIO framework extension (GpioClx) is requesting from the GPIO controller driver.

## Constants

### `QueryBankPowerInformation`

Power attributes. For this attribute type, the **BankPowerInformation** member of the [CLIENT_CONTROLLER_QUERY_SET_INFORMATION_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_client_controller_query_set_information_input) structure specifies a GPIO bank, and the **BankPowerInformation** member of the [CLIENT_CONTROLLER_QUERY_SET_INFORMATION_OUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_client_controller_query_set_information_output) structure contains the power attributes of the specified bank.

### `QueryBankInterruptBindingInformation`

Interrupt-binding attributes. For this attribute type, the **BankInterruptBinding** member of the **CLIENT_CONTROLLER_QUERY_SET_INFORMATION_INPUT** structure contains the raw and translated hardware resources assigned to the GPIO controller, and the **BankInterruptBinding** member of the **CLIENT_CONTROLLER_QUERY_SET_INFORMATION_OUTPUT** structure describes the binding of interrupt resources to GPIO banks.

### `QueryControllerFunctionBankMappingInformation`

Function-mapping attributes. For this attribute type, the **ControllerFunctionBankMapping** member of the **CLIENT_CONTROLLER_QUERY_SET_INFORMATION_INPUT** structure specifies an I/O control request (IOCTL), and the **ControllerFunctionBankMapping** member of the **CLIENT_CONTROLLER_QUERY_SET_INFORMATION_OUTPUT** structure indicates which GPIO banks must be in the F0 (fully on) power state to handle the specified IOCTL.

### `QuerySetRequestMaximumType`

Reserved for use by the operating system.

## Remarks

The **RequestType** member of the **CLIENT_CONTROLLER_QUERY_SET_INFORMATION_INPUT** structure is a value of type **CLIENT_CONTROLLER_QUERY_SET_REQUEST_TYPE**. GpioClx sets this member to a **CLIENT_CONTROLLER_QUERY_SET_REQUEST_TYPE** enumeration constant to indicate what type of attribute information is requested. The [CLIENT_QuerySetControllerInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_query_set_controller_information) callback function takes a pointer to a **CLIENT_CONTROLLER_QUERY_SET_INFORMATION_INPUT** structure as an input parameter, and optionally takes a pointer to a **CLIENT_CONTROLLER_QUERY_SET_INFORMATION_OUTPUT** structure as an output parameter.

## See also

[CLIENT_CONTROLLER_QUERY_SET_INFORMATION_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_client_controller_query_set_information_input)

[CLIENT_CONTROLLER_QUERY_SET_INFORMATION_OUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_client_controller_query_set_information_output)

[CLIENT_QuerySetControllerInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_query_set_controller_information)