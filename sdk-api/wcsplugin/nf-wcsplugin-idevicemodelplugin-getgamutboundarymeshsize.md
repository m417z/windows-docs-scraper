# IDeviceModelPlugIn::GetGamutBoundaryMeshSize

## Description

Returns the required data structure sizes for the [GetGamutBoundaryMesh](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcsplugin/nf-wcsplugin-idevicemodelplugin-getgamutboundarymesh) function.

## Parameters

### `pNumVertices` [out]

The required number of vertices.

### `pNumTriangles` [out]

The required number of triangles.

## Return value

If this function succeeds, the return value is S_OK.

If the plug-in device model wants WCS to compute its gamut boundary mesh, the return value is S_FALSE.

If this function fails, the return value is E_FAIL.

## Remarks

This function is called by the [CreateMultiProfileTransform](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-createmultiprofiletransform) function.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)
* [IDeviceModelPlugIn](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcsplugin/nn-wcsplugin-idevicemodelplugin)