# IPhotoAcquireItem::SetProperty

## Description

The `SetProperty` method sets a property for an item.

## Parameters

### `key` [in]

Specifies a key for the property to set.

### `pv` [in]

Pointer to a property variant containing the value to set the property to.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The property is stored in memory, but is not written to the file.

## See also

[GetProperty](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoacquireitem-getproperty)

[IPhotoAcquireItem Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquireitem)