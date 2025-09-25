# DXGKDDI_VIDPN_ACQUIRESOURCEMODESET callback function

## Description

The **pfnAcquireSourceModeSet** function returns a handle to a particular source mode set object that is contained by a specified VidPN object.

## Parameters

### `hVidPn` [in]

A handle to a VidPN object. The VidPN manager previously provided this handle to the display miniport driver by calling [DxgkDdiEnumVidPnCofuncModality](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_enumvidpncofuncmodality), [DxgkDdiIsSupportedVidPn](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_issupportedvidpn), or [DxgkDdiRecommendFunctionalVidPn](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_recommendfunctionalvidpn).

### `VidPnSourceId` [in]

An integer that identifies one of the video present sources associated with the VidPN object.

### `phVidPnSourceModeSet` [out]

A pointer to a variable that receives a handle to the requested source mode set object.

### `ppVidPnSourceModeSetInterface` [out]

A pointer to a variable that receives a pointer to a [DXGK_VIDPNSOURCEMODESET_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_vidpnsourcemodeset_interface) structure. The structure contains pointers to functions that the display miniport driver can call to inspect and alter the source mode set object.

## Return value

The **pfnAcquireSourceModeSet** function returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The function succeeded.|
|STATUS_GRAPHICS_INVALID_VIDPN|The handle supplied in hVidPn was invalid.|
|STATUS_GRAPHICS_INVALID_VIDEO_PRESENT_SOURCE|The identifier supplied in VidPnSourceId was invalid.|

## Remarks

VidPN source identifiers are assigned by the operating system. [DxgkDdiStartDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device), implemented by the display miniport driver, returns the number N of video present sources supported by the display adapter. Then the operating system assigns identifiers 0, 1, 2, ... N - 1.

When you have finished using the source mode set object handle, you must release the handle by calling [pfnReleaseSourceModeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpn_releasesourcemodeset). Source mode set objects are reference counted, so if you acquire a handle several times, you must release it that same number of times.

The lifetime of the [DXGK_VIDPNSOURCEMODESET_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_vidpnsourcemodeset_interface) structure returned in *ppVidPnSourceModeSetInterface* is owned by the operating system. Using this ownership scheme, the operating system can switch to newer implementations at run time without breaking clients of the interface.

The D3DDDI_VIDEO_PRESENT_SOURCE_ID data type is defined in *D3dukmdt.h*.

The D3DKMDT_HVIDPN and D3DKMDT_HVIDPNSOURCEMODESET data types are defined in *D3dkmdt.h*.

## See also

[VidPN Source Mode Set Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/)

[pfnAssignTargetModeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpn_assigntargetmodeset)

[pfnCreateNewSourceModeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpn_createnewsourcemodeset)

[pfnReleaseTargetModeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpn_releasetargetmodeset)