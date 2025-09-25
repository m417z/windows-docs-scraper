# IDataManager::get_RuleTargetFileName

## Description

Retrieves or sets the name of the report file that the TraceRpt.exe application creates.

This property is read/write.

## Parameters

## Remarks

PLA uses the file name only if you include the **plaCreateReport** value of the [DataManagerSteps](https://learn.microsoft.com/windows/win32/api/pla/ne-pla-datamanagersteps) enumeration in the *Steps* parameter of the [IDataManager::Run](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatamanager-run) method.

To specify the contents of the report, use the [IDataManager::ReportSchema](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatamanager-get_reportschema) property. To modify the contents of the report after it has been created, use the [IDataManager::Rules](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatamanager-get_rules) property.

## See also

[IDataManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-idatamanager)