# IEnumWiaItem::Skip

## Description

The **IEnumWiaItem::Skip** method skips the specified number of items during an enumeration of available [IWiaItem](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiaitem) objects.

## Parameters

### `celt` [in]

Type: **ULONG**

Specifies the number of items to skip.

## Return value

Type: **HRESULT**

If the method succeeds, the method returns S_OK. If it is unable to skip the specified number of items, it returns S_FALSE. If the method fails, it returns a standard COM error code.