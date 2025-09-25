# WdfDriverWdmGetDriverObject function

## Description

[Applies to KMDF only]

The **WdfDriverWdmGetDriverObject** method retrieves a pointer to the Windows Driver Model (WDM) driver object that is associated with a specified framework driver object.

## Parameters

### `Driver` [in]

A handle to the driver's framework driver object that the driver obtained from a previous call to [WdfDriverCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfdrivercreate) or [WdfGetDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfgetdriver).

## Return value

**WdfDriverWdmGetDriverObject** returns a pointer to a [DRIVER_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_driver_object) structure. A system bug check occurs if the *Driver* handle is invalid.

## Remarks

The pointer that the **WdfDriverWdmGetDriverObject** method returns is valid until the framework driver object is deleted. If the driver provides an [EvtCleanupCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_cleanup) function for the framework driver object, the pointer is valid until the callback function returns.

#### Examples

The following code example obtains a pointer to the WDM driver object that is associated with a specified framework driver object.

```cpp
PDRIVER_OBJECT  pDrvObj;

pDrvObj = WdfDriverWdmGetDriverObject(Driver);
```

## See also

[DRIVER_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_driver_object)

[WdfDriverCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfdrivercreate)

[WdfGetDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfgetdriver)