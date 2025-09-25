# DDSETSTATEOUTINFO structure

## Description

The DDSETSTATEOUTINFO structure contains the state information for the [video port extensions (VPE)](https://learn.microsoft.com/windows-hardware/drivers/) object.

## Members

### `bSoftwareAutoflip`

When set to a nonzero value, causes Microsoft DirectDraw to revert to software autoflipping. Note that once software autoflipping has been initiated, you cannot revert back to hardware autoflipping until the VPE object and surface are destroyed and restarted.

### `dwSurfaceIndex`

Indicates the zero-based index in the autoflip chain of the surface currently receiving the data from the VPE object. This field is ignored unless the miniport driver is switching from hardware autoflipping to software autoflipping.

### `dwVBISurfaceIndex`

Indicates the zero-based index in the autoflip chain of the [vertical blanking interval (VBI)](https://learn.microsoft.com/windows-hardware/drivers/) surface currently receiving the data from the VPE object. This field is ignored unless the video miniport driver is switching from hardware autoflipping to software autoflipping.

## Remarks

When asked to switch from bob to weave, the video miniport driver might need to switch from hardware autoflipping to software autoflipping (no current hardware supports automatic field skipping, and so on). All the driver has to do is set the **bSoftwareAutoflip** member to a nonzero value and DirectDraw reverts to software autoflipping.

If the miniport driver switches from hardware to software autoflipping, DirectDraw must know which surface is currently receiving data from the VPE object so it can continue without causing a glitch. Therefore, the miniport driver must set the **dwSurfaceIndex** member to the index in the autoflip chain of the surface currently receiving the data from the VPE object. When [DdVideoPortUpdate](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_vportcb_update) is called, it gives an array of surfaces that the driver can autoflip between. You can program the addresses of these surfaces that are used for software autoflipping into your hardware.

## See also

[DdVideoPortUpdate](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_vportcb_update)

[DxSetState](https://learn.microsoft.com/windows/desktop/api/dxmini/nc-dxmini-pdx_setstate)