## Description

The **DdVideoPortDestroy** callback function notifies the driver that DirectDraw has destroyed the specified VPE object.

## Parameters

### `unnamedParam1`

Points to a [DD_DESTROYVPORTDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_destroyvportdata) structure that contains the information required for the driver to clean up.

## Return value

**DdVideoPortDestroy** returns one of the following callback codes:

## Remarks

**DdVideoPortDestroy** can be optionally implemented in DirectDraw drivers that support VPE.

The driver should free any memory that it allocated and associated with the specified VPE object. This includes freeing any driver-allocated memory accessed through the **dwReserved1** and **dwReserved2** members of the [DD_VIDEOPORT_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_videoport_local) structure. This DD_VIDEOPORT_LOCAL structure is at the **lpVideoPort** member of the DD_DESTROYVPORTDATA structure at *lpDestroyVideoPort*.

## See also

[DD_DESTROYVPORTDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_destroyvportdata)

[DD_VIDEOPORT_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_videoport_local)

[DdVideoPortCreate](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_vportcb_createvideoport)