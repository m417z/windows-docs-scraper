# OcInitialize function

Initializes the optional component manager.

## Parameters

*Callbacks* \[in\]

A pointer to an [**OCM\_CLIENT\_CALLBACKS**](https://learn.microsoft.com/windows/win32/devnotes/ocm-client-callbacks) structure that specifies the callback functions to be used by the OC manager to perform various tasks.

*MasterOcInfName* \[in\]

The path of the master OC .inf file.

*Flags* \[in\]

This parameter can be one or more of the following values.

**OCINIT\_FORCENEWINF** (0x00000001)

**OCINIT\_KILLSUBCOMPS** (0x00000002)

**OCINIT\_RUNQUIET** (0x00000004)

**OCINIT\_LANGUAGEAWARE** (0x00000008)

*ShowError* \[out\]

If the function fails, this parameter indicates whether to display an error message.

*Log* \[in\]

A handle to the log.

## Return value

The function returns the OC manager context value.

## Remarks

This function has no associated import library or header file; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions.

## Requirements

| Requirement | Value |
|----------------|-----------------------------------------------------------------------------------------|
| DLL<br> | OcManage.dll |

## See also

[**OCM\_CLIENT\_CALLBACKS**](https://learn.microsoft.com/windows/win32/devnotes/ocm-client-callbacks)

[**OcTerminate**](https://learn.microsoft.com/windows/win32/devnotes/octerminate)

