# ISearchFolderItemFactory::SetStacks

## Description

Creates a list of stack keys, as specified. If this method is not called, by default the folder will not be stacked.

## Parameters

### `cStackKeys` [in]

Type: **UINT**

The number of stacks keys.

### `rgStackKeys` [in]

Type: **[PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey)***

A pointer to an array of [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey) structures containing stack key information.

## Return value

Type: **HRESULT**

Returns a success value if successful, or an error value otherwise.