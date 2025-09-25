# IFsrmClassificationManager::GetFileProperty

## Description

Retrieves the specified property from the file or folder.

**Windows Server 2008 R2:** Only files are supported until Windows Server 2012.

## Parameters

### `filePath` [in]

The file that contains the property that you want to retrieve. You must specify an absolute path to the
file. You cannot specify a file share.

### `propertyName` [in]

The name of the property to retrieve. Must not exceed 100 characters in length.

### `options` [in]

The option to use for retrieving the file's property. For possible values, see the
[FsrmGetFilePropertyOptions](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-fsrmgetfilepropertyoptions) enumeration.

### `property` [out]

An [IFsrmProperty](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmproperty) interface to the retrieved
property.

## Return value

The method returns the following return values.

## Remarks

FSRM asks the specified storage modules (see the *options* parameter) to retrieve the
property from the file. If the *options* parameter is set to
**FsrmGetFilePropertyOptions_None**, FSRM reruns classification on the file to ensure the
correct value is returned.

#### Examples

For examples in C# and PowerShell see
[Accessing Classification Properties](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/accessing-classification-properties).

## See also

[FsrmClassificationManager](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrmclassificationmanager)

[IFsrmClassificationManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmclassificationmanager)

[IFsrmClassificationManager2](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmclassificationmanager2)

[IFsrmClassificationManager::ClearFileProperty](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmclassificationmanager-clearfileproperty)

[IFsrmClassificationManager::EnumFileProperties](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmclassificationmanager-enumfileproperties)

[IFsrmClassificationManager::SetFileProperty](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmclassificationmanager-setfileproperty)

[MSFT_FSRMClassification](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmclassification)