## Description

Requests that the system dynamically switch to a higher refresh rate to enhance latency-sensitive content.

## Parameters

### `enable`

Type: **[BOOL](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

`TRUE` to request that the system dynamically switch to a higher refresh rate; otherwise, `FALSE`.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the function succeeds, it returns `S_OK`; otherwise, it returns an `HRESULT` value that indicates the error.

## Remarks

## See also

[DCompositionGetTargetStatistics](https://learn.microsoft.com/windows/win32/api/dcomp/nf-dcomp-dcompositiongetstatistics), [DCompositionGetStatistics](https://learn.microsoft.com/windows/win32/api/dcomp/nf-dcomp-dcompositiongetstatistics), [DCompositionGetFrameId](https://learn.microsoft.com/windows/win32/api/dcomp/nf-dcomp-dcompositiongetframeid), [DCompositionWaitForCompositorClock](https://learn.microsoft.com/windows/win32/api/dcomp/nf-dcomp-dcompositionwaitforcompositorclock)