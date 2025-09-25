# IPhotoAcquireSource::GetItemCount

## Description

The `GetItemCount` method retrieves the number of items found by the [InitializeItemList](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoacquiresource-initializeitemlist) method.

## Parameters

### `pnItemCount` [out]

Pointer to an integer value containing the item count.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | NULL was passed where a non-NULL pointer was expected. |

## Remarks

Before calling this method, call [InitializeItemList](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoacquiresource-initializeitemlist) to initialize the item list.

## See also

[IPhotoAcquireSource Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquiresource)

[IPhotoAcquireSource::InitializeItemList](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoacquiresource-initializeitemlist)