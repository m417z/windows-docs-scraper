## Description

Sets a target time for the next present.

## Parameters

### `targetTime`

Type: **[SystemInterruptTime](https://learn.microsoft.com/windows/win32/api/presentationtypes/ns-presentationtypes-systeminterrupttime)**

The target time for the next present.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

If the function succeeds, it returns `S_OK`; otherwise, it returns an `HRESULT` value that indicates the error.

## Remarks

The system will attempt to display the present as close to the specified time as possible.

This parameter setting persists across presents.

## See also