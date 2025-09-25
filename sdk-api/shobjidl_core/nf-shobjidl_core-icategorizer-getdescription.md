# ICategorizer::GetDescription

## Description

Gets the name of a categorizer, such as *Group By Device Type*, that can be displayed in the UI.

## Parameters

### `pszDesc` [out]

Type: **LPWSTR**

When this method returns, contains a pointer to a string of length *cch* that contains the categorizer name.

### `cch` [in]

Type: **UINT**

The number of characters in the *pszDesc* buffer.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

In the case of the system folder view object, if the description at *pszDesc* matches one of the category names listed in the folder's **Arrange Icons By** menu, a dot is placed by that name when the menu is displayed, either through the **View** menu or through the context menu.