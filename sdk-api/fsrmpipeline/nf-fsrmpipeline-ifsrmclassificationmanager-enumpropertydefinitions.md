# IFsrmClassificationManager::EnumPropertyDefinitions

## Description

[This method is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMClassification](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmclassification) class.]

Enumerates the property definitions.

## Parameters

### `options` [in]

One or more options for enumerating the property definitions. For possible values, see the
[FsrmEnumOptions](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-fsrmenumoptions) enumeration.

### `propertyDefinitions` [out]

An [IFsrmCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nn-fsrm-ifsrmcollection) interface that contains a
collection of property definitions. Each item in the collection is a **VARIANT** of
type **VT_DISPATCH**. Query the **pdispVal** member of the
variant for the [IFsrmPropertyDefinition](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmpropertydefinition)
interface.

The collection contains only committed property definitions; the collection will not contain newly created
property definitions that have not been committed.

## Return value

The method returns the following return values.

## See also

[FsrmClassificationManager](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrmclassificationmanager)

[IFsrmClassificationManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmclassificationmanager)

[IFsrmClassificationManager2](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmclassificationmanager2)

[IFsrmClassificationManager::CreatePropertyDefinition](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmclassificationmanager-createpropertydefinition)

[IFsrmClassificationManager::GetPropertyDefinition](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmclassificationmanager-getpropertydefinition)

[MSFT_FSRMClassification](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmclassification)