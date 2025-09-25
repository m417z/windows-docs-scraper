# IWiaItem::GetItemType

## Description

The **IWiaItem::GetItemType** method is called by applications to obtain the type information of an item.

## Parameters

### `pItemType` [out]

Type: **LONG***

Receives the address of a **LONG** variable that contains a combination of [WIA Item Type Flags](https://learn.microsoft.com/windows/desktop/wia/-wia-wia-item-type-flags).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Every [IWiaItem](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiaitem) object in the hierarchical tree of objects associated with a Windows Image Acquisition (WIA) hardware device has a specific data type. Item objects represent folders and files. Folders contain file objects. File objects contain data acquired by the device such as images and sounds. This method enables applications to identify the type of any item in a hierarchical tree of item objects in a device.

An item may have more than one type. For example, an item that represents an audio file will have the type attributes [WiaItemTypeAudio](https://learn.microsoft.com/windows/desktop/wia/-wia-wia-item-type-flags) | **WiaItemTypeFile**.