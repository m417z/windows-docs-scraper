# DXGKDDI_VIDPN_CREATENEWTARGETMODESET callback function

## Description

The **pfnCreateNewTargetModeSet** function creates a new target mode set object within a specified VidPN object.

## Parameters

### `hVidPn` [in]

A handle to a VidPN object. The VidPN manager previously provided this handle to the display miniport driver by calling [DxgkDdiEnumVidPnCofuncModality](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_enumvidpncofuncmodality), [DxgkDdiIsSupportedVidPn](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_issupportedvidpn), or [DxgkDdiRecommendFunctionalVidPn](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_recommendfunctionalvidpn).

### `VidPnTargetId` [in]

An integer that identifies one of the video present targets associated with the VidPN object.

### `phNewVidPnTargetModeSet` [out]

A pointer to a variable that receives a handle to the newly created target mode set object.

### `ppVidPnTargetModeSetInterace` [out]

A pointer to a variable that receives a pointer to a [DXGK_VIDPNTARGETMODESET_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_vidpntargetmodeset_interface) structure. The structure contains pointers to functions that the display miniport driver can call to inspect and alter the target mode set object.

## Return value

The **pfnCreateNewTargetModeSet** function returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The function succeeded.|
|STATUS_GRAPHICS_INVALID_VIDPN|The handle supplied in hVidPn was invalid.|
|STATUS_NO_MEMORY|The VidPN manager was unable to allocate the memory required to create the new target mode set object.|

## Remarks

To assign a new target mode set to a particular target in a VidPN implementation, perform the following steps:

1. Call **pfnCreateNewTargetModeSet** to get a handle to a new target mode set object. That target mode set object belongs to a particular VidPN object that you specify.
2. Use the functions of the [DXGK_VIDPNTARGETMODESET_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_vidpntargetmodeset_interface) structure to add modes to the target mode set object.
3. Call [pfnAssignTargetModeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpn_assigntargetmodeset) to assign the new target mode set to a particular target.

If you obtain a handle by calling **pfnCreateNewTargetModeSet** and then pass that handle to **pfnAssignTargetModeSet**, you do not need to release the handle by calling [pfnReleaseTargetModeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpn_releasetargetmodeset).

If you obtain a handle by calling **pfnCreateNewTargetModeSet** and then you decide not to assign the new target mode set to a target, you must release the newly obtained handle by calling **pfnReleaseTargetModeSet**.

The lifetime of the DXGK_VIDPNTARGETEMODESET_INTERFACE structure returned in *ppVidPnTargetModeSetInterface* is owned by the operating system. Using this ownership scheme, the operating system can switch to newer implementations at run time without breaking clients of the interface.

The D3DKMDT_HVIDPN and D3DKMDT_HVIDPNTARGETMODESET data types are defined in *D3dkmdt.h*.

## See also

[VidPN Target Mode Set Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/)

[pfnAssignTargetModeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpn_assigntargetmodeset)

[pfnReleaseTargetModeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpn_releasetargetmodeset)