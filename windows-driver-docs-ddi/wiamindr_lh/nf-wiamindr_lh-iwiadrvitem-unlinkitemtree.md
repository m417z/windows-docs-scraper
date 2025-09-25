## Description

The **IWiaDrvItem::UnlinkItemTree** method unlinks the driver item tree and releases all items in the tree.

## Parameters

### `__MIDL__IWiaDrvItem0005`

*lFlags* [in]

Indicates how the driver item tree should be unlinked. This parameter must be set to one of the following values.

| Value | Description |
|--|--|
| WiaItemTypeDeleted | The item is marked as deleted from the tree. |
| WiaItemTypeDisconnected | The item represents a disconnected device. |

For more information, see [WIA Item Type Flags](https://learn.microsoft.com/windows/win32/wia/-wia-wia-item-type-flags).

## Return value

If the method succeeds, it returns **S_OK**. If the method is called on a nonroot item, it returns **E_INVALIDARG**. If the method fails for another reason, it returns a standard COM error code.

## Remarks

Minidrivers must call this method on the root item in the driver item tree when they want to invalidate the tree. This is typically done when the driver is being unloaded or when the minidriver needs to rebuild the driver item tree.

## See also

[WIA Item Type Flags](https://learn.microsoft.com/windows/win32/wia/-wia-wia-item-type-flags)