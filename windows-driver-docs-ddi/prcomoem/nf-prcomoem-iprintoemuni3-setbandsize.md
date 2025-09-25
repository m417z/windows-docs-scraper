# IPrintOemUni3::SetBandSize

## Description

The `IPrintOemUni3::SetBandSize` method can be used with Unidrv-supported printers to specify the desired band size on the printed output.

## Parameters

### `pdevobj` [in]

A caller-supplied pointer to a [DEVOBJ](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_devobj) structure.

### `iFormat` [in]

An integer value that specifies the format of the bitmap in terms of the number of bits of color information per pixel that are required. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **BMF_1BPP** | Monochrome |
| **BMF_4BPP** | 4 bits per pixel |
| **BMF_8BPP** | 8 bits per pixel |
| **BMF_16BPP** | 16 bits per pixel |
| **BMF_24BPP** | 24 bits per pixel |
| **BMF_32BPP** | 32 bits per pixel |
| **BMF_4RLE** | 4 bits per pixel; run length encoded |
| **BMF_8RLE** | 8 bits per pixel; run length encoded |

### `dwPageWidthBytes` [in]

A Unidrv-supplied value that specifies the width of the printing area, in bytes.

### `dwPageHeight` [in]

A Unidrv-supplied value that specifies the height of the printing area, in pixels.

### `dwMaxHeight` [in]

A Unidrv-supplied value that specifies the maximum allowable height of the printing area, in pixels.

### `pdwRequiredHeight` [in]

A caller-supplied pointer to a DWORD that contains the height of the printing area, in pixels, required by the rendering plug-in.

## Return value

The method must return one of the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | The operation succeeded. See Note. |
| **E_FAIL** | The operation failed. See Note. |
| **E_NOTIMPL** | Unidrv should compute the banding size. |

## Remarks

This method is available in Windows Vista and later.

This method is used by a rendering plug-in to specify band size using the plug-in's own calculations, rather than using Unidrv's band size calculations.

You can disable banding operations by Unidrv by setting the *dwPageHeight* value to **pdwRequiredHeight*, but you should consider the performance effect of the height value that the rendering plug-in requests. For rendering, Unidrv needs at least the amount of memory that is calculated by multiplying *dwPageWidthBytes* by **pdwRequiredHeight*. If the rendering plug-in supports the [IPrintOemUni::DriverDMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemuni-driverdms) method and that method returns "S_OK", `IPrintOemUni3::SetBandSize` is not called.

If this method is defined and the printer's generic printer description (GPD) file indicates that preanalysis is disabled (the GPD file includes "***PreAnalysisOptions**: 0"), Unidrv calls this method to calculate band size. For information about the **PreAnalysisOptions** attribute, see [Preanalysis Infrastructure](https://learn.microsoft.com/windows-hardware/drivers/print/preanalysis-infrastructure).

If the rendering plug-in supports [IPrintOemUni::DriverDMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemuni-driverdms) and that method returns S_OK, `IPrintOemUni3::SetBandSize` is not called.