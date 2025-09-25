# WdfWmiInstanceGetProvider function

## Description

[Applies to KMDF only]

The **WdfWmiInstanceGetProvider** method returns a handle to the WMI provider object that is the parent object of a specified WMI instance object.

## Parameters

### `WmiInstance` [in]

A handle to a WMI instance object that the driver obtained from a previous call to [WdfWmiInstanceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiinstancecreate).

## Return value

**WdfWmiInstanceGetProvider** returns a handle to a WMI provider object.

A bug check occurs if the driver supplies an invalid object handle.

## See also

[WdfWmiInstanceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiinstancecreate)