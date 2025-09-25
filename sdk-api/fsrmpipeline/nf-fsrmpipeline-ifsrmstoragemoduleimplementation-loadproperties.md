# IFsrmStorageModuleImplementation::LoadProperties

## Description

Instructs the storage module to load all properties.

## Parameters

### `propertyBag` [in]

Specifies the properties to load.

## Return value

The method returns the following return values. Implementers should return an HRESULT error code for any other errors.

## Remarks

The storage module must call the [IFsrmPropertyBag::SetFileProperty](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmpropertybag-setfileproperty) method on the property bag that is passed in for each property it chooses to set.

If **FSRM_E_INCOMPATIBLE_FORMAT** or **FSRM_E_FILE_ENCRYPTED** is returned, FSRM will not indicate that the file has failed classification. If any other error value is returned, FSRM will indicate that the file has failed classification.

## See also

[IFsrmStorageModuleImplementation](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmstoragemoduleimplementation)