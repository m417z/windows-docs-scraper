# WdfDeviceWdmGetDeviceObject function

## Description

[Applies to KMDF only]

The **WdfDeviceWdmGetDeviceObject** method returns the Windows Driver Model (WDM) device object that is associated with a specified framework device object.

## Parameters

### `Device`

A handle to a framework device object.

## Return value

**WdfDeviceWdmGetDeviceObject** returns a pointer to a [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

The pointer that the **WdfDeviceWdmGetDeviceObject** method returns is valid until the framework device object is deleted. If the driver provides an [EvtCleanupCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_cleanup) function for the framework device object, the pointer is valid until the callback function returns.

#### Examples

The following code example creates a tracing message that contains pointers to the WDM device objects that represent a device's PDO and FDO.

```cpp
TraceEvents(
            TRACE_LEVEL_INFORMATION,
            AMCC_TRACE_INIT,
            "PDO 0x%p, FDO 0x%p",
            WdfDeviceWdmGetPhysicalDevice(device),
            WdfDeviceWdmGetDeviceObject(device)
            );
```

## See also

[WdfDeviceWdmGetPhysicalDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicewdmgetphysicaldevice)