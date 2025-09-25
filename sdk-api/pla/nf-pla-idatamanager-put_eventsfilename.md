# IDataManager::put_EventsFileName

## Description

Retrieves or sets the name for the events file.

This property is read/write.

## Parameters

## Remarks

PLA uses the file name only if you include the **plaCreateReport** value of the [DataManagerSteps](https://learn.microsoft.com/windows/win32/api/pla/ne-pla-datamanagersteps) enumeration in the *Steps* parameter of the [IDataManager::Run](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatamanager-run) method and if the data collection set contains trace data collectors.

## See also

[IDataManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-idatamanager)