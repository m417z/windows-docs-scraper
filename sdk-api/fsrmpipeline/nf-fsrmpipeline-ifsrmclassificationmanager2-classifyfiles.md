# IFsrmClassificationManager2::ClassifyFiles

## Description

This method is used to perform bulk enumeration, setting, and clearing of file
properties.

## Parameters

### `filePaths` [in]

A list of the file paths. The **SAFEARRAY** contains variants of type
**VT_BSTR**. For each item in the array, use the **bstrVal** member
to access the property name.

### `propertyNames` [in]

A list of the property names. The **SAFEARRAY** contains variants of type
**VT_BSTR**. For each item in the array, use the **bstrVal** member
to access the property name.

### `propertyValues` [in]

A list of the property values.

### `options` [in]

Options for the operation as enumerated by the
[FsrmGetFilePropertyOptions](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-fsrmgetfilepropertyoptions) enumeration. The
default value is **FsrmGetFilePropertyOptions_None**.

## Return value

The method returns the following return values.

## See also

[FsrmClassificationManager](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrmclassificationmanager)

[FsrmGetFilePropertyOptions](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-fsrmgetfilepropertyoptions)

[IFsrmClassificationManager2](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmclassificationmanager2)

[MSFT_FSRMClassification](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmclassification)