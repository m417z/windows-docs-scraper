# _WDF_USB_CONTINUOUS_READER_CONFIG structure

## Description

[Applies to KMDF and UMDF]

The **WDF_USB_CONTINUOUS_READER_CONFIG** structure contains information that the framework uses to configure a continuous reader for a USB pipe.

## Members

### `Size`

The size, in bytes, of this structure.

### `TransferLength`

The maximum length, in bytes, of data that can be received from the device.

### `HeaderLength`

An offset, in bytes, into the buffer that receives data from the device. The framework will store data from the device in a read buffer, beginning at the offset value. In other words, this space precedes the **TransferLength**-sized space in which the framework stores data from the device.

### `TrailerLength`

The length, in bytes, of a trailing buffer space. This space follows the **TransferLength**-sized space in which the framework stores data from the device.

### `NumPendingReads`

The number of read requests that the framework will queue to receive data from the I/O target. If this value is zero, the framework uses a default number of read requests. If the specified value is greater than the permitted maximum, the framework uses the permitted maximum. For more information about the **NumPendingReads** member, see the following Remarks section.

### `BufferAttributes`

A [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that specifies object attributes for the framework memory object that the framework creates for each read request. This member can be **NULL**. You cannot set the **ParentObject** member of the WDF_OBJECT_ATTRIBUTES structure.

### `EvtUsbTargetPipeReadComplete`

A pointer to the driver's [EvtUsbTargetPipeReadComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nc-wdfusb-evt_wdf_usb_reader_completion_routine) callback function.

### `EvtUsbTargetPipeReadCompleteContext`

An untyped pointer to driver-defined context information that the framework passes to the driver's [EvtUsbTargetPipeReadComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nc-wdfusb-evt_wdf_usb_reader_completion_routine) callback function.

### `EvtUsbTargetPipeReadersFailed`

A pointer to the driver's [EvtUsbTargetPipeReadersFailed](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nc-wdfusb-evt_wdf_usb_readers_failed) callback function. This pointer is optional and can be **NULL**. For more information about this parameter, see the Remarks section of [WdfUsbTargetPipeConfigContinuousReader](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetpipeconfigcontinuousreader).

## Remarks

The **WDF_USB_CONTINUOUS_READER_CONFIG** structure is used as input to the [WdfUsbTargetPipeConfigContinuousReader](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetpipeconfigcontinuousreader) method.

To initialize a WDF_USB_CONTINUOUS_READER_CONFIG structure, the driver must call [WDF_USB_CONTINUOUS_READER_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_continuous_reader_config_init).

Use the following guidelines when choosing a value for the **NumPendingReads** member:

* Set **NumPendingReads** to 0 if you want your driver to use the framework's default value.

  The default value is greater than 1 and has been determined to provide reasonably good performance for many devices on many processor configurations.
* Set **NumPendingReads** to 1 if it is important that your driver receive data buffers in the exact order that the device delivers the data.
* Set **NumPendingReads** to a number that meets the performance requirements for your device, based on thorough performance measurements.

  First, test your device with the default value (0) for **NumPendingReads**. Your tests should include various hardware configurations, including different types and numbers of processors and different USB host controllers and USB configurations. You can then experiment with higher values, using the same tests. A driver that might require a higher value is one for a device that has a high interrupt rate, where data can be lost if interrupts are not serviced rapidly.

A **NumPendingReads** value that is too large can slow down a system's performance. You should use the lowest value that meets your performance requirements. Typically, values that are higher than 3 or 4 do not improve data throughput. But higher values might reduce latency, or the chance of missing data, on a high-frequency pipe.

## See also

[EvtUsbTargetPipeReadComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nc-wdfusb-evt_wdf_usb_reader_completion_routine)

[EvtUsbTargetPipeReadersFailed](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nc-wdfusb-evt_wdf_usb_readers_failed)

[WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes)

[WDF_USB_CONTINUOUS_READER_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_continuous_reader_config_init)

[WdfUsbTargetPipeConfigContinuousReader](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetpipeconfigcontinuousreader)