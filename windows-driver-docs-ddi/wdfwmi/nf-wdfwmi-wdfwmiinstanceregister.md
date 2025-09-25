# WdfWmiInstanceRegister function

## Description

[Applies to KMDF only]

The **WdfWmiInstanceRegister** method registers a specified instance of a WMI data provider with the system's WMI service.

## Parameters

### `WmiInstance` [in]

A handle to a WMI instance object that the driver obtained from a previous call to [WdfWmiInstanceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiinstancecreate).

## Return value

**WdfWmiInstanceRegister** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_DEVICE_REQUEST** | The specified WMI instance has already been registered. |

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

Provider instances are not available to WMI clients until they have been registered. Your driver must either call **WdfWmiInstanceRegister** or set the **Register** member of the instance's [WDF_WMI_INSTANCE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/ns-wdfwmi-_wdf_wmi_instance_config) structure to **TRUE**.

For more information about the **WdfWmiInstanceRegister** method, see [Registering Provider Instances](https://learn.microsoft.com/windows-hardware/drivers/wdf/initializing-wmi-support-in-your-driver). For more information about WMI, see [Supporting WMI in Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-wmi-in-kmdf-drivers).

**WdfWmiInstanceRegister** registers the provider instance synchronously (that is, before returning) if it is called at IRQL = PASSIVE_LEVEL and asynchronously if it is called at IRQL > PASSIVE_LEVEL.

#### Examples

The following code example registers a specified instance of a WMI data provider with the system's WMI service.

```cpp
NTSTATUS  status;

status = WdfWmiInstanceRegister(wmiInstance);
```

## See also

[WDF_WMI_INSTANCE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/ns-wdfwmi-_wdf_wmi_instance_config)

[WdfWmiInstanceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiinstancecreate)

[WdfWmiInstanceDeregister](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiinstancederegister)