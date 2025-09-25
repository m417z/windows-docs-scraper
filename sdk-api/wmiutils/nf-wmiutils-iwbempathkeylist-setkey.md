# IWbemPathKeyList::SetKey

## Description

The
**IWbemPathKeyList::SetKey** method sets the name or value pair for a key. If the key exists, it is replaced. If the name is empty, all existing keys are deleted.

## Parameters

### `wszName` [in]

Key name, may be **NULL**.

### `uFlags` [in]

Reserved. Must be 0 (zero).

### `uCimType` [in]

CIMTYPE size.

### `pKeyVal` [in]

Pointer to the data. The data pointed to varies depending on the *uCimType* parameter.

## Return value

This method returns an **HRESULT** indicating the status of the method call.

## See also

[IWbemPath](https://learn.microsoft.com/windows/desktop/api/wmiutils/nn-wmiutils-iwbempath)

[IWbemPathKeyList](https://learn.microsoft.com/windows/desktop/api/wmiutils/nn-wmiutils-iwbempathkeylist)

[IWbemPathKeyList::SetKey2](https://learn.microsoft.com/windows/desktop/api/wmiutils/nf-wmiutils-iwbempathkeylist-setkey2)