# DXGKDDI_VIDPN_ACQUIRETARGETMODESET callback function

## Description

The **pfnAcquireTargetModeSet** function returns a handle to a particular target mode set object that is contained by a specified VidPN object.

## Parameters

### `hVidPn` [in]

A handle to a VidPN object. The VidPN manager previously provided this handle to the display miniport driver by calling [DxgkDdiEnumVidPnCofuncModality](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_enumvidpncofuncmodality), [DxgkDdiIsSupportedVidPn](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_issupportedvidpn), or [DxgkDdiRecommendFunctionalVidPn](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_recommendfunctionalvidpn).

### `VidPnTargetId` [in]

An integer that identifies one of the video present targets associated with the VidPN object.

### `phVidPnTargetModeSet` [out]

A pointer to a variable that receives a handle to the requested target mode set object.

### `ppVidPnTargetModeSetInterface` [out]

A pointer to a variable that receives a pointer to a [DXGK_VIDPNTARGETMODESET_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_vidpntargetmodeset_interface) structure. The structure contains pointers to functions that the display miniport driver can call to inspect and alter the target mode set object.

## Return value

The **pfnAcquireTargetModeSet** function returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The function succeeded.|
|STATUS_GRAPHICS_INVALID_VIDPN|The handle supplied in hVidPn was invalid.|
|STATUS_GRAPHICS_INVALID_VIDEO_PRESENT_TARGET|The identifier supplied in VidPnTargetId was invalid.|

## Remarks

VidPN target identifiers are assigned by the display miniport driver. [DxgkDdiQueryChildRelations](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_child_relations), implemented by the display miniport driver, returns an array of [DXGK_CHILD_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_child_descriptor) structures, each of which contains an identifier.

When you have finished using the target mode set object handle, you must release the handle by calling [pfnReleaseTargetModeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpn_releasetargetmodeset). Target mode set objects are reference counted, so if you acquire a handle several times, you must release it that same number of times.

The lifetime of the [DXGK_VIDPNTARGETMODESET_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_vidpntargetmodeset_interface) structure returned in *ppVidPnTargetModeSetInterface* is owned by the operating system. Using this ownership scheme, the operating system can switch to newer implementations at run time without breaking clients of the interface.

The D3DDDI_VIDEO_PRESENT_TARGET_ID data type is defined in *D3dukmdt.h*.

The D3DKMDT_HVIDPN and D3DKMDT_HVIDPNTARGETMODESET data types are defined in *D3dkmdt.h*.

## See also

[VidPN Target Mode Set Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/)

[pfnAssignTargetModeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpn_assigntargetmodeset)

[pfnCreateNewTargetModeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpn_createnewtargetmodeset)

[pfnReleaseTargetModeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpn_releasetargetmodeset)