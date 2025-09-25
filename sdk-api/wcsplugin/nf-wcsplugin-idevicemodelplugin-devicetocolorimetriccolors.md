# IDeviceModelPlugIn::DeviceToColorimetricColors

## Description

Returns the appropriate XYZ colors in response to the specified number of colors, channels, device colors and the proprietary plug-in algorithms.

## Parameters

### `cColors` [in]

The number of colors in the *pXYZColors* and *pDeviceValues* arrays.

### `cChannels` [in]

The number of color channels in the *pDeviceValues* arrays.

### `pDeviceValues` [in]

A pointer to the array of outgoing XYZColors.

### `pXYZColors` [out]

A pointer to the array of incoming device colors to convert to XYZColors.

## Return value

If this function succeeds, the return value is S_OK.

If this function fails, the return value is E_FAIL. For extended error information, call **GetLastError**.

## Remarks

If *cColors* or *cChannels* is zero, the return value is E_FAIL.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)
* [IDeviceModelPlugIn](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcsplugin/nn-wcsplugin-idevicemodelplugin)