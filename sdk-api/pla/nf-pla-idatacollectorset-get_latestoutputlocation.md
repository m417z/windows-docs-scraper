# IDataCollectorSet::get_LatestOutputLocation

## Description

Retrieves or sets the fully decorated folder name that PLA used the last time logs were written.

This property is read/write.

## Parameters

## Remarks

Typically, you do not set this property. When the data collector starts, PLA sets this property using the value from the [IDataCollectorSet::OutputLocation](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_outputlocation) property.

You can set this property to empty if the folder has been deleted.

## See also

[IDataCollectorSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-idatacollectorset)

[IDataCollectorSet::OutputLocation](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_outputlocation)

[IDataCollectorSet::RootPath](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_rootpath)

[IDataCollectorSet::Subdirectory](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_subdirectory)