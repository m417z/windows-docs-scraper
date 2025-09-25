# IDeviceModelPlugIn::ColorimetricToDeviceColorsWithBlack

## Description

Returns the appropriate device colors in response to the incoming number of colors, channels, black information, Commission Internationale l'Eclairge XYZ (CIEXYZ) colors and the proprietary plug-in algorithms.

## Parameters

### `cColors` [in]

The number of colors in the *pXYZColors* and *pDeviceValues* arrays.

### `cChannels` [in]

The number of color channels in the *pDeviceValues* arrays.

### `pXYZColors` [out]

A pointer to the array of outgoing [XYZColorF](https://learn.microsoft.com/windows/win32/api/wcsplugin/ns-wcsplugin-xyzcolorf) structures.

### `pBlackInformation` [in]

A pointer to the [BlackInformation](https://learn.microsoft.com/windows/desktop/api/wcsplugin/ns-wcsplugin-blackinformation).

### `pDeviceValues` [in]

A pointer to the array of incoming device colors that are to be converted to [XYZColorF](https://learn.microsoft.com/windows/win32/api/wcsplugin/ns-wcsplugin-xyzcolorf) structures.

## Return value

If this function succeeds, the return value is S_OK.

If this function fails, the return value is E_FAIL. For extended error information, call **GetLastError**.

## Remarks

If *cColors* or *cChannels* is zero, the return value is E_FAIL.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)
* [IDeviceModelPlugIn](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcsplugin/nn-wcsplugin-idevicemodelplugin)