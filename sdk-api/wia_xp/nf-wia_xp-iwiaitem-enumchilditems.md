# IWiaItem::EnumChildItems

## Description

The **IWiaItem::EnumChildItems** method creates an enumerator object and passes back a pointer to its [IEnumWiaItem](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-ienumwiaitem) interface for non-empty folders in a [IWiaItem](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiaitem) tree of a Windows Image Acquisition (WIA) device.

## Parameters

### `ppIEnumWiaItem` [out]

Type: **[IEnumWiaItem](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-ienumwiaitem)****

Receives the address of a pointer to the [IEnumWiaItem](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-ienumwiaitem) interface that **IWiaItem::EnumChildItems** creates.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The WIA run-time system represents each WIA hardware device as a hierarchical tree of [IWiaItem](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiaitem) objects. The **IWiaItem::EnumChildItems** method enables applications to enumerate child items in the current item. However, it can only be applied to items that are folders.

If the folder is not empty, it contains a subtree of [IWiaItem](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiaitem) objects. The **IWiaItem::EnumChildItems** method enumerates all of the items contained in the folder. It stores a pointer to an enumerator in the *ppIEnumWiaItem* parameter. Applications use the enumerator pointer to perform the enumeration of an object's child items.

Applications must call the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method on the interface pointers they receive through the *ppIEnumWiaItem* parameter.