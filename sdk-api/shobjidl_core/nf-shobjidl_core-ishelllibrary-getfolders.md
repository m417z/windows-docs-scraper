# IShellLibrary::GetFolders

## Description

Gets the set of child folders that are contained in the library.

## Parameters

### `lff` [in]

Type: **[LIBRARYFOLDERFILTER](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-libraryfolderfilter)**

One of the following [LIBRARYFOLDERFILTER](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-libraryfolderfilter) values that determines the folders to get. These flags cannot be combined.

#### LFF_FORCEFILESYSTEM (1)

Get only file-system folders. File-system folders are folders that have the [SFGAO_FILESYSTEM](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder-getattributesof) attribute set.

#### LFF_STORAGEITEMS (2)

Get all folders that can be bound to [IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) objects. These folders are folders that have the [SFGAO_STORAGE](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder-getattributesof) or [SFGAO_FILESYSTEM](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder-getattributesof) attribute set.

#### LFF_ALLITEMS (3)

Get all folders in the library.

### `riid` [in]

Type: **REFIID**

A reference to the IID of the interface to get in *ppv*. This value is typically IID_IShellItemArray, but it can also be IID_IObjectCollection, IID_IObjectArray, or the IID of any other interface that is implemented by CShellItemArray.

### `ppv` [out]

Type: **void****

 A pointer to the interface requested in *riid*. If this call fails, this value is **NULL**.

## Return value

Type: **HRESULT**

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The call was successful and the specified folders were returned in *ppv*. |
| **S_FALSE** | The call was successful but not all specified folders were returned in *ppv*. |
| **E_** | This method can return other error values. |

## Remarks

This method gets an ordered list of folders. By default, this method only returns storage locations.

For best results, use the **IID_PPV_ARGS** macro, defined in Objbase.h, for the *riid* and *ppv* parameters. This macro provides the correct IID based on the interface pointed to by the value in *ppv*, which eliminates the possibility of a coding error.

## See also

[IObjectArray](https://learn.microsoft.com/windows/desktop/api/objectarray/nn-objectarray-iobjectarray)

[IObjectCollection](https://learn.microsoft.com/windows/desktop/api/objectarray/nn-objectarray-iobjectcollection)

[IShellItemArray](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitemarray)

[IShellLibrary](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllibrary)

[IShellLibrary::AddFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllibrary-addfolder)

[IShellLibrary::LoadLibraryFromItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllibrary-loadlibraryfromitem)

[IShellLibrary::LoadLibraryFromKnownFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllibrary-loadlibraryfromknownfolder)

[LIBRARYFOLDERFILTER](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-libraryfolderfilter)

[Library Description Schema](https://learn.microsoft.com/windows/desktop/shell/library-schema-entry)

[SFGAO](https://learn.microsoft.com/windows/desktop/shell/sfgao)

[SHAddFolderPathToLibrary](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shaddfolderpathtolibrary)

[SHLoadLibraryFromItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shloadlibraryfromitem)

[SHLoadLibraryFromKnownFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shloadlibraryfromknownfolder)

[SHLoadLibraryFromParsingName](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shloadlibraryfromparsingname)

[SHRemoveFolderPathFromLibrary](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shremovefolderpathfromlibrary)

[Windows Libraries](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd758096(v=vs.85))