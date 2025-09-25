## Description

Gets per-target information for the specified composition frame and render target.

## Parameters

### `frameId`

Type: **COMPOSITION_FRAME_ID**

The identifier of the composition frame about which to get information.

### `targetId`

Type: **[COMPOSITION_TARGET_ID](https://learn.microsoft.com/windows/win32/api/dcomptypes/ns-dcomptypes-composition_target_id)\***

The identifier of the render target about which to get information.

### `targetStats`

Type: **[COMPOSITION_TARGET_STATS](https://learn.microsoft.com/windows/win32/api/dcomptypes/ns-dcomptypes-composition_target_stats)\***

Information about the specified composition frame and render target.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the function succeeds, it returns `S_OK`; otherwise, it returns an `HRESULT` value that indicates the error.

## Remarks

## See also

[DCompositionGetStatistics](https://learn.microsoft.com/windows/win32/api/dcomp/nf-dcomp-dcompositiongetstatistics), [DCompositionGetFrameId](https://learn.microsoft.com/windows/win32/api/dcomp/nf-dcomp-dcompositiongetframeid), [DCompositionBoostCompositorClock](https://learn.microsoft.com/windows/win32/api/dcomp/nf-dcomp-dcompositionboostcompositorclock), [DCompositionWaitForCompositorClock](https://learn.microsoft.com/windows/win32/api/dcomp/nf-dcomp-dcompositionwaitforcompositorclock)