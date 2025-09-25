# IPhotoAcquireSource::GetItemAt

## Description

The `GetItemAt` method retrieves the [IPhotoAcquireItem](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquireitem) object at the given index in the list of items.

## Parameters

### `nIndex` [in]

Integer value containing the index.

### `ppPhotoAcquireItem` [out]

Pointer to the address of an [IPhotoAcquireItem](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquireitem) object.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Before calling this method, call [InitializeItemList](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoacquiresource-initializeitemlist) to initialize the item list.

## See also

[IPhotoAcquireSource Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquiresource)