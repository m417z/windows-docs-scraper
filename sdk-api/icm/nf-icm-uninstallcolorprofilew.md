## Description

Removes a specified color profile from a specified computer. Associated files are optionally deleted from the system.

## Parameters

### `pMachineName`

Reserved. Must be **NULL**. This parameter is intended to point to the name of the machine from which to uninstall the specified profile. A **NULL** pointer indicates the local machine.

### `pProfileName`

Points to the file name of the profile to uninstall.

### `bDelete`

If set to **TRUE**, the function deletes the profile from the COLOR directory. If set to **FALSE**, this function has no effect.

## Return value

If this function succeeds, the return value is **TRUE**.

If this function fails, the return value is **FALSE**. For extended error information, call **GetLastError**.

## Remarks

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)