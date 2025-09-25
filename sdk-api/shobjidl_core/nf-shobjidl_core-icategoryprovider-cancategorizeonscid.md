# ICategoryProvider::CanCategorizeOnSCID

## Description

Determines whether a column can be used as a category.

## Parameters

### `pscid` [in]

Type: **const [SHCOLUMNID](https://learn.microsoft.com/windows/desktop/shell/objects)***

A pointer to a [SHCOLUMNID](https://learn.microsoft.com/windows/desktop/shell/objects) structure that identifies the column. Valid only when S_OK is returned. The GUID contained in this structure is then passed to [ICategoryProvider::CreateCategory](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icategoryprovider-createcategory).

## Return value

Type: **HRESULT**

Returns S_OK if the column can be used as a category or S_FALSE if not.

## Remarks

When using the System Folder View Object in Category view (**Show in Groups**), the titles of columns for which this method returns S_OK appear in the upper portion of the **Arrange Icons By** submenu.