## Description

Dismounts an image mounted with volumeId as the volume GUID.

## Parameters

### `volumeId`

Type: **GUID\***
Provides the volume GUID of the currently mounted image.

## Return value

**[HRESULT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND) – The volume GUID specified does not refer to a volume for a mounted CIM image.

## Remarks

## See also