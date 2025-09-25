# ICategoryProvider::EnumCategories

## Description

Gets the enumerator for the list of GUIDs that represent categories.

## Parameters

### `penum` [out]

Type: **IEnumGUID****

When this method returns, contains the address of a pointer to an **IEnumGUID** interface that specifies a list of GUIDs that represent categories.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

In the case of the system folder view object, **ICategoryProvider::EnumCategories** is used to obtain additional categories that are not associated with a column. When the list of category GUIDs is returned through *penum*, the UI attempts to retrieve the name of each category. That name is then displayed as a category choice. In the case of Windows XP, that choice appears in the folder's **Arrange Icons By** menu.