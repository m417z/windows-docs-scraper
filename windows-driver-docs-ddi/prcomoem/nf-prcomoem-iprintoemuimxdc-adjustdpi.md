# IPrintOemUIMXDC::AdjustDPI

## Description

The `IPrintOemUIMXDC::AdjustDPI` method enables an XPS filter pipeline driver to use UnidrvUI.dll or PS5UI.dll to support configuration of image resolution.

## Parameters

### `hPrinter`

A handle to the printer that is currently being queried.

### `cbDevMode`

The size of the [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew) structure, including appended data.

### `pDevMode`

A pointer to the DEVMODE structure that contains the current device settings.

### `cbOEMDM`

The number of bytes in the vendor-provided section of the DEVMODE structure.

### `pOEMDM`

A pointer to the data that is contained in the vendor portion of the DEVMODE structure that *pDevMode* points to.

### `pDPI`

A pointer to the current resolution, in dots per inch (DPI), assuming square pixels. If this parameter is configured, its returned value must be a positive integer.

## Return value

`AdjustDPI` returns S_OK if the method succeeds. Otherwise, this method should return E_NOTIMPL if the plug-in does not support the method, or any appropriate failure value if the plug-in cannot complete the operation. For more information, see the following Remarks section.

## Remarks

The *pDPI* parameter is IN OUT. All other parameters for this function are input only.

If the plug-in cannot complete the operation, it should return an appropriate failure HRESULT, which causes the current print job to fail.