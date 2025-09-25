# IFsrmClassifierModuleImplementation::UseRulesAndDefinitions

## Description

Specifies the collection of rules and relevant property definitions the classifier should expect to
process.

## Parameters

### `rules` [in]

Type: **[IFsrmCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nn-fsrm-ifsrmcollection)***

An [IFsrmCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nn-fsrm-ifsrmcollection) instance representing a collection
of rules that will be used during the current classification session.

### `propertyDefinitions` [in]

Type: **[IFsrmCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nn-fsrm-ifsrmcollection)***

An [IFsrmCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nn-fsrm-ifsrmcollection) instance representing a collection
of property definitions that are referenced by the specified collection of rules.

## Return value

Type: **HRESULT**

The method returns the following return values.

Other values will result in the client application receiving a
**FSRM_E_MODULE_SESSION_INITIALIZATION** error.

**Windows Server 2008 R2:** The client application will receive a **FSRM_E_UNEXPECTED** error.

## See also

[IFsrmClassifierModuleImplementation](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmclassifiermoduleimplementation)

[IFsrmCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nn-fsrm-ifsrmcollection)