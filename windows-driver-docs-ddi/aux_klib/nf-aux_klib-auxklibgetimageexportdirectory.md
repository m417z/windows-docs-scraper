# AuxKlibGetImageExportDirectory function

## Description

The **AuxKlibGetImageExportDirectory** routine returns an image module's export directory.

## Parameters

### `ImageBase` [in]

A pointer to the base of an image, which is obtained by calling [AuxKlibQueryModuleInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/aux_klib/nf-aux_klib-auxklibquerymoduleinformation).

## Return value

**AuxKlibGetImageExportDirectory** returns a pointer to an **IMAGE_EXPORT_DIRECTORY** structure. This structure is defined in Ntimage.h, which is included in the Microsoft Windows Driver Kit (WDK).

## Remarks

Drivers must call [AuxKlibInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/aux_klib/nf-aux_klib-auxklibinitialize) before calling **AuxKlibGetImageExportDirectory**.

## See also

[AuxKlibQueryModuleInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/aux_klib/nf-aux_klib-auxklibquerymoduleinformation)