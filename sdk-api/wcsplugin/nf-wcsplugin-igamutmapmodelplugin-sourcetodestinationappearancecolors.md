# IGamutMapModelPlugIn::SourceToDestinationAppearanceColors

## Description

Returns the appropriate gamut-mapped appearance colors in response to the specified number of colors and the [CIEJCh](https://learn.microsoft.com/windows/win32/api/_wcs/) colors.

## Parameters

### `cColors` [in]

The number of colors in the *pXYZColors* and *pDeviceValues* arrays.

### `pInputColors` [in]

A pointer to the array of incoming colors to be gamut mapped.

### `pOutputColors` [out]

A pointer to the array of outgoing colors.

## Return value

If this function succeeds, the return value is S_OK.

If this function fails, the return value is E_FAIL.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [IGamutMapModelPlugIn](https://learn.microsoft.com/windows/win32/api/wcsplugin/nn-wcsplugin-igamutmapmodelplugin)