# IFaxAccountSet::RemoveAccount

## Description

Removes a fax account from the fax server.

## Parameters

### `bstrAccountName` [in]

Type: **BSTR**

Specifies a null-terminated string that contains the name of the account to be removed.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

*bstrAccountName* must be of the form \<domainName>\<username> or just \<username> for local users.

## See also

[FaxAccountSet](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxaccountset)

[IFaxAccountSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxaccountset)