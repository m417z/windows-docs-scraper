# NetRemoveServiceAccount function

## Description

The **NetRemoveServiceAccount** function deletes the specified service account from the [Active Directory](https://learn.microsoft.com/windows/desktop/AD/active-directory-domain-services) database if the account is a standalone managed service account (sMSA). For group managed service accounts (gMSAs), this function does not delete the account from the Active Directory database. The secret stored in the [Local Security Authority](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) (LSA) is deleted for both sMSAs and gMSAs, and the state is stored in the Netlogon registry store.

This function has no associated import library. You must use the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Logoncli.dll.

## Parameters

### `ServerName` [in, optional]

The value of this parameter must be **NULL**.

### `AccountName` [in]

The name of the account to be deleted.

### `Flags` [in]

This parameter can have the following value.

| Value | Meaning |
| --- | --- |
| **SERVICE_ACCOUNT_FLAG_UNLINK_FROM_HOST_ONLY**<br><br>0x00000001 | For sMSAs, the service account object is unlinked from the local computer and the secret stored in the LSA is deleted. The service account object is not deleted from the Active Directory database. This flag has no meaning for gMSAs. |

## Return value

If the function succeeds, it returns **STATUS_SUCCESS**.

If the function fails, it returns an error code.

## See also

[NetAddServiceAccount](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netaddserviceaccount)

[NetEnumerateServiceAccounts](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netenumerateserviceaccounts)

[NetIsServiceAccount](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netisserviceaccount)