# NetIsServiceAccount function

## Description

The **NetIsServiceAccount** function tests whether the specified standalone managed service account (sMSA) or group managed service account (gMSA) exists in the Netlogon store on the specified server.

This function has no associated import library. You must use the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Logoncli.dll.

## Parameters

### `ServerName` [in, optional]

The value of this parameter must be **NULL**.

### `AccountName` [in]

The name of the account to be tested.

### `IsService` [out]

**TRUE** if the specified service account exists on the specified server; otherwise, **FALSE**.

## Return value

If the function succeeds, it returns **STATUS_SUCCESS**.

If the function fails, it returns an error code.

## See also

[NetAddServiceAccount](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netaddserviceaccount)

[NetEnumerateServiceAccounts](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netenumerateserviceaccounts)

[NetRemoveServiceAccount](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netremoveserviceaccount)