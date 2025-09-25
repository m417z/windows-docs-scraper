# IFsrmClassificationManager::EnumRules

## Description

[This method is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMClassification](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmclassification) class.]

Enumerates the rules of the specified type.

## Parameters

### `ruleType` [in]

The type of rules to enumerate. For possible values, see the
[FsrmRuleType](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-fsrmruletype) enumeration.

**Note** The **FsrmRuleType_Generic** type is not a valid type for this method.

### `options` [in]

One or more options for enumerating the property definitions. For possible values, see the
[FsrmEnumOptions](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-fsrmenumoptions) enumeration.

**Note** The **FsrmEnumOptions_Asynchronous** option is not supported for this
method.

### `Rules` [out]

An [IFsrmCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nn-fsrm-ifsrmcollection) interface that contains a
collection of classification rules. Each item in the collection is a **VARIANT** of
type **VT_DISPATCH**. Query the **pdispVal** member of the variant
for the [IFsrmRule](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmrule) interface. You can then use the
[IFsrmRule.RuleType](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmrule-get_ruletype) property to determine the rule's
type. Query the **IFsrmRule** interface for the rule interface to
use. For example, if **RuleType** is
**FsrmRuleType_Classification**, query the
**IFsrmRule** interface for the
[IFsrmClassificationRule](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmclassificationrule) interface.

The collection contains only committed rules; the collection will not contain newly created rules that have
not been committed.

## Return value

The method returns the following return values.

## See also

[FsrmClassificationManager](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrmclassificationmanager)

[IFsrmClassificationManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmclassificationmanager)

[IFsrmClassificationManager2](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmclassificationmanager2)

[IFsrmClassificationManager::CreateRule](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmclassificationmanager-createrule)

[IFsrmClassificationManager::GetRule](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmclassificationmanager-getrule)

[MSFT_FSRMClassification](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmclassification)