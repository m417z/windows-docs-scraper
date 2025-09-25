# IDataCollectorSet::put_DisplayName

## Description

Retrieves or sets the display name of the data collector set.

This property is read/write.

## Parameters

## Remarks

To use a localized string from a binary, specify the display name in the form @*binary*,#*id* where *binary* is the EXE or DLL that contains the localized resource string and *id* is the string resource identifier.

If you set the display name to the @*binary*,#*id* form, when you retrieve the display name you will receive the localized string. To retrieve the display name string that you set, access the [IDataCollectorSet::DisplayNameUnresolved](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_displaynameunresolved) property.

## See also

[IDataCollectorSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-idatacollectorset)

[IDataCollectorSet::DisplayNameUnresolved](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_displaynameunresolved)