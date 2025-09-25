# IPrintOemPS2::GetPDEVAdjustment

## Description

The `IPrintOemPS2::GetPDEVAdjustment` method enables a plug-in to override specific [PDEV](https://learn.microsoft.com/windows-hardware/drivers/) settings.

## Parameters

### `pdevobj`

Pointer to a [DEVOBJ](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_devobj) structure.

### `dwAdjustType`

Specifies the type of adjustment asked for. The following flags are currently supported:

| Flag | Meaning |
| --- | --- |
| PDEV_ADJUST_PAPER_MARGIN_TYPE | Adjust the paper margin setting that is reported in the PDEV. See the [PDEV_ADJUST_PAPER_MARGIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_pdev_adjust_paper_margin) structure. |
| PDEV_HOSTFONT_ENABLED_TYPE | Enable or disable the Hostfont support feature. See the [PDEV_HOSTFONT_ENABLED](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_pdev_hostfont_enabled) structure. |
| PDEV_USE_TRUE_COLOR_TYPE | Enable or disable color output for monochrome and color printers. See the [PDEV_USE_TRUE_COLOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_pdev_use_true_color) structure. |

### `pBuf`

Pointer to a structure that contains the planned settings that are used if there is no change. These structures are listed in the preceding table. The plug-in can overwrite the settings in the relevant structure.

### `cbBuffer`

Specifies the size, in bytes, of the structure pointed to by *pBuf*.

### `pbAdjustmentDone` [out]

Pointer to a memory location that the plug-in sets to **TRUE** when it actually changes a value in the buffer. This may be used by the driver for optimizations.

## Return value

The `IPrintOemPS2::GetPDEVAdjustment` method should return S_OK if it recognizes the adjustment type, and S_FALSE if it does not. If the method fails, it should return E_FAIL. The chain of plug-ins is called until either S_OK or a failure code other than E_NOTIMPL is returned. That is, the chain of plug-ins is called until the first plug-in that is capable of handling the adjustment is found.

## Remarks

This function is available in Windows XP and later.

Currently, the Pscript5 driver calls `IPrintOemPS2::GetPDEVAdjustment` to adjust the paper margin setting, as reported in the PDEV, to enable or disable the Hostfont feature, or to turn PostScript color output on or off.

## See also

[IPrintOemPS2](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nn-prcomoem-iprintoemps2)

[PDEV_ADJUST_PAPER_MARGIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_pdev_adjust_paper_margin)

[PDEV_HOSTFONT_ENABLED](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_pdev_hostfont_enabled)

[PDEV_USE_TRUE_COLOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_pdev_use_true_color)