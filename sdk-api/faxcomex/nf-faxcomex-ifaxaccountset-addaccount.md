# IFaxAccountSet::AddAccount

## Description

Adds a fax account to the fax server and returns the new [IFaxAccount](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxaccount) object.

## Parameters

### `bstrAccountName` [in]

Type: **BSTR**

Specifies a null-terminated string that contains a name for the new account.

### `pFaxAccount`

Type: **[IFaxAccount](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxaccount)****

The address of a pointer to an [IFaxAccount](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxaccount) object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

*bstrAccountName* must be of the form <domainName>\<username> or just <username> for local users.

When the new account is returned, all its values except the name are set to defaults.

## See also

[FaxAccountSet](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxaccountset)

[IFaxAccountSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxaccountset)