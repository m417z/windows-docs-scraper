## Description

Presents this presentation manager.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

If the function succeeds, it returns `S_OK`; otherwise, it returns an `HRESULT` value that indicates the error.

## Remarks

If the presentation manager has become lost, this call will return `PRESENTATION_ERROR_LOST`. If the application receives that error, you must destroy this presentation manager and create a new one.

## See also