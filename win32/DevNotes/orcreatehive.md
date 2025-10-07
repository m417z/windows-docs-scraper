# ORCreateHive function

Creates an offline registry hive that contains a single empty root key.

## Parameters

*phkResult* \[out\]

Points to a variable to receive a handle to the root key of the newly created offline registry hive. If the hive cannot be created, the function sets this parameter to **NULL**.

## Return value

If the function succeeds, the return value is ERROR\_SUCCESS.

If the function fails, the return value is a nonzero error code defined in Winerror.h. You can use the [FormatMessage](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-formatmessage) function with the FORMAT\_MESSAGE\_FROM\_SYSTEM flag to get a generic description of the error.

If there is insufficient memory to create the registry hive, the function returns ERROR\_NOT\_ENOUGH\_MEMORY.

## Remarks

The **ORCreateHive** function creates an empty offline registry hive in memory. Use the [**ORCreateKey**](https://learn.microsoft.com/windows/win32/devnotes/orcreatekey) and [**ORSetValue**](https://learn.microsoft.com/windows/win32/devnotes/orsetvalue) functions to add keys and set their values.

## Requirements

| Requirement | Value |
|----------------------------|---------------------------------------------------------------------------------------|
| Redistributable<br> | Windows Offline Registry library version 1.0 or later<br> |
| Header<br> | Offreg.h |
| DLL<br> | Offreg.dll |

## See also

[**ORCreateKey**](https://learn.microsoft.com/windows/win32/devnotes/orcreatekey)

[**OROpenHive**](https://learn.microsoft.com/windows/win32/devnotes/oropenhive)

[**ORSaveHive**](https://learn.microsoft.com/windows/win32/devnotes/orsavehive)

[**ORSetValue**](https://learn.microsoft.com/windows/win32/devnotes/orsetvalue)

