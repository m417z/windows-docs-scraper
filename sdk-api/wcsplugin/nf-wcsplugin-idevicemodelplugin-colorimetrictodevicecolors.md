# IDeviceModelPlugIn::ColorimetricToDeviceColors

## Description

Returns the appropriate XYZ colors in response to the specified number of colors, channels, device colors and the proprietary plug-in algorithms.

## Parameters

### `cColors` [in]

The number of colors in the *pXYZColors* and *pDeviceValues* arrays.

### `cChannels` [in]

The number of color channels in the *pDeviceValues* arrays.

### `pXYZColors` [in]

The pointer to the array of incoming XYZColors to convert to device colors.

### `pDeviceValues` [out]

The pointer to an array that contains the resulting outgoing device color values.

## Return value

If this function succeeds, the return value is S_OK.

If this function fails, the return value is E_FAIL.

## Remarks

If *cColors* or *cChannels* is zero, the return value is E_FAIL. If there are invalid or out of gamut colors (which may occur if there has been prior processing of the gamut map model), then the return value is E_FAIL.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)
* [IDeviceModelPlugIn](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcsplugin/nn-wcsplugin-idevicemodelplugin)