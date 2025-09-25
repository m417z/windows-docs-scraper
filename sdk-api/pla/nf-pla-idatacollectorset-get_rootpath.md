# IDataCollectorSet::get_RootPath

## Description

Retrieves or sets the base path where the subdirectories are created.

**Warning** If you change the **RootPath** property, you should change it to a directory that only contains performance logs. Setting this to another directory, such as the drive root or system root, may cause files to be inadvertently deleted when the logs are cleaned up by the system.

This property is read/write.

## Parameters

## Remarks

If this property is changed from the default value, the specified directory must exist before the [IDataCollectorSet::Start](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-start) method is called.

## See also

[IDataCollectorSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-idatacollectorset)

[IDataCollectorSet::LatestOutputLocation](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_latestoutputlocation)

[IDataCollectorSet::OutputLocation](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_outputlocation)

[IDataCollectorSet::Subdirectory](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_subdirectory)