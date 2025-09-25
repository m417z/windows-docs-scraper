# NetQueryServiceAccount function

## Description

Gets information about the specified managed service account.

## Parameters

### `ServerName` [in, optional]

The value of this parameter must be **NULL**.

### `AccountName` [in]

The name of the account to be created.

### `InfoLevel` [in]

Specifies the format of the data returned in the *Buffer* parameter. This can be the following value.

| Value | Meaning |
| --- | --- |
| 0 | The *Buffer* parameter contains an [MSA_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-msa_info_0) structure. |

### `Buffer` [out]

Information about the specified service account.

When you have finished using this buffer, free it by calling the [NetApiBufferFree](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferfree) function.

## Return value

If the function succeeds, it returns **STATUS_SUCCESS**.

If the function fails, it returns an error code.

## See also

[NetAddServiceAccount](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netaddserviceaccount)

[NetEnumerateServiceAccounts](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netenumerateserviceaccounts)

[NetIsServiceAccount](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netisserviceaccount)

[NetRemoveServiceAccount](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netremoveserviceaccount)