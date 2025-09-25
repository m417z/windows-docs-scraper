# NetEnumerateServiceAccounts function

## Description

The **NetEnumerateServiceAccounts** function enumerates the standalone managed service accounts (sMSA) on the specified server. This function only enumerates sMSAs and not group managed service accounts (gMSA).

This function has no associated import library. You must use the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Logoncli.dll.

## Parameters

### `ServerName` [in, optional]

The value of this parameter must be **NULL**.

### `Flags` [in]

This parameter is reserved. Do not use it.

### `AccountsCount` [out]

The number of elements in the *Accounts* array.

### `Accounts` [out]

A pointer to an array of the names of the service accounts on the specified server.

When you have finished using the names, free the array by calling the [NetApiBufferFree](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferfree) function.

## Return value

If the function succeeds, it returns **STATUS_SUCCESS**.

If the function fails, it returns an error code.

## See also

[NetAddServiceAccount](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netaddserviceaccount)

[NetIsServiceAccount](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netisserviceaccount)

[NetRemoveServiceAccount](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netremoveserviceaccount)