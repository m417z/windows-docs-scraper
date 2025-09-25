# DXGKDDI_VIDPN_ASSIGNSOURCEMODESET callback function

## Description

The **pfnAssignSourceModeSet** function assigns a source mode set to a particular source in a specified VidPN.

## Parameters

### `hVidPn` [in]

A handle to a VidPN object. The VidPN manager previously provided this handle to the display miniport driver by calling [DxgkDdiEnumVidPnCofuncModality](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_enumvidpncofuncmodality) or [DxgkDdiRecommendFunctionalVidPn](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_recommendfunctionalvidpn).

### `VidPnSourceId` [in]

An integer that identifies one of the video present sources associated with the VidPN object.

### `hVidPnSourceModeSet` [in]

A handle to the source mode set object that is to be assigned to the source identified by *VidPnSourceId*. The display miniport driver previously obtained this handle by calling [pfnCreateNewSourceModeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpn_createnewsourcemodeset).

## Return value

The **pfnAssignSourceModeSet** function returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The function succeeded.|
|STATUS_GRAPHICS_INVALID_VIDPN|The handle supplied in hVidPn was invalid.|
|STATUS_GRAPHICS_INVALID_VIDEO_PRESENT_SOURCE|The identifier supplied in VidPnSourceId was invalid.|
|STATUS_GRAPHICS_INVALID_VIDPN_SOURCEMODESET|The handle supplied in hVidPnSourceModeSet was invalid.|
|STATUS_GRAPHICS_PINNED_MODE_MUST_REMAIN_IN_SET|The source mode set you are attempting to assign does not contain the mode that was already pinned on the source.|

## Remarks

VidPN source identifiers are assigned by the operating system. [DxgkDdiStartDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device), implemented by the display miniport driver, returns the number N of video present sources supported by the display adapter. Then the operating system assigns identifiers 0, 1, 2, ... N - 1.

If you obtain a handle by calling **pfnCreateNewSourceModeSet** and then pass that handle to **pfnAssignSourceModeSet**, you do not need to release the handle by calling [pfnReleaseSourceModeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpn_releasesourcemodeset).

If you obtain a handle by calling **pfnCreateNewSourceModeSet** and then you decide not to assign the new source mode set to a source, you must release the newly obtained handle by calling **pfnReleaseSourceModeSet**.

**Note** The **pfnAssignSourceModeSet** function releases or does not release the source mode set object that is identified by the *hVidPnSourceModeSet* parameter depending on the reason that caused **pfnAssignSourceModeSet** to fail.

**pfnAssignSourceModeSet** does not release the source mode set object if **pfnAssignSourceModeSet** fails with an invalid input parameter (that is, fails with the STATUS_GRAPHICS_INVALID_VIDPN, STATUS_GRAPHICS_INVALID_VIDEO_PRESENT_SOURCE, or STATUS_GRAPHICS_INVALID_VIDPN_SOURCEMODESET error code) because the parameters that were specified were not sufficient for the operating system to determine which mode set object to release. Such invalid parameter situations indicate a gross coding error in the driver. You can fix this error by specifying the correct VidPN handle, source identifier, or VidPN source mode set handle.

**pfnAssignSourceModeSet** will release the source mode set object after successfully validating all of the input parameters if **pfnAssignSourceModeSet** fails because of one of the following reasons:

* The source mode set is empty.
* The source mode set does not contain a mode that is pinned in the previous mode set, if any.
* The source mode set was not created for the source that is identified by *VidPnSourceId*.

The D3DDDI_VIDEO_PRESENT_SOURCE_ID data type is defined in *D3dukmdt.h*.

The D3DKMDT_HVIDPN and D3DKMDT_HVIDPNSOURCEMODESET data types are defined in *D3dkmdt.h*.

## See also

[VidPN Source Mode Set Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/)

[pfnCreateNewSourceModeSet](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpn_createnewsourcemodeset)