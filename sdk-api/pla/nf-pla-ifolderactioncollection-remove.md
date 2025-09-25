# IFolderActionCollection::Remove

## Description

Removes a folder action from the collection based on the specified index.

## Parameters

### `Index` [in]

The zero-based index of the folder action to remove from the collection. The variant type can be VT_I4, VT_UI4, or VT_DISPATCH.

## Return value

Returns S_OK if successful.

## Remarks

If the variant type is VT_DISPATCH, pass the **IDispatch** interface of the [IFolderAction](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-ifolderaction) interface to be removed.

## See also

[IFolderActionCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-ifolderactioncollection)

[IFolderActionCollection::Add](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-ifolderactioncollection-add)

[IFolderActionCollection::Clear](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-ifolderactioncollection-clear)