# JetErrFormattedMessage function

Retrieves an error code identifier (IDA) and creates the final display string when a Jet error and extended error information is provided.

## Parameters

*err*

The Jet error number that is used to look up and format the displayable error message.

*pExtendedErrorInfo*

All Jet error information including the database name, the table name, and any minor error information.

*pIda*

A pointer to the IDA that is associated with the specific error code.

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

If the function succeeds, it returns **JET\_errSuccess**; otherwise, it returns a formatted error message that indicates the specific reason for failure.

## Remarks

This function has no associated import library or header file; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions.

## Requirements

| Requirement | Value |
|----------------|-----------------------------------------------------------------------------------------|
| DLL<br> | Msjter40.dll |

