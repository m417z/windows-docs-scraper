# IDataCollectorSet::get_Description

## Description

Retrieves or sets the description of the data collector set. The description will be added to all output files as metadata and inserted into Performance Data Helper logs as a comment.

This property is read/write.

## Parameters

## Remarks

To use a localized string from a binary, specify the description in the form @*binary*,#*id* where *binary* is the EXE or DLL that contains the localized resource string and *id* is the string resource identifier.

If you set the description to the @*binary*,#*id* form, when you retrieve the description you will receive the localized string. To retrieve the description string that you set, access the [IDataCollectorSet::DescriptionUnresolved](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_descriptionunresolved) property.

## See also

[IDataCollectorSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-idatacollectorset)

[IDataCollectorSet::DescriptionUnresolved](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_descriptionunresolved)