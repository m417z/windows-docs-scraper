# GPIO_CLIENT_QUERY_SET_CONTROLLER_INFORMATION callback function

## Description

The *CLIENT_QuerySetControllerInformation* event callback function queries the general-purpose I/O (GPIO) controller driver for the specified set of attributes of the GPIO controller.

## Parameters

### `Context` [in]

A pointer to the GPIO controller driver's [device context](https://learn.microsoft.com/windows-hardware/drivers/gpio/gpio-device-contexts).

### `InputBuffer` [in]

A pointer to a [CLIENT_CONTROLLER_QUERY_SET_INFORMATION_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_client_controller_query_set_information_input) structure that describes the type of attributes that the caller is requesting.

### `OutputBuffer` [out, optional]

An optional pointer to a [CLIENT_CONTROLLER_QUERY_SET_INFORMATION_OUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_client_controller_query_set_information_output) structure into which the function writes the values of the requested attributes.

## Return value

The *CLIENT_QuerySetControllerInformation* function returns **STATUS_SUCCESS** if the call is successful. Possible return values include the following error code.

| Return code | Description |
| --- | --- |
| **STATUS_NOT_SUPPORTED** | The function does not support the type of attributes that are being requested. |

## Remarks

The **RequestType** member of the **CLIENT_CONTROLLER_QUERY_SET_INFORMATION_INPUT** structure pointed to by *InputBuffer* specifies the type of attributes that are being requested. For a list of the types of attributes that can be requested, see [CLIENT_CONTROLLER_QUERY_SET_REQUEST_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ne-gpioclx-_client_controller_query_set_request_type).

Implementing a *CLIENT_QuerySetControllerInformation* function is optional. If a GPIO controller driver implements a *CLIENT_QuerySetControllerInformation* function, this function might support some types of attribute requests, but not support others. If the caller requests an attribute type that the function does not support, the function returns **STATUS_NOT_SUPPORTED**.

#### Examples

To define a *CLIENT_QuerySetControllerInformation* callback function, you must first provide a function declaration that identifies the type of callback function you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *CLIENT_QuerySetControllerInformation* callback function that is named `MyEvtGpioQuerySetControllerInformation`, use the GPIO_CLIENT_QUERY_SET_CONTROLLER_INFORMATION function type, as shown in this code example:

```
GPIO_CLIENT_QUERY_SET_CONTROLLER_INFORMATION MyEvtGpioQuerySetControllerInformation;
```

Then, implement your callback function as follows:

```
_Use_decl_annotations_
NTSTATUS
  MyEvtGpioQuerySetControllerInformation(
    PVOID Context,
    PCLIENT_CONTROLLER_QUERY_SET_INFORMATION_INPUT InputBuffer,
    PCLIENT_CONTROLLER_QUERY_SET_INFORMATION_OUTPUT OutputBuffer
    )
{ ... }
```

The GPIO_CLIENT_QUERY_SET_CONTROLLER_INFORMATION function type is defined in the Gpioclx.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the GPIO_CLIENT_QUERY_SET_CONTROLLER_INFORMATION function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for KMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-kmdf-drivers). For more information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[CLIENT_CONTROLLER_QUERY_SET_INFORMATION_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_client_controller_query_set_information_input)

[CLIENT_CONTROLLER_QUERY_SET_INFORMATION_OUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_client_controller_query_set_information_output)

[CLIENT_CONTROLLER_QUERY_SET_REQUEST_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ne-gpioclx-_client_controller_query_set_request_type)