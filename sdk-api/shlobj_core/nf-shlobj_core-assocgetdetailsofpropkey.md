# AssocGetDetailsOfPropKey function

## Description

Retrieves the value for a given property key using the file association information provided by the [Namespace Extensions](https://learn.microsoft.com/windows/desktop/shell/nse-works).

## Parameters

### `psf` [in]

Type: **[IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder)***

A pointer to the shell folder for which the details of the property key of the file association are being retrieved.

### `pidl` [in]

Type: **PCUITEMID_CHILD**

The PIDL of the child item for which the file associations are being requested.

### `pkey` [in]

Type: **[PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey)***

A pointer to the property key that is being retrieved.

### `pv` [out]

Type: **VARIANT***

When this function returns, contains the details of the given property key.

### `pfFoundPropKey` [out]

Type: **BOOL***

When this function returns, contains a flag that is **TRUE** if the property key was found, otherwise **FALSE**.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function is to be used only by implementers of
[IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder) [Namespace Extensions](https://learn.microsoft.com/windows/desktop/shell/nse-works). Other calling applications should use
[IShellFolder2::GetDetailsEx](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder2-getdetailsex) to get a value
for a [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey). This function is to be used by
implementers of **IShellFolder** Namespace Extensions.

The provided namespace extension must support the use of this API in one of the following three ways.

1. If the provided [Namespace Extensions](https://learn.microsoft.com/windows/desktop/shell/nse-works) supports retrieving an [IQueryAssociations](https://learn.microsoft.com/windows/desktop/api/shlwapi/nn-shlwapi-iqueryassociations) interface for the item by implementing [IShellFolder::GetUIObjectOf](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder-getuiobjectof)(..., **IID_IQueryAssociations**, ...), then **AssocGetDetailsOfPropKey** will use the provided file associations API to retrieve the value for the property key.
2. If the provided namespace extension returns **SFGAO_FILESYSTEM** for the item from [IShellFolder::GetAttributesOf](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder-getattributesof) and provides a parsing name for the item, then **AssocGetDetailsOfPropKey** will use the standard file system associations to retrieve the value for the property key.
3. If the provided namespace extension returns **SFGAO_FOLDER** | **SFGAO_BROWSABLE** for the item from [IShellFolder::GetAttributesOf](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder-getattributesof), then **AssocGetDetailsOfPropKey** will use the file association for folders (**ASSOCCLASS_FOLDER**) to retrieve the value for the property key.

If the ShellFolder being implemented contains items that are extensible through the file associations mechanism, then you can use this function to retrieve **PropertyKeys** that are declared for a given file association. For example, if a given Shell folder drives a details pane and you want the properties displayed in that pane to be governed by third party file name extensions, then you can use this function to return **PKEY_PropList_PreviewDetails**. This key has a value that is declared in the registry for that file name extension with a semicolon delimited list of properties. There is a list of file name extension defined properties in the registry. This list includes but is not limited to the following:

* **PKEY_PropList_PreviewDetails**
* **PKEY_PropList_PreviewTitle**
* **PKEY_PropList_FullDetails**
* **PKEY_PropList_TileInfo**
* **PKEY_PropList_ExtendedTileInfo**
* **PKEY_PropList_InfoTip**
* **PKEY_PropList_QuickTip**
* **PKEY_PropList_FileOperationPrompt**
* **PKEY_PropList_ConflictPrompt**
* **PKEY_PropList_SetDefaultsFor**
* **PKEY_PropList_NonPersonal**
* **PKEY_NewMenuPreferredTypes**
* **PKEY_NewMenuAllowedTypes**