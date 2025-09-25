# IDeviceModelPlugIn::GetPrimarySamples

## Description

Returns the measurement color for the primary sample.

## Parameters

### `pPrimaryColor` [out]

The primary color type, which is determined by using the hue circle order. If the plugin device model does not natively support primaries for red, yellow, green, cyan, blue, magenta, black and white, it must still return virtual primary data.

## Return value

If this function succeeds, the return value is S_OK.

If this function fails, the return value is E_FAIL.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)
* [IDeviceModelPlugIn](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcsplugin/nn-wcsplugin-idevicemodelplugin)