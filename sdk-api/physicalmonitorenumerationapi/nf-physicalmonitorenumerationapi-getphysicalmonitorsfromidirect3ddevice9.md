# GetPhysicalMonitorsFromIDirect3DDevice9 function

## Description

Retrieves the physical monitors associated with a Direct3D device.

## Parameters

### `pDirect3DDevice9` [in]

Pointer to the [IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9) interface of the Direct3D device.

### `dwPhysicalMonitorArraySize` [in]

Number of elements in *pPhysicalMonitorArray*. To get the required size of the array, call [GetNumberOfPhysicalMonitorsFromIDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/physicalmonitorenumerationapi/nf-physicalmonitorenumerationapi-getnumberofphysicalmonitorsfromidirect3ddevice9).

### `pPhysicalMonitorArray` [out]

Pointer to an array of [PHYSICAL_MONITOR](https://learn.microsoft.com/windows/win32/api/physicalmonitorenumerationapi/ns-physicalmonitorenumerationapi-physical_monitor) structures. The caller must allocate the array.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

A single Direct3D device can be associated with more than one physical monitor. This function returns a handle and a text description for each physical monitor.

When you are done using the monitor handles, close them by passing the *pPhysicalMonitorArray* array to the [DestroyPhysicalMonitors](https://learn.microsoft.com/windows/desktop/api/physicalmonitorenumerationapi/nf-physicalmonitorenumerationapi-destroyphysicalmonitors) function.

## See also

[Monitor Configuration Functions](https://learn.microsoft.com/windows/desktop/Monitor/monitor-configuration-functions)