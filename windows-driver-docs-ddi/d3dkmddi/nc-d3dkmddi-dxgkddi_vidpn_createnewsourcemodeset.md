# DXGKDDI_VIDPN_CREATENEWSOURCEMODESET callback function

## Description

The **pfnCreateNewSourceModeSet** function creates a new source mode set object within a specified VidPN object.

## Parameters

### `hVidPn` [in]

A handle to a VidPN object. The VidPN manager previously provided this handle to the display miniport driver by calling [DxgkDdiEnumVidPnCofuncModality](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_enumvidpncofuncmodality), [DxgkDdiIsSupportedVidPn](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_issupportedvidpn), or [DxgkDdiRecommendFunctionalVidPn](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_recommendfunctionalvidpn).

### `VidPnSourceId` [in]

An integer that identifies one of the video present sources associated with the VidPN object.

### `phNewVidPnSourceModeSet` [out]

A pointer to a variable that receives a handle to the newly created source mode set object.

### `ppVidPnSourceModeSetInterface` [out]

A pointer to a variable that receives a pointer to a [DXGK_VIDPNSOURCEMODESET_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_vidpnsourcemodeset_interface) structure. The structure contains pointers to functions that the display miniport driver can call to inspect and alter the source mode set object.

## Return value

The **pfnCreateNewSourceModeSet** function returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The function succeeded.|
|STATUS_GRAPHICS_INVALID_VIDPN|The handle supplied in hVidPn was invalid.|
|STATUS_NO_MEMORY|The VidPN manager was unable to allocate the memory required to create the new source mode set object.|

## Remarks

To assign a new source mode set to a particular source in a VidPN, perform the following steps:

1. Call **pfnCreateNewSourceModeSet** to get a handle to a new source mode set object. That source mode set object belongs to a particular VidPN object that you specify.
2. Use the functions of the [DXGK_VIDPNSOURCEMODESET_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_vidpnsourcemodeset_interface) interface to add modes to the source mode set object.
3. Call [pfnAssignSourceModeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpn_assignsourcemodeset) to assign the new source mode set to a particular source.

If you obtain a handle by calling **pfnCreateNewSourceModeSet** and then pass that handle to **pfnAssignSourceModeSet**, you do not need to release the handle by calling [pfnReleaseSourceModeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpn_releasesourcemodeset).

If you obtain a handle by calling **pfnCreateNewSourceModeSet** and then you decide not to assign the new source mode set to a source, you must release the newly obtained handle by calling **pfnReleaseSourceModeSet**.

The lifetime of the DXGK_VIDPNSOURCEMODESET_INTERFACE structure returned in *ppVidPnSourceModeSetInterface* is owned by the operating system. Using this ownership scheme, the operating system can switch to newer implementations at run time without breaking clients of the interface.

The D3DKMDT_HVIDPN and D3DKMDT_HVIDPNSOURCEMODESET data types are defined in *D3dkmdt.h*.

## See also

[VidPN Source Mode Set Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/)

[pfnAssignSourceModeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpn_assignsourcemodeset)

[pfnReleaseSourceModeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpn_releasesourcemodeset)