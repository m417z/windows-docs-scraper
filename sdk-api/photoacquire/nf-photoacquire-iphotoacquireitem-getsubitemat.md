# IPhotoAcquireItem::GetSubItemAt

## Description

The `GetSubItemAt` method retrieves a subitem of an item, given the index of the subitem.

## Parameters

### `nItemIndex` [in]

Integer containing the index of the item.

### `ppPhotoAcquireItem` [out]

Returns the [IPhotoAcquireItem](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquireitem) object at the given index.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

If no item is found at the given index, *ppPhotoAcquireItem* is set to **NULL**.

## See also

[IPhotoAcquireItem Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquireitem)