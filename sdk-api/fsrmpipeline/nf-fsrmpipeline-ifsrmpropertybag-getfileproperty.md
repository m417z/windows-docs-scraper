# IFsrmPropertyBag::GetFileProperty

## Description

Retrieves the specified property from the property bag.

## Parameters

### `name` [in]

The name of the property to retrieve.

### `fileProperty` [out]

An [IFsrmProperty](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmproperty) interface to the retrieved property.

## Return value

The method returns the following return values.

## Remarks

Use the property name specified in the rule's [PropertyAffected](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmclassificationrule-get_propertyaffected) property.

## See also

[IFsrmPropertyBag](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmpropertybag)

[IFsrmPropertyBag::SetFileProperty](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmpropertybag-setfileproperty)