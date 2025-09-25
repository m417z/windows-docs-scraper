# IFsrmClassificationManager::SetFileProperty

## Description

Sets the value of the specified property in the file or folder.

**Windows Server 2008 R2:** Only files are supported until Windows Server 2012.

## Parameters

### `filePath` [in]

The file that contains the property that you want to set. You must specify an absolute path to the file. You
cannot specify a file share.

### `propertyName` [in]

The name of the property whose value you want to set.

### `propertyValue` [in]

The value to set the specified property to.

## Return value

The method returns the following return values.

## Remarks

The method verifies that the property value is valid for the property's type. For example, for an ordered or
multiple choice list, that the value is a member of the list; for a Boolean property, that the value is the string
"0" or "1"; and for a date, that the value is a 64-bit decimal value expressed
as a string.

**SetFileProperty** only
supports property definitions that are available on the server whose
[AppliesTo](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmpropertydefinition2-get_appliesto) property has the
**FsrmPropertyDefinitionAppliesTo_Files** (1) bit set.

#### Examples

For examples in C# and PowerShell see
[Accessing Classification Properties](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/accessing-classification-properties).

## See also

[FsrmClassificationManager](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrmclassificationmanager)

[IFsrmClassificationManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmclassificationmanager)

[IFsrmClassificationManager2](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmclassificationmanager2)

[IFsrmClassificationManager::ClearFileProperty](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmclassificationmanager-clearfileproperty)

[IFsrmClassificationManager::EnumFileProperties](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmclassificationmanager-enumfileproperties)

[IFsrmClassificationManager::GetFileProperty](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmclassificationmanager-getfileproperty)

[MSFT_FSRMClassification](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmclassification)