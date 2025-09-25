# IFaxAccountSet::GetAccounts

## Description

Returns an [IFaxAccounts](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxaccounts) object that represents all the fax accounts on the fax server.

## Parameters

### `ppFaxAccounts` [out, retval]

Type: **[IFaxAccounts](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxaccounts)****

The address of a pointer to an [IFaxAccounts](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxaccounts) object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[FaxAccountSet](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxaccountset)

[IFaxAccountSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxaccountset)