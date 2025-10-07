# CchLszOfId2 function

Decodes and stores a string.

## Parameters

*id*

The identifier of the string in the resource file to be decoded and stored. The validity of the string is not verified.

*lsz*

A pointer to a buffer with a length of *cbmax*. Strings that are longer than *cbmax* are truncated.

*cbmax*

The maximum length of the string to be stored in the *lsz* parameter.

## Return value

This function returns the decoded string.

## Remarks

This function has no associated import library or header file; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions.

## Requirements

| Requirement | Value |
|----------------|-----------------------------------------------------------------------------------------|
| DLL<br> | Msjint40.dll |

