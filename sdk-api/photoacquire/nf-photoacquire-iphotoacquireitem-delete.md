# IPhotoAcquireItem::Delete

## Description

The `Delete` method deletes an item.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

To determine whether an item may be deleted, call [CanDelete](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoacquireitem-candelete) first.

## See also

[IPhotoAcquireItem Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquireitem)

[IPhotoAcquireItem::CanDelete](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoacquireitem-candelete)