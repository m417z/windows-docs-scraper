# OOBEComplete function

## Description

Determines whether OOBE (Windows Welcome) has been completed.

## Parameters

### `isOOBEComplete` [out]

Pointer to a variable that will receive the completion of OOBE upon success.

## Return value

**TRUE** if the OOBE completion state was successfully set. Otherwise,
**FALSE** if OOBE completion state was not set. If **FALSE**,
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) will retrieve extended error
information.