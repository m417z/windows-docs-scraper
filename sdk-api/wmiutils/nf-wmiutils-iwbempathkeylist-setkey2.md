# IWbemPathKeyList::SetKey2

## Description

The
**IWbemPathKeyList::SetKey2** method sets the name or value pair for a key using variants. If the key exists, it is replaced.

## Parameters

### `wszName` [in]

Key name, may be **NULL**.

### `uFlags` [in]

Reserved. Must be 0 (zero).

### `uCimType` [in]

CIMTYPE size.

### `pKeyVal` [in]

Pointer to a variant that contains the data.

## Return value

This method returns an **HRESULT** indicating the status of the method call.

## See also

[IWbemPath](https://learn.microsoft.com/windows/desktop/api/wmiutils/nn-wmiutils-iwbempath)

[IWbemPathKeyList](https://learn.microsoft.com/windows/desktop/api/wmiutils/nn-wmiutils-iwbempathkeylist)