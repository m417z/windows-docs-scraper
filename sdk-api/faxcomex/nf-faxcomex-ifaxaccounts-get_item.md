# IFaxAccounts::get_Item

## Description

Returns a [FaxAccount](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxaccount) object from a [FaxAccounts](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxaccounts) collection.

## Parameters

### `vIndex` [in]

Type: **VARIANT**

**VARIANT** that specifies a value that indicates the item to retrieve from the collection. If this parameter is type **VT_I2** or **VT_I4**, it specifies the index of the item to retrieve. The index is 1-based. If this parameter is type **VT_BSTR**, it specifies the account name to use to search the collection. Other types are not supported.

### `pFaxAccount` [out, retval]

Type: **[IFaxAccount](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxaccount)****

The [FaxAccount](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxaccount) object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IFaxAccounts](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxaccounts)

[Item](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxaccounts-item)