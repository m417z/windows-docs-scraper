# WdfWmiInstanceGetDevice function

## Description

[Applies to KMDF only]

The **WdfWmiInstanceGetDevice** method returns a handle to the framework device object that is associated with a specified WMI instance object.

## Parameters

### `WmiInstance` [in]

A handle to a WMI instance object that the driver obtained from a previous call to [WdfWmiInstanceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiinstancecreate).

## Return value

**WdfWmiInstanceGetDevice** returns a handle to a framework device object.

A bug check occurs if the driver supplies an invalid object handle.

## See also

[WdfWmiInstanceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiinstancecreate)