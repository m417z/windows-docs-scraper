## Description

Gets the identifier of the most recent compositor frame of the specified type.

## Parameters

### `frameIdType`

Type: **[COMPOSITION_FRAME_ID_TYPE](https://learn.microsoft.com/windows/win32/api/dcomptypes/ne-dcomptypes-composition_frame_id_type)**

The type of the compositor frame.

### `frameId`

Type: **COMPOSITION_FRAME_ID\***

The identifer of the most recent compositor frame of the specified type.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the function succeeds, it returns `S_OK`; otherwise, it returns an `HRESULT` value that indicates the error.

## Remarks

## See also

[DCompositionGetTargetStatistics](https://github.com/MicrosoftDocs/sdk-api/blob/docs/sdk-api-src/content/dcomp/nf-dcomp-dcompositiongettargetstatistics.md), [DCompositionGetStatistics](https://learn.microsoft.com/windows/win32/api/dcomp/nf-dcomp-dcompositiongetstatistics), [DCompositionBoostCompositorClock](https://learn.microsoft.com/windows/win32/api/dcomp/nf-dcomp-dcompositionboostcompositorclock), [DCompositionWaitForCompositorClock](https://learn.microsoft.com/windows/win32/api/dcomp/nf-dcomp-dcompositionwaitforcompositorclock)