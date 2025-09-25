# _CLIENT_CONTROLLER_QUERY_SET_INFORMATION_INPUT structure

## Description

The **CLIENT_CONTROLLER_QUERY_SET_INFORMATION_INPUT** structure contains a request for the hardware attributes of the general-purpose I/O (GPIO) controller.

## Members

### `RequestType`

The type of attribute information that is being requested. This member is set to a [CLIENT_CONTROLLER_QUERY_SET_REQUEST_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ne-gpioclx-_client_controller_query_set_request_type) enumeration value.

### `Size`

Specifies the size, in bytes, of the **CLIENT_CONTROLLER_QUERY_SET_INFORMATION_INPUT** structure.

### `Flags`

A set of flag bits that supply additional information about the type of attribute request indicated by the **RequestType** member. No flags are currently defined for the **Flags** member.

### `BankPowerInformation`

A structure that contains information about the GPIO bank whose power attributes are being requested.

### `BankPowerInformation.BankId`

The identifier for a bank of GPIO pins. If M is the number of banks in the GPIO controller, **BankId** is an integer in the range 0 to M–1\. The GPIO framework extension (GpioClx) previously obtained the number of banks in the controller from the [CLIENT_QueryControllerBasicInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_query_controller_basic_information) event callback function. For more information, see Remarks in [CLIENT_CONTROLLER_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_client_controller_basic_information).

### `BankInterruptBinding`

A structure that contains information about the interrupt resources that are assigned to the GPIO controller.

### `BankInterruptBinding.ResourcesTranslated`

A handle to a framework resource-list object that identifies the translated hardware resources that the Plug and Play manager has assigned to the device.

### `BankInterruptBinding.ResourcesRaw`

A handle to a framework resource-list object that identifies the raw hardware resources that the Plug and Play manager has assigned to the device.

### `BankInterruptBinding.TotalBanks`

The number of banks in the GPIO controller. This member indicates the expected length of the **BankInterruptBinding.ResourceMapping** array in the caller-allocated [CLIENT_CONTROLLER_QUERY_SET_INFORMATION_OUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_client_controller_query_set_information_output) structure, if the caller supplies a non-NULL pointer to this structure.

### `ControllerFunctionBankMapping`

A structure that contains information about an I/O control request (IOCTL).

### `ControllerFunctionBankMapping.InputBuffer`

A pointer to the input buffer for the IOCTL.

### `ControllerFunctionBankMapping.InputBufferSize`

The size, in bytes, of the input buffer for the IOCTL.

### `ControllerFunctionBankMapping.OutputBufferSize`

The size, in bytes, of the output buffer for the IOCTL.

### `ControllerFunctionBankMapping.TotalBanks`

The number of banks in the GPIO controller. This member indicates the expected length of the **ControllerFunctionBankMapping.Mapping** array in the caller-allocated [CLIENT_CONTROLLER_QUERY_SET_INFORMATION_OUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_client_controller_query_set_information_output) structure, if the caller supplies a non-NULL pointer to this structure.

## Remarks

The unnamed union contains input information for the various types of attribute requests. The **RequestType** member determines which member of this union is used. The following table shows the union member that corresponds to each valid **RequestType** value.

| RequestType value | Union member |
|--|--|
| QueryBankPowerInformation | BankPowerInformation |
| QueryBankInterruptBindingInformation | BankInterruptBinding |
| QueryControllerFunctionBankMappingInformation | ControllerFunctionBankMapping |

The *InputBuffer* parameter of the [CLIENT_QuerySetControllerInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_query_set_controller_information) function is a pointer to a **CLIENT_CONTROLLER_QUERY_SET_INFORMATION_INPUT** structure.

## See also

- [CLIENT_CONTROLLER_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_client_controller_basic_information)
- [CLIENT_CONTROLLER_QUERY_SET_INFORMATION_OUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_client_controller_query_set_information_output)
- [CLIENT_QueryControllerBasicInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_query_controller_basic_information)
- [CLIENT_QuerySetControllerInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_query_set_controller_information)