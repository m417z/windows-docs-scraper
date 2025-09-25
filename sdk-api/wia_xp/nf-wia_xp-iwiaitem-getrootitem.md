# IWiaItem::GetRootItem

## Description

The **IWiaItem::GetRootItem** method retrieves the root item of a tree of item objects used to represent a Windows Image Acquisition (WIA) hardware device.

## Parameters

### `ppIWiaItem` [out]

Type: **[IWiaItem](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiaitem)****

Receives the address of a pointer to the [IWiaItem](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiaitem) interface that contains a pointer to the **IWiaItem** interface of the root item.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Given any [IWiaItem](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiaitem) object in the object tree of a WIA hardware device, the application retrieves a pointer to the root item by calling this function.

Applications must call the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method on the interface pointers they receive through the *ppIWiaItem* parameter.