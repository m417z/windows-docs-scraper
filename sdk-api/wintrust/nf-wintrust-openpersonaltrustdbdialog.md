# OpenPersonalTrustDBDialog function

## Description

The **OpenPersonalTrustDBDialog** function displays the **Certificates** dialog box.

**Note** This function has no associated header file or import library. You must define the function yourself and use the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Wintrust.dll.

## Parameters

### `hwndParent` [in, optional]

The handle of the parent window for the dialog box. If this parameter is **NULL**, the dialog box has no parent.

## Return value

Returns nonzero if the dialog box was opened successfully or zero otherwise.