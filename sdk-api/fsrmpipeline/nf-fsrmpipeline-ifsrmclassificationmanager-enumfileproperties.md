# IFsrmClassificationManager::EnumFileProperties

## Description

Enumerates the properties of the specified file.

## Parameters

### `filePath` [in]

The file that contains the properties that you want to enumerate. You must specify an absolute path to the
file. You cannot specify a file share.

### `options` [in]

The option to use for enumerating the file's properties. For possible values, see the
[FsrmGetFilePropertyOptions](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-fsrmgetfilepropertyoptions) enumeration.

### `fileProperties` [out]

An [IFsrmCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nn-fsrm-ifsrmcollection) interface that contains a
collection of file properties. Each item in the collection is a **VARIANT** of type
**VT_DISPATCH**. Query the **pdispVal** member of the variant for
the [IFsrmProperty](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmproperty) interface.

## Return value

The method returns the following return values.

## Remarks

FSRM asks the specified storage modules (see the *options* parameter) to return all
the properties for the file for which they are responsible. For storage modules that embed the properties in the
file, the list will include all properties embedded in the file (not just those defined by FSRM).

If the *options* parameter is set to
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

[IFsrmClassificationManager::GetFileProperty](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmclassificationmanager-getfileproperty)

[IFsrmClassificationManager::SetFileProperty](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmclassificationmanager-setfileproperty)

[MSFT_FSRMClassification](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmclassification)