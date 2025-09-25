# DXGKDDI_EXCHANGEPRESTARTINFO callback function

## Description

Allows very simple data to be exchanged between the OS and driver which may be required prior to DxgkDdiStartDevice device being called and therefore cannot be queried through normal caps or adapter info DDIs.

## Parameters

### `hAdapter` [in]

Identifies the adapter.

### `pPreStartInfo` [in]

Pointer to a [DXGK_PRE_START_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_pre_start_info) structure, which contains both fields for the OS to pass info and fields for the driver to return info. Initially, only *SupportPreserveBootDisplay* is defined.

[out] SupportPreserveBootDisplay

The driver and hardware support the requirements that allow the boot frame buffer to be used and displayed throughout the hardware initialization, performed during [DxgkDdiStartDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device).

## Return value

If this routine succeeds and returns the requested change, it returns STATUS_SUCCESS.

## Remarks

This DDI will be called after [DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) and before [DxgkDdiStartDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device) so that the driver does not have access to its own hardware resources. However, it can use the *PhysicalDeviceObject* passed to the driver in **DxgkDdiAddDevice** to call [IoGetDeviceProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdeviceproperty). For example, it can find the hardware id in order to decide what to return in the output fields of the DXGK_PRE_START_INFO structure.

This function is always called at PASSIVE level so the supporting code should be made pageable where possible.