# IWiaItem::FindItemByName

## Description

The **IWiaItem::FindItemByName** method searches an item's tree of sub-items using the name as the search key. Each [IWiaItem](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiaitem) object has a name as one of its standard properties.

## Parameters

### `lFlags` [in]

Type: **LONG**

Currently unused. Should be set to zero.

### `bstrFullItemName` [in]

Type: **BSTR**

Specifies the name of the item for which to search.

### `ppIWiaItem` [out]

Type: **[IWiaItem](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiaitem)****

Pointer to the [IWiaItem](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiaitem) interface.

## Return value

Type: **HRESULT**

This method returns S_OK if it finds the item, or S_FALSE if it does not find the item. If the method fails, it returns a standard COM error code.

## Remarks

This method searches the current item's tree of sub-items using the name as the search key. If **IWiaItem::FindItemByName** finds the item specified by *bstrFullItemName*, it stores the address of a pointer to the [IWiaItem](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiaitem) interface of the item in the *ppIWiaItem* parameter.

Applications must call the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method on the interface pointers they receive through the *ppIWiaItem* parameter.