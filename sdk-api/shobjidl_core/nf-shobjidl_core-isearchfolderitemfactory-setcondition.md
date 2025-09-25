# ISearchFolderItemFactory::SetCondition

## Description

Sets the [ICondition](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition) of the search. When this method is not called, the resulting search will have no filters applied.

## Parameters

### `pCondition` [in]

Type: **[ICondition](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition)***

A pointer to an [ICondition](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition) interface.

## Return value

Type: **HRESULT**

Returns **S_OK** if successful, or an error value otherwise.

## See also

[ICondition::Clone](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nf-structuredquerycondition-icondition-clone)

[ISearchFolderItemFactory](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-isearchfolderitemfactory)