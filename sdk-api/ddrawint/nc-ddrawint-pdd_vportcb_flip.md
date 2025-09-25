## Description

The *DdVideoPortFlip* callback function performs a physical flip, causing the VPE object to start writing data to the new surface.

## Parameters

### `unnamedParam1`

Points to a [DD_FLIPVPORTDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_flipvportdata) structure that contains the information required for the driver to perform the flip.

## Return value

*DdVideoPortFlip* returns one of the following callback codes:

## Remarks

*DdVideoPortFlip* must be implemented in DirectDraw drivers that support VPE.

The driver should update its surface pointers so that the next frame of video will be written to the surface to which the **lpSurfTarg** member of the DD_FLIPVPORTDATA structure at *lpFlipVideoPort* points. If a previous flip request is still pending, the driver should fail the call by setting the **ddRVal** member of DD_FLIPVPORTDATA to DDERR_WASSTILLDRAWING and returning DDHAL_DRIVER_HANDLED. *DdVideoPortFlip* does not affect the actual display of the video data.

A call to *DdVideoPortFlip* typically accompanies a call to [DdFlip](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_surfcb_flip) when an application is performing video streaming.

## See also

[DD_FLIPVPORTDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_flipvportdata)

[DdFlip](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_surfcb_flip)