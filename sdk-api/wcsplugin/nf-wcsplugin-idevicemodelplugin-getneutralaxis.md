# IDeviceModelPlugIn::GetNeutralAxis

## Description

The [IDeviceModelPlugIn::GetNeutralAxis](https://learn.microsoft.com/windows/win32/api/wcsplugin/nf-wcsplugin-idevicemodelplugin-getneutralaxis) return the XYZ colorimetry of sample points along the device's neutral axis.

## Parameters

### `cColors` [in]

The number of points that are returned.

### `pXYZColors` [out]

A pointer to an array of [XYZColorF](https://learn.microsoft.com/windows/desktop/api/wcsplugin/ns-wcsplugin-xyzcolorf) structures.

## Return value

If this function succeeds, the return value is S_OK.

If this function fails, the return value is E_FAIL.

## Remarks

You should define "neutral axis" in a way that is appropriate for your device. Usually, it is points made by the device's gray values. This might be R=G=B, or C=M=Y=0 and any value of K. For some devices, the most pleasing gray may be one that uses a different combination of colorants, such as M=Y=0 and C=K. The plug-in is responsible for determining the colorimetry of a sampling of the neutral axis values and returning them. The sampling may be as sparse as two points (white and black) or as dense as desired.

There is no requirement that the samples be uniformly spaced in any color space.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)
* [IDeviceModelPlugIn](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcsplugin/nn-wcsplugin-idevicemodelplugin)