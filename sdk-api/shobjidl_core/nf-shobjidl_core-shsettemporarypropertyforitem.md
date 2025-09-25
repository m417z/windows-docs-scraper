# SHSetTemporaryPropertyForItem function

## Description

Sets a temporary property for the specified item. A temporary property is kept in a read/write store that holds properties only for the lifetime of the [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) object, instead of writing them back into the item.

## Parameters

### `psi` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

A pointer to the item on which the temporary property is to be set.

### `propkey` [in]

Type: **REFPROPERTYKEY**

Reference to the [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey) that identifies the temporary property that is being set.

### `propvar` [in]

Type: **REFPROPVARIANT**

Reference to a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) that contains the value of the temporary property.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

A temporary value can only be read with [SHGetTemporaryPropertyForItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shgettemporarypropertyforitem) or by passing GPS_TEMPORARY to [IShellItem2::GetPropertyStore](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellitem2-getpropertystore).