# JetErrIDARawMessage function

Retrieves an unformatted message string when an error code identifier (IDA) is provided.

## Parameters

*Ida*

A number that maps to a specific error code and is displayed to the user.

*pMessage*

A pointer to the error message.

*cbMessage*

A count of the number of bytes in the error message.

*pcbActual*

A pointer to the actual number of bytes read.

*pContextId*

A pointer to the context identifier that is associated with the help file.

*pwszHelp/file*

A pointer to a pointer to the file that explains the error.

## Return value

If the function succeeds, it returns **JET\_errSuccess**; otherwise, it returns an unformatted message that indicates the specific reason for failure.

## Remarks

This function has no associated import library or header file; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions.

## Requirements

| Requirement | Value |
|----------------|-----------------------------------------------------------------------------------------|
| DLL<br> | Msjter40.dll |

