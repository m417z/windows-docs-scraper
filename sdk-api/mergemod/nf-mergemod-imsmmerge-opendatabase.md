# IMsmMerge::OpenDatabase

## Description

The
**OpenDatabase** method opens a Windows Installer installation database, located at a specified path, that is to be merged with a module. For more information, see the
[OpenDatabase](https://learn.microsoft.com/windows/desktop/Msi/merge-opendatabase) method of the
[Merge](https://learn.microsoft.com/windows/desktop/Msi/merge-object) object.

**IMsmMerge2::OpenDatabase** Mergemod.dll version 2.0 and later.**IMsmMerge::OpenDatabase** All Mergemod.dll versions.

## Parameters

### `Path`

Path to the database being opened.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **E_FAIL** | There was an error opening the database. |
| **S_OK** | The function succeeded. |

## See also

[Merge Module Automation](https://learn.microsoft.com/windows/desktop/Msi/merge-module-automation)