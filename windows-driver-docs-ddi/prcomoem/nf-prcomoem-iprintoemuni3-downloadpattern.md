# IPrintOemUni3::DownloadPattern

## Description

The `IPrintOemUni3::DownloadPattern` method downloads a pattern to a printer.

## Parameters

### `pdevobj`

A pointer to a [DEVOBJ](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_devobj) structure.

### `psoPattern`

A pointer to the [SURFOBJ](https://learn.microsoft.com/windows/win32/api/winddi/ns-winddi-surfobj) structure that contains the pattern to download.

### `lPatternID`

The ID of the pattern to download.

## Return value

If successful, this method should return S_OK. Otherwise, this method should return an appropriate value in the returned HRESULT.

## Remarks

This method is available in Windows Vista and later.

You should implement this method if you want your rendering plug-in, rather than Unidrv, to download a pattern. If implemented, this method is called by **DrvRealizeBrush** for raster-mode print jobs. This method is not called for vector-mode print jobs.

## See also

[DrvRealizeBrush](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvrealizebrush)

[IPrintOemUni3](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nn-prcomoem-iprintoemuni3)