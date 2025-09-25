# IConfigurationDataCollector::get_SystemStateFile

## Description

Retrieves or sets the name of the file that contains the saved system state.

This property is read/write.

## Parameters

## Remarks

Do not include the path in the file name; the [IDataCollectorSet::RootPath](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_rootpath) and [IDataCollectorSet::Subdirectory](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_subdirectory) properties determine the path to the file.

If you do not specify the name of the file, the system state is not retrieved.

The state information is a snapshot of the Circular Kernel Context Logger. The context logger provides a snapshot of the current state of the computer. The file contains kernel events. You can use the TraceRpt.exe tool to decode the events.

## See also

[IConfigurationDataCollector](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-iconfigurationdatacollector)