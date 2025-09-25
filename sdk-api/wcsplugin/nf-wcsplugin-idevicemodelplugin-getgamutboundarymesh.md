# IDeviceModelPlugIn::GetGamutBoundaryMesh

## Description

Returns the triangular mesh from the plug-in. This function is used to compute the GamutBoundaryDescription.

## Parameters

### `cChannels` [in]

The number of channels.

### `cVertices` [in]

The number of vertices.

### `cTriangles` [in]

The number of triangles.

### `pVertices` [out]

A pointer to the array of vertices in the plug-in model gamut shell.

### `pTriangles` [out]

A pointer to the array of triangles in the plug-in model gamut shell.

## Return value

If this function succeeds, the return value is S_OK.

If this function fails, the return value is E_FAIL.

## Remarks

This function is called by the [CreateMultiProfileTransform](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-createmultiprofiletransform) function.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)
* [IDeviceModelPlugIn](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcsplugin/nn-wcsplugin-idevicemodelplugin)