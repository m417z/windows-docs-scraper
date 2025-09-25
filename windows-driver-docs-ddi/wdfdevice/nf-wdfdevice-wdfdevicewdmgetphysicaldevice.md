# WdfDeviceWdmGetPhysicalDevice function

## Description

[Applies to KMDF only]

The **WdfDeviceWdmGetPhysicalDevice** method retrieves the physical device's WDM PDO from the device stack.

## Parameters

### `Device` [in]

A handle to a framework device object.

## Return value

**WdfDeviceWdmGetPhysicalDevice** returns a pointer to a [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure.

A bug check occurs if the driver supplies an invalid object handle.

**WdfDeviceWdmGetPhysicalDevice** returns **NULL** if the caller supplies a control device object.

## Remarks

The pointer that the **WdfDeviceWdmGetPhysicalDevice** method returns is valid until the framework device object is deleted. If the driver provides an [EvtCleanupCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_cleanup) function for the framework device object, the pointer is valid until the callback function returns.

#### Examples

For a code example that uses **WdfDeviceWdmGetPhysicalDevice**, see [WdfDeviceWdmGetAttachedDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicewdmgetattacheddevice).