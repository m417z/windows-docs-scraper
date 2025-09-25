## Description

Enables or disables the specified present statistics kind.

## Parameters

### `presentStatisticsKind`

Type: **[PresentStatisticsKind](https://learn.microsoft.com/windows/win32/api/presentationtypes/ne-presentationtypes-presentstatisticskind)**

The present statistics kind to enable or disable.

### `enabled`

Type: **[BOOLEAN](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

`TRUE` to enable the present statistics kind; otherwise, `FALSE`.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

If the function succeeds, it returns `S_OK`; otherwise, it returns an `HRESULT` value that indicates the error.

## Remarks

The requested change takes place as soon as possible, however effects can be delayed. We suggest that you register all desired present statistics before you issue presents, and not change during use. This is also how statistics can be extended and changed in the future without breaking backwards compatibility.

## See also