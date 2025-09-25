# WdfWmiInstanceDeregister function

## Description

[Applies to KMDF only]

The **WdfWmiInstanceDeregister** method deregisters a specified instance of a WMI data provider from the system's WMI service.

## Parameters

### `WmiInstance` [in]

A handle to a WMI instance object that the driver obtained from a previous call to [WdfWmiInstanceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiinstancecreate).

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

For more information about the **WdfWmiInstanceDeregister** method, see [Registering Provider Instances](https://learn.microsoft.com/windows-hardware/drivers/wdf/initializing-wmi-support-in-your-driver). For more information about WMI, see [Supporting WMI in Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-wmi-in-kmdf-drivers).

[WdfWmiInstanceRegister](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiinstanceregister) deregisters the provider instance synchronously (that is, before returning) if it is called at IRQL = PASSIVE_LEVEL and asynchronously if it is called at IRQL > PASSIVE_LEVEL.

#### Examples

The following code example deregisters a specified instance of a WMI data provider from the system's WMI service.

```cpp
WdfWmiInstanceDeregister(wmiInstance);
```

## See also

[WdfWmiInstanceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiinstancecreate)

[WdfWmiInstanceRegister](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiinstanceregister)