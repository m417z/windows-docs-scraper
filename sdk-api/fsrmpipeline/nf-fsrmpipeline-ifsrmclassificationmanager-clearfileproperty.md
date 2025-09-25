# IFsrmClassificationManager::ClearFileProperty

## Description

Attempts to remove the specified property from the file or folder.

**Windows Server 2008 R2:** Only files are supported until Windows Server 2012.

## Parameters

### `filePath` [in]

The file that contains the property that you want to remove. You must specify an absolute path to the file.
You cannot specify a file share.

### `property` [in]

The name of the property to remove from the file.

## Return value

The method returns the following return values.

## Remarks

The property is removed from the file if the storage module is able to remove the property; otherwise, the
property's value is cleared using the values in the following list.

| Property type | Cleared value |
| --- | --- |
| Boolean |  |
| Date |  |
| Hierarchy |  |
| Integer |  |
| Multiple choice list |  |
| Single choice list |  |
| Multi-string |  |
| Ordered list |  |
| String | Empty string |

## See also

[FsrmClassificationManager](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrmclassificationmanager)

[IFsrmClassificationManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmclassificationmanager)

[IFsrmClassificationManager2](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmclassificationmanager2)

[IFsrmClassificationManager::GetFileProperty](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmclassificationmanager-getfileproperty)

[IFsrmClassificationManager::SetFileProperty](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmclassificationmanager-setfileproperty)

[MSFT_FSRMClassification](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmclassification)