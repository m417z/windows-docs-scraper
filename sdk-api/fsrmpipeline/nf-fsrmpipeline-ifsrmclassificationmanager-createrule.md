# IFsrmClassificationManager::CreateRule

## Description

[This method is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMClassification](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmclassification) class.]

Creates a rule of the specified type.

## Parameters

### `ruleType` [in]

The type of rule to create, set this parameter to **FsrmRuleType_Classification**.
For more information, see [FsrmRuleType](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-fsrmruletype).

### `Rule` [out]

An [IFsrmRule](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmrule) interface to the new rule. Query the
**IFsrmRule** interface to get the interface to get the
[IFsrmClassificationRule](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmclassificationrule) interface.

To save the rule, call [IFsrmRule::Commit](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nf-fsrm-ifsrmobject-commit)
method.

## Return value

The method returns the following return values.

## Remarks

There is no limit to the number of rules that you can create. Use the
[IFsrmRule.ModuleDefinitionName](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmrule-get_moduledefinitionname) property
to associate the rule with a classification module.

FSRM cannot guarantee the order in which the rules
are run.

## See also

[FsrmClassificationManager](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrmclassificationmanager)

[IFsrmClassificationManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmclassificationmanager)

[IFsrmClassificationManager2](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmclassificationmanager2)

[IFsrmClassificationManager::EnumRules](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmclassificationmanager-enumrules)

[IFsrmClassificationManager::GetRule](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmclassificationmanager-getrule)

[MSFT_FSRMClassification](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmclassification)