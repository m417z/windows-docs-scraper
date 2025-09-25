## Description

Installs a given profile for use on a specified machine. The profile is also copied to the COLOR directory.

## Parameters

### `pMachineName`

Reserved. Must be **NULL**. This parameter is intended to point to the name of the computer on which the profile is to be installed. A **NULL** pointer indicates the local computer.

### `pProfileName`

Pointer to the fully qualified path name of the profile to install.

## Return value

If this function succeeds, the return value is **TRUE**.

If this function fails, the return value is **FALSE**. For extended error information, call **GetLastError**.

## Remarks

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)