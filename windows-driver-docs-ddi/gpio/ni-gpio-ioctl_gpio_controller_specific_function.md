# IOCTL_GPIO_CONTROLLER_SPECIFIC_FUNCTION IOCTL

## Description

The **IOCTL_GPIO_CONTROLLER_SPECIFIC_FUNCTION** I/O control code enables a client of the general-purpose I/O (GPIO) controller to request a controller-specific device-control operation. Typically, the clients of a GPIO controller are drivers for peripheral devices that connect to GPIO pins.

## Parameters

### Major code

### Input buffer

The input buffer requirements for this I/O control code are defined by the developer of the GPIO controller driver. For more information about input buffers for METHOD_BUFFERED IRPs, see [Buffer Descriptions for I/O Control Codes](https://learn.microsoft.com/windows-hardware/drivers/kernel/buffer-descriptions-for-i-o-control-codes).

### Input buffer length

### Output buffer

The output buffer requirements for this I/O control code are defined by the developer of the GPIO controller driver. For more information about output buffers for METHOD_BUFFERED IRPs, see [Buffer Descriptions for I/O Control Codes](https://learn.microsoft.com/windows-hardware/drivers/kernel/buffer-descriptions-for-i-o-control-codes).

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

If the operation is successful, the GPIO controller driver sets the **Status** member to STATUS_SUCCESS, and sets the **Information** member to the total number of bytes written to the output buffer. If an operation does not produce output data or the output data pointer is NULL, the **Information** member is set to zero.

If either the input buffer is not large enough to contain the input parameters or the output buffer is not large enough to contain the output parameters for the controller-specific operation, the **Status** member is set to STATUS_BUFFER_TOO_SMALL.

If this request fails, the **Status** member is set to an error code, and the **Information** member is set to zero.

If the GPIO controller driver does not any support controller-specific operations, the **Status** member is set to STATUS_NOT_IMPLEMENTED. If the GPIO controller driver supports controller-specific operations, but does not recognize the contents of the input buffer as valid, the **Status** member is set to STATUS_NOT_SUPPORTED.

## Remarks

Typical GPIO controllers do not support **IOCTL_GPIO_CONTROLLER_SPECIFIC_FUNCTION** requests. However, a controller driver developer has the option of defining one or more controller-specific operations to address the special requirements or capabilities of a GPIO controller on a particular hardware platform.

Only a peripheral device driver that is aware of the controller-specific operations supported by a particular type of GPIO controller hardware can use **IOCTL_GPIO_CONTROLLER_SPECIFIC_FUNCTION** requests to perform these operations. A peripheral device driver that uses these requests to perform controller-specific operations on one hardware platform risks the loss of compatibility with other platforms that do not support these operations.

The meaning of the **IOCTL_GPIO_CONTROLLER_SPECIFIC_FUNCTION** control code is defined by the developer of the GPIO controller driver. Typically, the controller driver uses this control code to enable peripheral device drivers to perform hardware-specific operations on the GPIO pins to which their devices are connected.

For example, the input buffer to the **IOCTL_GPIO_CONTROLLER_SPECIFIC_FUNCTION** request might contain a controller-defined command code and some number of input parameters. The GPIO controller driver may or may not write data to the output buffer, depending on the command code.

The peripheral device driver sends this I/O control request to the file object for the target GPIO device. The file object is a [FILE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object) structure that represents an open connection to a set of pins on the GPIO controller. Kernel-mode driver framework (KMDF) drivers use a WDFIOTARGET handle to refer to this file object.

## See also

[FILE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object)