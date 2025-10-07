# NmMakeCert function

Creates a user certificate for use with NetMeeting conferencing.

## Parameters

*szFirstName*

The user's first name.

*szLastName*

The user's last name.

*szEmailName*

The user's email name.

*szCity*

The user's city.

*szCountry*

The user's country/region.

*dwFlags*

A value that indicates how the certificate should be created. Values can be any of the following.

| Value | Meaning |
|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------|
| **NMMKCERT\_F\_CLEANUP\_ONLY**

0x00000004 | Delete the old certificate without creating a new one. \ | | **NMMKCERT\_F\_DELETEOLDCERT**

0x00000001 | Delete the old certificate previously created with this function. \ | | **NMMKCERT\_F\_LOCAL\_MACHINE**

0x00000002 | Create the certificate in the local machine certificate store. \ |

## Return value

Returns 1 if the function succeeds and –1 if the function fails.

## Remarks

This function has no associated import library or header file; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions.

## Requirements

| Requirement | Value |
|----------------|-----------------------------------------------------------------------------------------|
| DLL<br> | Nmmkcert.dll |

