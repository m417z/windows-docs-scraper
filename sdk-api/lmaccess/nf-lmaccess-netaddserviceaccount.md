# NetAddServiceAccount function

## Description

The **NetAddServiceAccount** function creates a standalone managed service account (sMSA) or retrieves the credentials for a group managed service account (gMSA) and stores the account information on the local computer.

This function has no associated import library. You must use the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Logoncli.dll.

**Windows Server 2008 R2:** Installing a managed service account by using the PowerShell command line interface cmdlet to call this function fails with error code 0xC0000225 when the value of the *AccountName* parameter does not match the corresponding [Security Accounts Manager](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SAM) name of the account.

## Parameters

### `ServerName` [in, optional]

The value of this parameter must be **NULL**.

### `AccountName` [in]

The name of the account to be created.

### `Password` [in]

This parameter is reserved. Do not use it.

### `Flags` [in]

This parameter can be the following value.

| Value | Meaning |
| --- | --- |
| **SERVICE_ACCOUNT_FLAG_LINK_TO_HOST_ONLY**<br><br>0x00000001 | No standalone managed service account is created. If a service account with the specified name exists, it is linked to the local computer. This flag is ignored if the account name is an existing gMSA. |

## Return value

If the function succeeds, it returns **STATUS_SUCCESS**.

If the function fails, it returns an error code.

## See also

[NetEnumerateServiceAccounts](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netenumerateserviceaccounts)

[NetIsServiceAccount](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netisserviceaccount)

[NetRemoveServiceAccount](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netremoveserviceaccount)