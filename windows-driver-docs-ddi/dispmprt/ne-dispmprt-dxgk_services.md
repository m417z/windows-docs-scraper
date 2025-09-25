# DXGK_SERVICES enumeration

## Description

A **DXGK_SERVICES** enumeration value indicates the type of display port driver-implemented service interface that [**DxgkCbQueryServices**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_query_services) should return.

## Constants

### `DxgkServicesAgp`

Indicates the [Accelerated Graphics Port (AGP) interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_agp_interface).

### `DxgkServicesDebugReport`

Indicates the [Debug Report interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_debug_report_interface).

### `DxgkServicesTimedOperation`

Indicates the [Timed Operation interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_timed_operation_interface).

### `DxgkServicesSPB`

Indicates the [Simple Peripheral Bus (SPB) interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_spb_interface). Available starting with Windows 8.

### `DxgkServicesBDD`

Reserved for system use. Do not use in your driver. Supported starting with Windows 8.

### `DxgkServicesFirmwareTable`

Indicates the [System Firmware Table interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_firmware_table_interface). Available starting with Windows 8.

### `DxgkServicesIDD`

Reserved for system use. Do not use in your driver. Available starting with Windows 8.

### `DxgkServicesFeature`

Indicates the [interface for querying whether a feature is enabled](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_feature_interface). Available starting with Windows 11, version 24H2 (WDDM 3.2).

## Remarks

In this context, an interface is a set of pointers to functions implemented by *Dxgkrnl*. A kernel-mode display minport driver (KMD) can call the function interfaces that aren't reserved for system use.

## See also

[**DXGK_AGP_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_agp_interface)

[**DXGK_DEBUG_REPORT_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_debug_report_interface)

[**DXGK_FIRMWARE_TABLE_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_firmware_table_interface)

[**DXGK_FEATURE_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_feature_interface)

[**DXGK_SPB_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_spb_interface)

[**DXGK_TIMED_OPERATION_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_timed_operation_interface)

[**DxgkCbQueryServices**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_query_services)