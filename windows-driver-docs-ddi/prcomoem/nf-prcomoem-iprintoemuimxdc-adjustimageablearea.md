# IPrintOemUIMXDC::AdjustImageableArea

## Description

The `IPrintOemUIMXDC::AdjustImageableArea` method enables an XPS filter pipeline driver to use UnidrvUI.dll or PS5UI.dll to support configuration of the printable area, including orientation and direction of rotation.

## Parameters

### `hPrinter`

A handle to the printer that is currently being queried.

### `cbDevMode`

The size of the [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew) structure, in bytes, including appended data.

### `pDevMode`

A pointer to the DEVMODE structure that contains the current device settings.

### `cbOEMDM`

The number of bytes in the vendor-provided section of the DEVMODE structure.

### `pOEMDM`

A pointer to the data that is contained in the vendor portion of the DEVMODE structure that *pDevMode* points to.

### `prclImageableArea`

A pointer to a [RECTL](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rectl) structure that contains the printable area. This parameter is populated by UnidrvUI.dll or PS5UI.dll with data from the corresponding GPD or PPD, before the parameter is passed to the plug-in. The plug-in can then update this data before returning.

## Return value

`AdjustImageableArea` returns S_OK if this method succeeds. Otherwise, this method should return E_NOTIMPL if the plug-in does not support the method, or any appropriate failure value if the plug-in cannot complete the operation. For more information, see the following Remarks section.

## Remarks

The *prclImageableArea* parameter is IN OUT. All other parameters for this method are input only.

If the plug-in cannot complete the operation, it should return an appropriate failure HRESULT value, which will cause the current print job to fail.

## See also

[IPrintOemUIMXDC](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nn-prcomoem-iprintoemuimxdc)

[RECTL](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rectl)