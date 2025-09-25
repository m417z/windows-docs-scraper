# IFsrmFileScreenManager::CreateFileScreenException

## Description

Creates a file screen exception object.

## Parameters

### `path` [in]

The local directory path to which the file screen exception applies. The path is limited to 260 characters.

### `fileScreenException` [out]

An [IFsrmFileScreenException](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmscreen/nn-fsrmscreen-ifsrmfilescreenexception) interface of the newly created file screen exception. To add the exception to FSRM, call [IFsrmFileScreenException::Commit](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nf-fsrm-ifsrmobject-commit) method.

## Return value

The method returns the following return values.

## Remarks

You can use the exception to allow files to be saved in a directory when a file screen would otherwise prevent it. For example, if P:\*directory* contains a file screen that blocks *.mp3, you could create an exception that allows MP3 files on P:\*directory*\*subdirectory*.

#### Examples

For an example, see [Defining a File Screen Exception](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/defining-a-file-screen-exception).

## See also

[FsrmFileScreenManager](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrmfilescreenmanager)

[IFsrmFileScreenManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmscreen/nn-fsrmscreen-ifsrmfilescreenmanager)