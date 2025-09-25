# IDeviceModelPlugIn::GetNeutralAxisSize

## Description

The [IDeviceModelPlugIn::GetNeutralAxisSize](https://learn.microsoft.com/windows/win32/api/wcsplugin/nf-wcsplugin-idevicemodelplugin-getneutralaxissize) function returns the number of data points along the neutral axis that are returned by the [GetNeutralAxis](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcsplugin/nf-wcsplugin-idevicemodelplugin-getneutralaxis) function. It is provided so that a Color Management Module (CMM) can allocate an appropriately sized buffer.

## Parameters

### `pcColors` [out]

The number of points that will be returned by a call to [GetNeutralAxis](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcsplugin/nf-wcsplugin-idevicemodelplugin-getneutralaxis). Minimum is 2 (black and white).

## Return value

If this function succeeds, the return value is S_OK.

If this function fails, the return value is E_FAIL.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)
* [IDeviceModelPlugIn](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcsplugin/nn-wcsplugin-idevicemodelplugin)