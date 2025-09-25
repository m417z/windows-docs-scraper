# IFsrmClassificationManager::GetRule

## Description

[This method is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMClassification](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmclassification) class.]

Retrieves the specified rule.

## Parameters

### `ruleName` [in]

The name of the rule to retrieve. Must not exceed 100 characters in length.

### `ruleType` [in]

The type of the rule to retrieve. For possible types, see the
[FsrmRuleType](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-fsrmruletype) enumeration.

**Note** The **FsrmRuleType_Generic** type is not supported by this method.

### `Rule` [out]

An [IFsrmRule](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmrule) interface to the retrieved rule. Query the
**IFsrmRule** interface to get the interface for the specified
type. For example, if *ruleType* is
**FsrmRuleType_Classification**, query the
**IFsrmRule** interface for the
[IFsrmClassificationRule](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmclassificationrule) interface.

## Return value

The method returns the following return values.

## See also

[FsrmClassificationManager](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrmclassificationmanager)

[IFsrmClassificationManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmclassificationmanager)

[IFsrmClassificationManager2](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmclassificationmanager2)

[IFsrmClassificationManager::CreateRule](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmclassificationmanager-createrule)

[IFsrmClassificationManager::EnumRules](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmclassificationmanager-enumrules)

[MSFT_FSRMClassification](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmclassification)