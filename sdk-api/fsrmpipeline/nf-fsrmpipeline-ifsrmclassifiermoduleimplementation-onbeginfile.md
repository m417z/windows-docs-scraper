# IFsrmClassifierModuleImplementation::OnBeginFile

## Description

Instructs the classifier to prepare for processing a file with the specified property bag.

## Parameters

### `propertyBag` [in]

The property bag that corresponds to the file to be processed.

### `arrayRuleIds` [in]

A **SAFEARRAY** of variants that contains one or more strings listing the identifiers of rules that will be processed. Each identifier corresponds to a rule object that is in the rule collection passed in by a previous call to the [IFsrmClassifierModuleImplementation::UseRulesAndDefinitions](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmclassifiermoduleimplementation-userulesanddefinitions) method. The rule object can also be obtained by using this identifier in a call to the [IFsrmCollection::GetById](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nf-fsrm-ifsrmcollection-getbyid) method on this collection.

## Return value

The method returns the following return values. Implementers should return an **HRESULT** error code for any other errors.

## Remarks

The classifier is not allowed to directly call [IFsrmPropertyBag::SetFileProperty](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmpropertybag-setfileproperty) on the property bag that is passed in. The classifier instead provides property values when the [IFsrmClassifierModuleImplementation::DoesPropertyValueApply](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmclassifiermoduleimplementation-doespropertyvalueapply) method or the [IFsrmClassifierModuleImplementation::GetPropertyValueToApply](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmclassifiermoduleimplementation-getpropertyvaluetoapply) method is called by FSRM.

Each of the calls to the [IFsrmClassifierModuleImplementation::DoesPropertyValueApply](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmclassifiermoduleimplementation-doespropertyvalueapply) method or the [IFsrmClassifierModuleImplementation::GetPropertyValueToApply](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmclassifiermoduleimplementation-getpropertyvaluetoapply) method is associated with a rule, the identifiers of which are passed in through the *arrayRuleIds* parameter. As an optimization, the classifier may optionally pre-compute the responses for the **IFsrmClassifierModuleImplementation::DoesPropertyValueApply** method or the **IFsrmClassifierModuleImplementation::GetPropertyValueToApply** method during the **OnBeginFile** method call using the rule identifiers passed in through the *arrayRuleIds* parameter.

If **FSRM_E_INCOMPATIBLE_FORMAT** or **FSRM_E_FILE_ENCRYPTED** is returned, FSRM will not indicate that the file has failed classification. If any other error value is returned, FSRM will indicate that the file has failed classification.

## See also

[IFsrmClassifierModuleImplementation](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmclassifiermoduleimplementation)