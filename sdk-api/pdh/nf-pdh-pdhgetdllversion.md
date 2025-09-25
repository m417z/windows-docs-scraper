# PdhGetDllVersion function

## Description

Returns the version of the currently installed Pdh.dll file.

**Note** This function is obsolete and no longer supported.

## Parameters

### `lpdwVersion` [out]

Pointer to a variable that receives the version of Pdh.dll. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **PDH_CVERSION_WIN50** | The file version is a legacy operating system. |
| **PDH_VERSION** | The file version is Windows XP. |

## Return value

If the function succeeds, it returns ERROR_SUCCESS.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) or a
[PDH error code](https://learn.microsoft.com/windows/desktop/PerfCtrs/pdh-error-codes). The following are possible values.

## Remarks

This function is used to help in determining the functionality that the currently installed version of Pdh.dll supports.