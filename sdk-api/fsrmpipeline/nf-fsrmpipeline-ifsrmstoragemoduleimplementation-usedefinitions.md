# IFsrmStorageModuleImplementation::UseDefinitions

## Description

Specifies the property definitions FSRM recognizes.

## Parameters

### `propertyDefinitions` [in]

Collection of property definitions that are currently defined by FSRM.

## Return value

The method returns the following return values.

Other values will result in the client application receiving a
**FSRM_E_MODULE_SESSION_INITIALIZATION** error.

**Windows Server 2008 R2:** The client application will receive a **FSRM_E_UNEXPECTED** error.

## Remarks

The storage module may optionally use the collection of property definitions when determining how to load and
save particular properties as appropriate.

## See also

[IFsrmStorageModuleImplementation](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmstoragemoduleimplementation)