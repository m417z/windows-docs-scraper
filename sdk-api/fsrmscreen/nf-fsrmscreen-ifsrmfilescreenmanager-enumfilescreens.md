# IFsrmFileScreenManager::EnumFileScreens

## Description

Enumerates the file screens for the specified directory and its subdirectories.

## Parameters

### `path` [in]

The local directory path associated with the file screen that you want to retrieve.

If the path ends with "\*", retrieve all file screens associated with the immediate subdirectories of the path (does not include the file screen associated with the path).

If the path ends with "\...", retrieve the file screen for the path and all file screens associated with the immediate subdirectories of the path (recursively).

If the path does not end in "\*" or "\...", retrieve the file screen for the path only.

If path is null or empty, the method returns all file screens.

### `options` [in]

The options to use when enumerating the file screens. For possible values, see the [FsrmEnumOptions](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-fsrmenumoptions) enumeration.

### `fileScreens` [out]

An [IFsrmCommittableCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nn-fsrm-ifsrmcommittablecollection) interface that contains a collection of file screens.

Each item of the collection is a **VARIANT** of type **VT_DISPATCH**. Query the **pdispVal** member of the variant for the [IFsrmFileScreen](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmscreen/nn-fsrmscreen-ifsrmfilescreen) interface.

The collection contains only committed file screens; the collection will not contain newly created file screens that have not been committed.

The collection is empty if the path does not contain file screens.

## Return value

The method returns the following return values.

## See also

[FsrmFileScreenManager](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrmfilescreenmanager)

[IFsrmFileScreenManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmscreen/nn-fsrmscreen-ifsrmfilescreenmanager)