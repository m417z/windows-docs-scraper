# WdfDeviceWdmGetAttachedDevice function

## Description

[Applies to KMDF only]

The **WdfDeviceWdmGetAttachedDevice** method returns the next-lower WDM device object in the [device stack](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdm-concepts-for-kmdf-drivers).

## Parameters

### `Device` [in]

A handle to a framework device object.

## Return value

**WdfDeviceWdmGetAttachedDevice** returns a pointer to a WDM [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure. If the specified object handle represents a physical device object (PDO), the method returns **NULL**.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

The pointer that the **WdfDeviceWdmGetAttachedDevice** method returns is valid until the framework device object is deleted. If the driver provides an [EvtCleanupCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_cleanup) function for the framework device object, the pointer is valid until the callback function returns.

#### Examples

The following code example creates a tracing message that contains pointers to the WDM device objects that represent a device's PDO, FDO, and next-lower device.

```cpp
TraceEvents(
            TRACE_LEVEL_INFORMATION,
            DBG_PNP,
            "PDO(0x%p) FDO(0x%p), Lower(0x%p)\n",
            WdfDeviceWdmGetPhysicalDevice(device),
            WdfDeviceWdmGetDeviceObject(device),
            WdfDeviceWdmGetAttachedDevice(device)
            );
```

## See also

[WdfDeviceWdmGetDeviceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicewdmgetdeviceobject)

[WdfDeviceWdmGetPhysicalDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicewdmgetphysicaldevice)