# IFsrmFileScreenManager::CreateFileScreen

## Description

Creates a file screen object.

## Parameters

### `path` [in]

The local directory path to which the file screen applies. The string is limited to 260 characters.

### `fileScreen` [out]

An [IFsrmFileScreen](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmscreen/nn-fsrmscreen-ifsrmfilescreen) interface of the newly created file screen. To add the file screen to FSRM, call the [IFsrmFileScreen::Commit](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nf-fsrm-ifsrmobject-commit) method.

## Return value

The method returns the following return values.

## Remarks

The screen applies to the directory and all its subdirectories (recursively). For example, a screen on P:\*directory* that blocks *.mp3 also blocks MP3 files on P:\*directory*\*subdirectory*.

If you create a file screen on P:\*directory*\*subdirectory*, the screen that you created on P:\*directory* still applies to P:\*directory*\*subdirectory*. If you do not want the screen on P:\*directory* to apply to P:\*directory*\*subdirectory*, you need to create a [file screen exception](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmscreen/nf-fsrmscreen-ifsrmfilescreenmanager-createfilescreenexception).

#### Examples

For an example, see [Defining a File Screen](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/defining-a-file-screen).

## See also

[FsrmFileScreenManager](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrmfilescreenmanager)

[IFsrmFileScreenManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmscreen/nn-fsrmscreen-ifsrmfilescreenmanager)