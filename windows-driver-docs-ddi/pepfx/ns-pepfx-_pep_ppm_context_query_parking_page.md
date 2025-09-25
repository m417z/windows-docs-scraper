# _PEP_PPM_CONTEXT_QUERY_PARKING_PAGE structure (pepfx.h)

## Description

The **PEP_PPM_CONTEXT_QUERY_PARKING_PAGE** structure describes the parking page for a processor.

## Members

### `PhysicalPageAddress`

The physical memory address of the parking page.

### `VirtualPageAddress`

The virtual memory address of the parking page.

## Remarks

The output buffer for a [PEP_PPM_POWER_CONTROL_QUERY_PARKING_PAGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_context_query_parking_page) power control request is a **PEP_PPM_CONTEXT_QUERY_PARKING_PAGE** structure.

## See also

[PEP_PPM_POWER_CONTROL_QUERY_PARKING_PAGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_context_query_parking_page)