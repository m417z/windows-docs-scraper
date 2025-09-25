## Description

Sets a flag to disable or enable buffer read back.

## Parameters

### `value`

Type: **[BOOLEAN](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

`TRUE` if read back is disabled; otherwise, `FALSE`.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

If the function succeeds, it returns `S_OK`; otherwise, it returns an `HRESULT` value that indicates the error.

## Remarks

Pass `TRUE` to this function to prevent the compositor from ever rendering the buffer into a form of capture (screen capture, window capture, etc.)

## See also