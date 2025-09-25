## Description

Gets basic information about the composition frame and a list of render target ID's that are part of the frame.

## Parameters

### `frameId`

Type: **COMPOSITION_FRAME_ID**

The identifier of the composition frame about which to get information.

### `frameStats`

Type: **[COMPOSITION_FRAME_STATS](https://learn.microsoft.com/windows/win32/api/dcomptypes/ns-dcomptypes-composition_frame_stats)\***

A struct that contains information about the composition frame.

### `targetIdCount`

Type: **[UINT](https://learn.microsoft.com/windows/win32/WinProg/windows-data-types)**

The number of render targets about which to get information.

### `targetIds`

Type: **[COMPOSITION_TARGET_ID](https://learn.microsoft.com/windows/win32/api/dcomptypes/ns-dcomptypes-composition_target_id)\***

The identifiers of the render targets about which to get information.

### `actualTargetIdCount`

Type: **[UINT](https://learn.microsoft.com/windows/win32/WinProg/windows-data-types)\***

The actual number of render targets.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the function succeeds, it returns `S_OK`; otherwise, it returns an `HRESULT` value that indicates the error.

## Remarks

## See also

[DCompositionGetTargetStatistics](https://github.com/MicrosoftDocs/sdk-api/blob/docs/sdk-api-src/content/dcomp/nf-dcomp-dcompositiongettargetstatistics.md), [DCompositionGetFrameId](https://learn.microsoft.com/windows/win32/api/dcomp/nf-dcomp-dcompositiongetframeid), [DCompositionBoostCompositorClock](https://learn.microsoft.com/windows/win32/api/dcomp/nf-dcomp-dcompositionboostcompositorclock), [DCompositionWaitForCompositorClock](https://learn.microsoft.com/windows/win32/api/dcomp/nf-dcomp-dcompositionwaitforcompositorclock)