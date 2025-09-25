# DXGKDDI_VIDPN_ASSIGNTARGETMODESET callback function

## Description

The **pfnAssignTargetModeSet** function assigns a target mode set to a particular target in a specified VidPN.

## Parameters

### `hVidPn` [in]

A handle to a VidPN object. The VidPN manager previously provided this handle to the display miniport driver by calling [DxgkDdiEnumVidPnCofuncModality](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_enumvidpncofuncmodality) or [DxgkDdiRecommendFunctionalVidPn](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_recommendfunctionalvidpn).

### `VidPnTargetId` [in]

An integer that identifies one of the video present targets associated with the VidPN object.

### `hVidPnTargetModeSet` [in]

A handle to the target mode set object that is to be assigned to the target identified by *VidPnTargetId*. The display miniport driver previously obtained this handle by calling [pfnCreateNewTargetModeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpn_createnewtargetmodeset).

## Return value

The **pfnAssignTargetModeSet** function returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The function succeeded.|
|STATUS_GRAPHICS_INVALID_VIDPN|The handle supplied in hVidPn was invalid.|
|STATUS_GRAPHICS_INVALID_VIDEO_PRESENT_TARGET|The identifier supplied in VidPnTargetId was invalid.|
|STATUS_GRAPHICS_INVALID_VIDPN_TARGETMODESET|The handle supplied in hVidPnTargetModeSet was invalid.|
|STATUS_GRAPHICS_PINNED_MODE_MUST_REMAIN_IN_SET|The target mode set you are attempting to assign does not contain the mode that was already pinned on the target.|

## Remarks

VidPN target identifiers are assigned by the display miniport driver. [DxgkDdiQueryChildRelations](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_child_relations), implemented by the display miniport driver, returns an array of [DXGK_CHILD_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_child_descriptor) structures, each of which contains an identifier.

If you obtain a handle by calling **pfnCreateNewTargetModeSet** and then pass that handle to **pfnAssignTargetModeSet**, you do not need to release the handle by calling [pfnReleaseTargetModeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpn_releasetargetmodeset).

If you obtain a handle by calling **pfnCreateNewTargetModeSet** and then you decide not to assign the new target mode set to a target, you must release the newly obtained handle by calling **pfnReleaseTargetModeSet**.

**Note** The **pfnAssignTargetModeSet** function releases or does not release the target mode set object that is identified by the *hVidPnTargetModeSet* parameter depending on the reason that caused **pfnAssignTargetModeSet** to fail.

**pfnAssignTargetModeSet** does not release the target mode set object if **pfnAssignTargetModeSet** fails with an invalid input parameter (that is, fails with the STATUS_GRAPHICS_INVALID_VIDPN, STATUS_GRAPHICS_INVALID_VIDEO_PRESENT_TARGET, or STATUS_GRAPHICS_INVALID_VIDPN_TARGETMODESET error code) because the parameters that were specified were not sufficient for the operating system to determine which mode set object to release. Such invalid parameter situations indicate a gross coding error in the driver. You can fix this error by specifying the correct VidPN handle, target identifier, or VidPN target mode set handle.

**pfnAssignTargetModeSet** will release the target mode set object after successfully validating all of the input parameters if **pfnAssignTargetModeSet** fails because of one of the following reasons:

* The target mode set is empty.
* The target mode set does not contain a mode that is pinned in the previous mode set, if any.
* The target mode set was not created for the target that is identified by *VidPnTargetId*.

The D3DDDI_VIDEO_PRESENT_TARGET_ID data type is defined in *D3dukmdt.h*.

The D3DKMDT_HVIDPN and D3DKMDT_HVIDPNTARGETMODESET data types are defined in *D3dkmdt.h*.

## See also

[VidPN Target Mode Set Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/)

[pfnCreateNewTargetModeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpn_createnewtargetmodeset)