# IPhotoAcquireItem::GetSubItemCount

## Description

The `GetSubItemCount` method retrieves the number of subitems contained in an item.

## Parameters

### `pnCount` [out]

Pointer to an integer containing the count of subitems.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

If an error occurs, *pnCount* will be set to **NULL**.

## See also

[IPhotoAcquireItem Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquireitem)