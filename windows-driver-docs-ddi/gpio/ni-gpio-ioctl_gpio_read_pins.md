# IOCTL_GPIO_READ_PINS IOCTL

## Description

The **IOCTL_GPIO_READ_PINS** I/O control code enables a client of the general-purpose I/O (GPIO) controller to read from a set of GPIO pins that are configured as inputs. Typically, the clients of a GPIO controller are drivers for peripheral devices that connect to GPIO pins.

## Parameters

### Major code

### Input buffer

No input buffer.

### Input buffer length

None.

### Output buffer

The output buffer.

### Output buffer length

The output buffer should be large enough to contain readings from all of the GPIO pins that are part of the target connection to which the client sends the request. For example, if the GPIO controller hardware implements 64 GPIO pins, and the client opens a connection to three of these GPIO pins, a one-byte buffer is sufficiently large to contain the three 1-bit values that are read from the three pins in the connection.

### Input/output buffer

### Input/output buffer length

### Status block

If the operation is successful, the GPIO controller driver sets the **Status** member to STATUS_SUCCESS, and sets the **Information** member to the total number of bytes transferred during the requested operation. If the operation transfers N bits, the number of bytes transferred is (N + 7) / 8. (That is, 7 is added to N to round up to the next byte boundary before the integer division by 8.)

If this request fails, the **Status** member is set to an error code and no data is read from the GPIO pins. The requested operation might fail for various reasons, which can include invalid client input, low resources, and device malfunction.

If the output buffer is not large enough to contain the data that is read from all of the GPIO pins in the target connection, the **Status** member is set to STATUS_BUFFER_TOO_SMALL. If the GPIO pins in the target connection are configured as outputs, the **Status** member is set to STATUS_GPIO_OPERATION_DENIED.

## Remarks

This request reads all of the GPIO pins that are part of the target connection to which the client sends the request. For example, if the connection has three pins, the 1-bit values that are read from these pins are saved in bits 0, 1, and 2 in the output buffer. The three pins in this example connection might map to GPIO pins 7, 8, and 23 in the GPIO controller hardware. If so, GPIO pin 7 is saved in bit 0 (the least significant bit) of the buffer, GPIO pin 8 is saved in bit 1 of the buffer, and GPIO pin 23 is saved in bit 2 of the buffer.

When the client opens a connection to a target GPIO device, all of the GPIO pins in this connection are configured either as inputs or as outputs. An **IOCTL_GPIO_READ_PINS** request can succeed only if the target pins are inputs.

 The client sends this I/O control request to the file object for the target device. The file object is a [FILE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object) structure that represents a logical connection to the target. [Kernel-mode driver framework](https://learn.microsoft.com/previous-versions/windows/hardware/download/dn550976(v=vs.85)) (KMDF) drivers call the [WdfIoTargetCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetcreate) method to open this connection. [User-mode driver framework](https://learn.microsoft.com/windows-hardware/drivers/wdf/overview-of-the-umdf) (UMDF) drivers call the [IWDFRemoteTarget::OpenFileByName](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfremotetarget-openfilebyname) method to open the connection.

For code examples that show how to use the **IOCTL_GPIO_READ_PINS** request to read a set of GPIO I/O pins, see the following topics:

[Connecting a KMDF Driver to GPIO I/O Pins](https://learn.microsoft.com/windows-hardware/drivers/gpio/connecting-a-kmdf-driver-to-gpio-i-o-pins)

## See also

[FILE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object)

[IWDFRemoteTarget::OpenFileByName](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfremotetarget-openfilebyname)

[WdfIoTargetCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetcreate)