# IWiaItem::CreateChildItem

## Description

The **IWiaItem::CreateChildItem** method is used by applications to add [IWiaItem](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiaitem) objects to the **IWiaItem** tree of a device.

## Parameters

### `lFlags` [in]

Type: **LONG**

Specifies the WIA item type. Must be set to one of the values listed in [WIA Item Type Flags](https://learn.microsoft.com/windows/desktop/wia/-wia-wia-item-type-flags).

### `bstrItemName` [in]

Type: **BSTR**

Specifies the WIA item name, such as "Top". You can think of this parameter as being equivalent to a file name.

### `bstrFullItemName` [in]

Type: **BSTR**

Specifies the full WIA item name. You can think of this parameter as equivalent to a full path to a file, such as "003\Root\Top".

### `ppIWiaItem` [out]

Type: **[IWiaItem](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiaitem)****

Receives the address of a pointer to the [IWiaItem](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiaitem) interface that sets the **IWiaItem::CreateChildItem** method.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Some WIA hardware devices allow applications to create new items in the [IWiaItem](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiaitem) tree that represents the device. Applications must test the devices to see if they support this capability. Use the [IEnumWIA_DEV_CAPS](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-ienumwia_dev_caps) interface to enumerate the current device's capabilities.

If the device allows the creation of new items in the [IWiaItem](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiaitem) tree, invoking **IWiaItem::CreateChildItem** creates a new **IWiaItem** that is a child of the current node. **IWiaItem::CreateChildItem** passes a pointer to the new node to the application through the *ppIWiaItem* parameter.

Applications must call the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method on the interface pointers they receive through the *ppIWiaItem* parameter.