# IDataCollectorSet::put_Subdirectory

## Description

Retrieves or sets a base subdirectory of the root path where the next instance of the data collector set will write its logs.

This property is read/write.

## Parameters

## Remarks

The actual name of the subdirectory used can be different if you had previously specified formatting options in the [IDataCollectorSet::SubdirectoryFormat](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_subdirectoryformat) property. The [IDataCollectorSet::LatestOutputLocation](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_latestoutputlocation) property contains the actual folder name used.

If a location is not specified, files are written to the path specified in the [IDataCollectorSet::RootPath](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_rootpath) property.

PLA creates the folders in the subdirectory path if they do not exist. Note that the folders will not inherit the ACLs from the root path. The user specified in the [IDataCollectorSet::UserAccount](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_useraccount) property and those in the Administrators group will have read and write access to the folders. Users in the Performance Log Users group and Performance Monitor Users group have read-only access.

## See also

[IDataCollectorSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-idatacollectorset)

[IDataCollectorSet::LatestOutputLocation](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_latestoutputlocation)

[IDataCollectorSet::OutputLocation](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_outputlocation)

[IDataCollectorSet::RootPath](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_rootpath)

[IDataCollectorSet::SubdirectoryFormat](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_subdirectoryformat)

[IDataCollectorSet::SubdirectoryFormatPattern](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_subdirectoryformatpattern)