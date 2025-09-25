# IFsrmClassifierModuleImplementation::DoesPropertyValueApply

## Description

Queries the classifier to find out whether the specified property value applies to the file most recently specified by the [IFsrmClassifierModuleImplementation::OnBeginFile](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmclassifiermoduleimplementation-onbeginfile) method.

## Parameters

### `property` [in]

Name of the property to query.

### `value` [in]

Value of the property to check in the query.

### `applyValue` [out]

Is **VARIANT_TRUE** if the property applies; otherwise, **VARIANT_FALSE**.

### `idRule` [in]

The identifier of the rule object associated with the property value being queried. This rule object is in the rule collection passed in by a previous call to the [IFsrmClassifierModuleImplementation::UseRulesAndDefinitions](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmclassifiermoduleimplementation-userulesanddefinitions) method. The rule object can also be obtained by using this identifier in a call to the [IFsrmCollection::GetById](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nf-fsrm-ifsrmcollection-getbyid) method on this collection.

### `idPropDef` [in]

The identifier of the property definition object that corresponds to the property being queried. This property definition object is in the property definition collection passed in by a previous call to the [IFsrmClassifierModuleImplementation::UseRulesAndDefinitions](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmclassifiermoduleimplementation-userulesanddefinitions) method. The property definition object can also be obtained by using this identifier in a call to the [IFsrmCollection::GetById](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nf-fsrm-ifsrmcollection-getbyid) method on this collection.

## Return value

The method returns the following return values. Implementers should return an **HRESULT** error code for any other errors.

## Remarks

This method is called if the [IFsrmClassifierModuleDefinition::NeedsExplicitValue](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmclassifiermoduledefinition-get_needsexplicitvalue) property of the classifier's module definition is **VARIANT_FALSE**.

The identifiers passed in the *idRule* and *idPropDef* parameters can be used by the classifier implementation to determine whether the property value applies to the file. For classifiers that require the associated rule and/or property definition to make the determination, it is suggested that implementers cache the corresponding collections passed to them during [IFsrmClassifierModuleImplementation::UseRulesAndDefinitions](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmclassifiermoduleimplementation-userulesanddefinitions).

If **FSRM_E_INCOMPATIBLE_FORMAT** or **FSRM_E_FILE_ENCRYPTED** is returned, FSRM will not indicate that the file has failed classification. If any other error value is returned, FSRM will indicate that the file has failed classification.

## See also

[IFsrmClassifierModuleImplementation](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmclassifiermoduleimplementation)