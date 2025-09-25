# WDF_USB_CONTINUOUS_READER_CONFIG_INIT function

## Description

[Applies to KMDF and UMDF]

The **WDF_USB_CONTINUOUS_READER_CONFIG_INIT** function initializes a [WDF_USB_CONTINUOUS_READER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_continuous_reader_config) structure.

## Parameters

### `Config` [out]

A pointer to a [WDF_USB_CONTINUOUS_READER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_continuous_reader_config) structure.

### `EvtUsbTargetPipeReadComplete` [in]

A pointer to the driver's [EvtUsbTargetPipeReadComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nc-wdfusb-evt_wdf_usb_reader_completion_routine) callback function.

### `EvtUsbTargetPipeReadCompleteContext` [in]

An untyped pointer to driver-defined context information that the framework passes to the driver's [EvtUsbTargetPipeReadComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nc-wdfusb-evt_wdf_usb_reader_completion_routine) callback function.

### `TransferLength` [in]

The maximum length, in bytes, of data that can be received from the device.

## Remarks

The **WDF_USB_CONTINUOUS_READER_CONFIG_INIT** function zeros the specified [WDF_USB_CONTINUOUS_READER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_continuous_reader_config) structure and sets the structure's **Size** member. It also sets the structure's **EvtUsbTargetPipeReadComplete**, **EvtUsbTargetPipeReadCompleteContext**, and **TransferLength** members to the specified values.

 Note that **WDF_USB_CONTINUOUS_READER_CONFIG_INIT** does *not* set the structure's **EvtUsbTargetPipeReadersFailed** member.

 After calling **WDF_USB_CONTINUOUS_READER_CONFIG_INIT**, the driver can optionally add a **EvtUsbTargetPipeReadersFailed** pointer to the [WDF_USB_CONTINUOUS_READER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_continuous_reader_config) structure.

For a code example that uses **WDF_USB_CONTINUOUS_READER_CONFIG_INIT**, see [WdfUsbTargetPipeConfigContinuousReader](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetpipeconfigcontinuousreader).

## See also

[EvtUsbTargetPipeReadComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nc-wdfusb-evt_wdf_usb_reader_completion_routine)

[WDF_USB_CONTINUOUS_READER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_continuous_reader_config)