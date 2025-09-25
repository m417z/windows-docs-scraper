# IFsrmFileScreenManager::EnumFileScreenExceptions

## Description

Enumerates the file screen exceptions for the specified directory and its subdirectories.

## Parameters

### `path` [in]

The local directory path associated with the file screen exception that you want to retrieve.

If the path ends with "\*", retrieve all exceptions associated with the immediate subdirectories of the path (does not include the exceptions associated with the path).

If the path ends with "\...", retrieve the exception for the path and all exceptions associated with the immediate subdirectories of the path (recursively).

If the path does not end in "\*" or "\...", retrieve the exception for the path only.

If path is null or empty, the method returns all file screen exceptions.

### `options` [in]

The options to use when enumerating the exceptions. For possible values, see the [FsrmEnumOptions](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-fsrmenumoptions) enumeration.

### `fileScreenExceptions` [out]

An [IFsrmCommittableCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nn-fsrm-ifsrmcommittablecollection) interface that contains a collection of file screen exceptions.

Each item of the collection is a **VARIANT** of type **VT_DISPATCH**. Query the **pdispVal** member of the variant for the [IFsrmFileScreenException](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmscreen/nn-fsrmscreen-ifsrmfilescreenexception) interface.

The collection contains only committed exceptions; the collection will not contain newly created exceptions that have not been committed.

The collection is empty if the path does not contain file screen exceptions.

## Return value

The method returns the following return values.

## See also

[FsrmFileScreenManager](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrmfilescreenmanager)

[IFsrmFileScreenManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmscreen/nn-fsrmscreen-ifsrmfilescreenmanager)