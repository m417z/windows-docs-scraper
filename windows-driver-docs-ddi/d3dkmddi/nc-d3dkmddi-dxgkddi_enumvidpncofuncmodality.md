# DXGKDDI_ENUMVIDPNCOFUNCMODALITY callback function

## Description

The *DxgkDdiEnumVidPnCofuncModality* function makes the source and target modes sets of a VidPN cofunctional with the VidPN's topology and the modes that have already been pinned.

## Parameters

### `hAdapter`

A handle to a context block associated with a display adapter. The display miniport driver previously provided this handle to the DirectX graphics kernel subsystem in the *MiniportDeviceContext* output parameter of the [DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function.

### `pEnumCofuncModality`

A pointer to a [DXGKARG_ENUMVIDPNCOFUNCMODALITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_enumvidpncofuncmodality) structure that contains function arguments.

## Return value

*DxgkDdiEnumVidPnCofuncModality* returns STATUS_SUCCESS if it succeeds; otherwise, it returns one of the error codes defined in *Ntstatus.h*.

## Remarks

The **hConstrainingVidPn** member of *pEnumCofuncModalityArg* is a handle to a VidPN object called the constraining VidPN. Other members of *pEnumCofuncModalityArg* identify one video present source or target as the pivot of the enumeration (or specify that there is no pivot).

*DxgkDdiEnumVidPnCofuncModality* must perform the following tasks:

* Examine the topology and mode sets of the constraining VidPN.
* Update each mode set that is not the pivot and does not already have a pinned mode. The updated mode sets must be cofunctional with the VidPN's topology and with any modes that have already been pinned.

Note that if a source or target is identified as the pivot of the enumeration, the mode set for that source or target must not change. For more information about how to update source and target mode sets, see [Enumerating Cofunctional VidPN Source and Target Modes](https://learn.microsoft.com/windows-hardware/drivers/display/enumerating-cofunctional-vidpn-source-and-target-modes).

The *DxgkDdiEnumVidPnCofuncModality* function should be made pageable.