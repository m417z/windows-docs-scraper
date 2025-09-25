# IPhotoAcquireItem::GetProperty

## Description

The `GetProperty` method retrieves the value of a property of an item.

## Parameters

### `key` [in]

Specifies a key for the property.

### `pv` [out]

Pointer to a property variant containing the property value.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

For an item that is a shell object, this method will defer to the **IPropertyStore** object provided by the item if the property hasn't been set or updated using [SetProperty](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoacquireitem-setproperty).

## See also

[IPhotoAcquireItem Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquireitem)

[SetProperty](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoacquireitem-setproperty)