# WdfDeviceUnmapIoSpace function

## Description

[Applies to UMDF only]

The **WdfDeviceUnmapIoSpace** function unmaps a specified range of physical addresses previously mapped by the [WdfDeviceMapIoSpace](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicemapiospace) function.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `PseudoBaseAddress` [in]

The address of a location that receives a pointer to the pseudo base address.

### `NumberOfBytes` [in]

Specifies a value greater than zero, indicating the number of bytes to be mapped.

## Remarks

This function is the UMDF version 2 equivalent of [IWDFDevice3::UnmapIoSpace](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice3-unmapiospace).

If a driver calls [WdfDeviceMapIoSpace](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicemapiospace) in [EvtDevicePrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware) callback, it must call **WdfDeviceUnmapIoSpace** in its [EvtDeviceReleaseHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_release_hardware) callback.

## See also

[IWDFDevice3::UnmapIoSpace](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice3-unmapiospace)

[WdfDeviceMapIoSpace](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicemapiospace)