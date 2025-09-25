# _AUX_MODULE_EXTENDED_INFO structure

## Description

The **AUX_MODULE_EXTENDED_INFO** structure contains extended information about a loaded image module.

## Members

### `BasicInfo`

An [AUX_MODULE_BASIC_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/aux_klib/ns-aux_klib-_aux_module_basic_info) structure.

### `ImageSize`

The size, in bytes, of the loaded image.

### `FileNameOffset`

The offset, in bytes, from the beginning of the full path name to the file name of the module's image file.

### `FullPathName`

The full path name of the module's image file.

## Remarks

The **AUX_MODULE_EXTENDED_INFO** structure is used as input to the [AuxKlibQueryModuleInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/aux_klib/nf-aux_klib-auxklibquerymoduleinformation) routine.

## See also

[AuxKlibQueryModuleInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/aux_klib/nf-aux_klib-auxklibquerymoduleinformation)