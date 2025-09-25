# _GPIO_CLIENT_CONTROLLER_SPECIFIC_FUNCTION_PARAMETERS structure

## Description

The **GPIO_CLIENT_CONTROLLER_SPECIFIC_FUNCTION_PARAMETERS** structure describes the input and output buffers for a controller-specific operation.

## Members

### `InputBuffer`

A pointer to an input buffer from which the general-purpose I/O (GPIO) controller driver reads the input parameters for the controller-specific operation. This member can be NULL if the operation does not require input parameters.

### `InputBufferLength`

The size, in bytes, of the input buffer pointed to by **InputBuffer**.

### `OutputBuffer`

A pointer to an output buffer to which the GPIO controller driver writes the results for the controller-specific operation. This member can be NULL if the operation does not require output parameters.

### `OutputBufferLength`

The size, in bytes, of the output buffer pointed to by **OutputBuffer**.

### `BytesWritten`

The number of bytes written to the output buffer. The GPIO controller driver sets the value of this member to indicate how much data was written to the output buffer. If no data was written to the output buffer, or if **OutputBuffer** = NULL, the driver should set **BytesWritten** = 0.

## Remarks

The *Parameters* parameter to the [CLIENT_ControllerSpecificFunction](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_controller_specific_function) function is a pointer to a **GPIO_CLIENT_CONTROLLER_SPECIFIC_FUNCTION_PARAMETERS** structure. This structure describes the input and output buffers from a custom I/O control request (IOCTL) for a hardware-specific operation that is implemented by the GPIO controller and supported by the GPIO controller driver.

The GPIO framework extension (GpioClx) fills in the first four members of the structure before the call to the *CLIENT_ControllerSpecificFunction* function. This function fills in the last member, **BytesWritten**.

## See also

[CLIENT_ControllerSpecificFunction](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_controller_specific_function)