# SHGetTemporaryPropertyForItem function

## Description

Retrieves the temporary property for the given item. A temporary property is a read/write store that holds properties only for the lifetime of the [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) object, rather than being persisted back into the item.

## Parameters

### `psi` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

A pointer to the item for which the temporary property is to be retrieved.

### `propkey`

Type: **REFPROPERTYKEY**

The property key.

### `ppropvar` [out]

Type: **[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)***

A pointer to the temporary property for the item.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.