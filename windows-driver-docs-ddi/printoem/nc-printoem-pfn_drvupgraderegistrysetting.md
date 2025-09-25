## Description

The **DrvUpgradeRegistrySetting** function is obsolete.

 Windows 2000 and later UI plug-ins should use [IPrintOemDriverUI::DrvUpgradeRegistrySetting](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemdriverui-drvupgraderegistrysetting) or [IPrintCoreUI2::DrvUpgradeRegistrySetting](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintcoreui2-drvupgraderegistrysetting).

This function pointer prototype defines the type of the *pfnUpgrade* parameter of the [OEMUpgradeRegistry](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/nf-printoem-oemupgraderegistry) function.

## Parameters

### `hPrinter`

Defines the **HANDLE** parameter *hPrinter*.

### `pFeature`

Defines the **PCSTR** parameter *pFeature*.

### `pOption`

Defines the **PCSTR** parameter *pOption*.

## Return value

Returns a **BOOL** value.