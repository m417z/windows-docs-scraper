# IFsrmStorageModuleImplementation::SaveProperties

## Description

Instructs the storage module to save properties associated with a file.

## Parameters

### `propertyBag` [in]

Specifies the location to save properties.

## Return value

The method returns the following return values. Implementers should return an HRESULT error code for any other errors.

## Remarks

If **FSRM_E_INCOMPATIBLE_FORMAT** or **FSRM_E_FILE_ENCRYPTED** is returned, FSRM will not indicate that the file has failed classification. If any other error value is returned, FSRM will indicate that the file has failed classification.

## See also

[IFsrmStorageModuleImplementation](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmstoragemoduleimplementation)