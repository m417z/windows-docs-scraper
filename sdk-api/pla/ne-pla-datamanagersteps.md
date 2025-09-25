# DataManagerSteps enumeration

## Description

Defines the actions that the data manager takes when it runs.

## Constants

### `plaCreateReport:0x1`

Runs TraceRpt.exe using as input all the binary performance files (.blg) or event trace files (.etl) in the collection. You can use the [IDataManager::ReportSchema](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatamanager-get_reportschema) property to customize the report.

The [IDataManager::RuleTargetFileName](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatamanager-get_ruletargetfilename) property contains the name of the file that TraceRpt creates.

### `plaRunRules:0x2`

If a report exists, apply the rules specified in the [IDataManager::Rules](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatamanager-get_rules) property to the report.

The [RuleTargetFileName](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatamanager-get_ruletargetfilename) property contains the name of the file to which the rules are applied.

### `plaCreateHtml:0x4`

Converts the XML file specified in [RuleTargetFileName](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatamanager-get_ruletargetfilename) to HTML format. The HTML format is written to the file specified in the [IDataManager::ReportFileName](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatamanager-get_reportfilename) property.

### `plaFolderActions:0x8`

Apply the folder actions specified in the [IDataManager::FolderActions](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatamanager-get_folderactions) property to all folders defined in the collection.

### `plaResourceFreeing:0x10`

If the [IDataManager::MaxFolderCount](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatamanager-get_maxfoldercount), [IDataManager::MaxSize](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatamanager-get_maxsize), or [IDataManager::MinFreeDisk](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatamanager-get_minfreedisk) property exceeds its limit, apply the resource policy specified in the [IDataManager::ResourcePolicy](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatamanager-get_resourcepolicy) property.

## Remarks

Specify one or more actions. The data manager applies the actions in the order in which they are defined in this enumeration.

## See also

[IDataManager::Run](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatamanager-run)