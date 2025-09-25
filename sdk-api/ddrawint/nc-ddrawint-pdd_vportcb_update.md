## Description

The **DdVideoPortUpdate** callback function starts and stops the VPE object, and modifies the VPE object data stream.

## Parameters

### `unnamedParam1`

Points to a [DD_UPDATEVPORTDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_updatevportdata) structure that contains the information required for the driver to update the VPE object.

## Return value

**DdVideoPortUpdate** returns one of the following callback codes:

## Remarks

DirectDraw drivers that support VPE must implement **DdVideoPortUpdate**.

When the **dwFlags** member of the DD_UPDATEVPORTDATA structure at *lpUpdate* is DDRAWI_VPORTSTART or DDRAWI_VPORTUPDATE, the driver should do the following:

* Check all flags in the **dwVPFlags** member of the [DDVIDEOPORTINFO](https://learn.microsoft.com/windows/desktop/api/dvp/ns-dvp-ddvideoportinfo) structure to which the *lpVideoInfo* member of DD_UPDATEVPORTDATA points. These flags describe how the driver should transfer video data to a surface (or surfaces); for example, they indicate whether the driver should perform autoflipping, crop the video or [VBI](https://learn.microsoft.com/windows-hardware/drivers/) data, etc.
* Set up loops in the hardware to write video and/or VBI data to the surfaces in the order in which the surfaces are stored in the array(s). The driver should return as quickly as possible after setting up these loops.
* If autoflipping has been requested, store the frame buffer offset for each surface in the driver's internal data structure. The surface offsets should be stored in the order in which the surfaces occur in the [DD_SURFACE_INT](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_surface_int) arrays at the **lplpDDSurface** and **lplpDDVBISurface** members of DD_UPDATEVPORTDATA. In this way, when [DdUpdateOverlay](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_surfcb_updateoverlay) is called, the driver has a record of the flipping order of the surface chain.

If the **dwVBIHeight** member of the DDVIDEOPORTINFO structure is greater than zero and **lplpDDVBISurface** is not **NULL**, the driver should write the lines of [VBI](https://learn.microsoft.com/windows-hardware/drivers/) data specified by the number in **dwVBIHeight** into each surface in the array to which **lplpDDVBISurface** points.

If the driver's hardware cannot support the number of surfaces specified when autoflipping is requested, **DdVideoPortUpdate** should fail the call by setting DDERR_UNSUPPORTED in the **ddRVal** member of DD_UPDATEVPORTDATA.

The number of surfaces in the video and [VBI](https://learn.microsoft.com/windows-hardware/drivers/) surface chains can be different; that is, the **dwNumAutoflip** and **dwNumVBIAutoflip** members of DD_UPDATEVPORTDATA can be different values.

When **dwFlags** is DDRAWI_VPORTSTOP, the driver should return immediately. The driver should not poll until the data stream stops.

## See also

[DDVIDEOPORTINFO](https://learn.microsoft.com/windows/desktop/api/dvp/ns-dvp-ddvideoportinfo)

[DD_SURFACE_INT](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_surface_int)

[DD_UPDATEVPORTDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_updatevportdata)

[DdUpdateOverlay](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_surfcb_updateoverlay)