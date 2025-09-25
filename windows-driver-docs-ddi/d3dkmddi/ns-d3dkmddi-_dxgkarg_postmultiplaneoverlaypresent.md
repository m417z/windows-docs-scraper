# _DXGKARG_POSTMULTIPLANEOVERLAYPRESENT structure

## Description

Contains arguments for the [DxgkDdiPostMultiPlaneOverlayPresent](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_postmultiplaneoverlaypresent) function.

## Members

### `VidPnTargetId` [in]

The zero-based identification number of the video present target in a path of a video present network (VidPN) topology. This number represents the video present target where the vertical sync occurs.

### `PhysicalAdapterMask` [in]

The physical adapter mask where the vertical sync occurs. If this member contains a valid value, the driver must also set the ValidPhysicalAdapterMask bit-field flag in the Flags member.

### `LayerIndex` [in]

The zero-based index of the overlay plane to display. The top plane (in the z-direction) has index zero. The planes' index values must be sequential from top to bottom.

### `PresentID` [in]

64 bit integer value representing each flip request for a particular MPO plane.