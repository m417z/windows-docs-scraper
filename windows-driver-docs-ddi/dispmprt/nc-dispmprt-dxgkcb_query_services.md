# DXGKCB_QUERY_SERVICES callback function

## Description

The **DxgkCbQueryServices** function returns an interface implemented by the display port driver.

## Parameters

### `DeviceHandle` [in]

A handle that represents a display adapter. The display miniport driver previously obtained this handle in the **DeviceHandle** member of the [**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface) structure that was passed to [**DxgkDdiStartDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device).

### `ServicesType` [in]

A constant from the [**DXGK_SERVICES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ne-dispmprt-dxgk_services) enumeration that specifies which interface is being requested.

### `Interface` [in, out]

A pointer to an [**INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_interface) structure that receives the requested interface.

## Return value

**DxgkCbQueryServices** returns STATUS_SUCCESS if it succeeds. Otherwise, it returns one of the error codes defined in *Ntstatus.h*.

## Remarks

An interface, in this context, is a set of functions implemented by the display port driver. The display port driver makes the functions of an interface available to other drivers by providing function pointers in response to **DxgkCbQueryServices**.

### Obtaining the AGP interface

To obtain an Accelerated Graphics Port (AGP) interface, do the following:

1. Allocate a [**DXGK_AGP_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_agp_interface) structure.

2. Set the **Size** member to sizeof(DXGK_AGP_INTERFACE).

3. Set the **Version** member. Version constants are defined in *Dispmprt.h* (for example, DXGK_AGP_INTERFACE_VERSION_1).

4. Call **DxgkCbQueryServices**; set **ServicesType** to **DxgkServicesAgp**, and set **Interface** to the address (cast as [PINTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_interface)) of your **DXGK_AGP_INTERFACE** structure.

5. On return from **DxgkCbQueryServices**, your **DXGK_AGP_INTERFACE** structure will contain pointers to the AGP interface functions; for example, [**AgpAllocatePool**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_agp_allocate_pool).

### Obtaining the Debug Report interface

To obtain a Debug Report interface, do the following:

1. Allocate a [**DXGK_DEBUG_REPORT_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_debug_report_interface) structure.

2. Set the **Size** member to sizeof(DXGK_DEBUG_REPORT_INTERFACE).

3. Set the **Version** member. Version constants are defined in *Dispmprt.h* (for example, DXGK_DEBUG_REPORT_INTERFACE_VERSION_1).

4. Call **DxgkCbQueryServices**; set **ServicesType** to **DxgkServicesDebugReport**, and set **Interface** to the address (cast as PINTERFACE) of your **DXGK_DEBUG_REPORT_INTERFACE** structure.

5. On return from **DxgkCbQueryServices**, your DXGK_DEBUG_REPORT_INTERFACE structure will contain pointers to the Debug Report interface functions; for example, [**DbgReportCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_debug_report_interface).

### Obtaining the Timed Operation interface

To obtain a Timed Operation interface, do the following:

1. Allocate a [**DXGK_TIMED_OPERATION_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_timed_operation_interface) structure.

2. Set the **Size** member to sizeof(DXGK_TIMED_OPERATION_INTERFACE).

3. Set the **Version** member. Version constants are defined in *Dispmprt.h* (for example, DXGK_TIMED_OPERATION_INTERFACE_VERSION_1).

4. Call **DxgkCbQueryServices**; set **ServicesType** to **DxgkServicesTimedOperation**, and set **Interface** to the address (cast as PINTERFACE) of your **DXGK_TIMED_OPERATION_INTERFACE** structure.

5. On return from **DxgkCbQueryServices**, your **DXGK_TIMED_OPERATION_INTERFACE** structure will contain pointers to the Timed Operation interface functions; for example, [**TimedOperationStart**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_timed_operation_interface).

### Obtaining the SPB and System Firmware Table interfaces

The [Simple Peripheral Bus (SPB)](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_spb_interface) and [System Firmware Table](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_firmware_table_interface) interfaces can be similarly obtained by following the above steps using the appropriate **ServicesType** and structure.

## See also

[**DXGK_AGP_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_agp_interface)

[**DxgkDdiStartDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device)

[**DXGK_DEBUG_REPORT_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_debug_report_interface)

[**DXGK_FIRMWARE_TABLE_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_firmware_table_interface)

[**DXGK_SERVICES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ne-dispmprt-dxgk_services)

[**DXGK_SPB_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_spb_interface)

[**DXGK_TIMED_OPERATION_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_timed_operation_interface)

[**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface)

[**INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_interface)