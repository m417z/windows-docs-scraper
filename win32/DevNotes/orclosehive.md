# ORCloseHive function

Closes the specified offline registry hive and frees memory allocated for the hive.

## Parameters

*Handle* \[in\]

A handle to the root key of the offline registry hive to be closed.

## Return value

If the function succeeds, the return value is ERROR\_SUCCESS.

If the function fails, the return value is a nonzero error code defined in Winerror.h. You can use the [FormatMessage](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-formatmessage) function with the FORMAT\_MESSAGE\_FROM\_SYSTEM flag to get a generic description of the error.

## Remarks

The **ORCloseHive** function frees all memory allocated by the offline registry functions on behalf of the specified hive.

To preserve changes to the hive, call the [**ORSaveHive**](https://learn.microsoft.com/windows/win32/devnotes/orsavehive) function before calling **ORCloseHive**.

## Requirements

| Requirement | Value |
|----------------------------|---------------------------------------------------------------------------------------|
| Redistributable<br> | Windows Offline Registry library version 1.0 or later<br> |
| Header<br> | Offreg.h |
| DLL<br> | Offreg.dll |

## See also

[**OROpenHive**](https://learn.microsoft.com/windows/win32/devnotes/oropenhive)

[**ORSaveHive**](https://learn.microsoft.com/windows/win32/devnotes/orsavehive)

