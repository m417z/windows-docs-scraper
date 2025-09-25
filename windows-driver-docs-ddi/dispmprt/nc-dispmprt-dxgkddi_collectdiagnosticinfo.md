# DXGKDDI_COLLECTDIAGNOSTICINFO callback function

## Description

The DxgkDdiCollectDiagnosticInfo callback routine collects the private driver information for reasons that are specified by [DXGK_DIAGNOSTICINFO_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ne-dispmprt-dxgk_diagnosticinfo_type).

In Windows 10, version 1903, the driver will be called to collect private information if the function calls to [DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) or [DxgkDdiStartDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device) failed.

## Parameters

### `PhysicalDeviceObject` [in]

A pointer to a physical device object (PDO) that identifies a display adapter.

### `pCollectDiagnosticInfo` [in, out]

A pointer to a [DXGKARG_COLLECTDIAGNOSTICINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgkarg_collectdiagnosticinfo) structure which describes information collected by the driver.

## Return value

Returns STATUS_SUCCESS if the private data information was successfully collected. Otherwise, it returns an error code such as one of the following.

| Error Code | Meaning |
| ---------- | ------- |
| STATUS_DRIVER_INTERNAL_ERROR | A generic SW error happened inside the driver. |
| STATUS_ACCESS_DENIED | The hardware is currently being used by other threads and this DDI can't get access to it. |
| STATUS_DEVICE_HARDWARE_ERROR | A generic HW error happened. |
| STATUS_DEVICE_POWERED_OFF | The device is powered off. |

## Prototype

```
//Declaration

DXGKDDI_COLLECTDIAGNOSTICINFO DxgkddiCollectdiagnosticinfo;

// Definition

NTSTATUS DxgkddiCollectdiagnosticinfo
(
	IN_CONST_PDEVICE_OBJECT PhysicalDeviceObject
	INOUT_PDXGKARG_COLLECTDIAGNOSTICINFO pCollectDiagnosticInfo
)
{...}

```

## Remarks

This function is called at PASSIVE level, at any time in between the calls to [**DxgkDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) and [**DxgkDdiStartDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device), and should support [synchronization zero level](https://learn.microsoft.com/windows-hardware/drivers/display/threading-and-synchronization-zero-level). The collected data shouldn't contain any private user information.

WDDM 2.7 and later drivers are required to support the **DXGK_DI_BLACKSCREEN** [**DXGK_DIAGNOSTICINFO_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ne-dispmprt-dxgk_diagnosticinfo_type) enum type for black screen black box data collection.

For black screen scenarios, the OS will first collect the white box data from the driver by calling [**DxgkDdiGetDisplayStateNonIntrusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_getdisplaystatenonintrusive) and [**DxgkDdiGetDisplayStateIntrusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_getdisplaystateintrusive) before calling this DDI to collect black box information.

It is recommended to use **pCollectDiagnosticInfo->BucketingString** to bucketize the black box data where possible. If the size of the **BufferSizeIn** input buffer is not sufficient for all the black box data then drivers should make their own tradeoffs in leaving out the data that is least important in most black screen root cause analysis.

## See also

[**DXGKARG_COLLECTDIAGNOSTICINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgkarg_collectdiagnosticinfo)

[**DxgkDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device)

[**DxgkDdiStartDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device)