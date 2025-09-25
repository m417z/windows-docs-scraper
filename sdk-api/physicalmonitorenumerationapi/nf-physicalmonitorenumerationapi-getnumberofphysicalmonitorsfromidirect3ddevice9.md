# GetNumberOfPhysicalMonitorsFromIDirect3DDevice9 function

## Description

Retrieves the number of physical monitors associated with a Direct3D device.

## Parameters

### `pDirect3DDevice9` [in]

Pointer to the [IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9) interface of the Direct3D device.

### `pdwNumberOfPhysicalMonitors` [out]

Receives the number of physical monitors associated with the Direct3D device.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[GetPhysicalMonitorsFromIDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/physicalmonitorenumerationapi/nf-physicalmonitorenumerationapi-getphysicalmonitorsfromidirect3ddevice9)

[Monitor Configuration Functions](https://learn.microsoft.com/windows/desktop/Monitor/monitor-configuration-functions)