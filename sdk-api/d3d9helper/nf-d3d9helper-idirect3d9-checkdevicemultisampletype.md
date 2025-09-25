# IDirect3D9::CheckDeviceMultiSampleType

## Description

Determines if a multisampling technique is available on this device.

## Parameters

### `Adapter` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Ordinal number denoting the display adapter to query. D3DADAPTER_DEFAULT is always the primary display adapter. This method returns **FALSE** when this value equals or exceeds the number of display adapters in the system. See Remarks.

### `DeviceType` [in]

Type: **[D3DDEVTYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddevtype)**

Member of the [D3DDEVTYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3ddevtype) enumerated type, identifying the device type.

### `SurfaceFormat` [in]

Type: **[D3DFORMAT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat)**

Member of the [D3DFORMAT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dformat) enumerated type that specifies the format of the surface to be multisampled. For more information, see Remarks.

### `Windowed` [in]

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

bool value. Specify **TRUE** to inquire about windowed multisampling, and specify **FALSE** to inquire about full-screen multisampling.

### `MultiSampleType` [in]

Type: **[D3DMULTISAMPLE_TYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dmultisample-type)**

Member of the [D3DMULTISAMPLE_TYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dmultisample-type) enumerated type, identifying the multisampling technique to test.

### `pQualityLevels` [out]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

**pQualityLevels** returns the number of device-specific sampling variations available with the given sample type. For example, if the returned value is 3, then quality levels 0, 1 and 2 can be used when creating resources with the given sample count. The meanings of these quality levels are defined by the device manufacturer and cannot be queried through D3D. For example, for a particular device different quality levels at a fixed sample count might refer to different spatial layouts of the sample locations or different methods of resolving. This can be **NULL** if it is not necessary to return the quality levels.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the device can perform the specified multisampling method, this method returns D3D_OK.
D3DERR_INVALIDCALL is returned if the Adapter or MultiSampleType parameters are invalid. This method returns D3DERR_NOTAVAILABLE if the queried multisampling technique is not supported by this device. D3DERR_INVALIDDEVICE is returned if DeviceType does not apply to this adapter.

## Remarks

This method is intended for use with both render-target and depth-stencil surfaces because you must create both surfaces multisampled if you want to use them together.

The following code fragment shows how you could use **CheckDeviceMultiSampleType** to test for devices that support a specific multisampling method.

```

if( SUCCEEDED(pD3D->CheckDeviceMultiSampleType( pCaps->AdapterOrdinal,
                                pCaps->DeviceType, BackBufferFormat,
                                FALSE, D3DMULTISAMPLE_3_SAMPLES, NULL ) ) &&
         SUCCEEDED(pD3D->CheckDeviceMultiSampleType( pCaps->AdapterOrdinal,
                                pCaps->DeviceType, DepthBufferFormat,
                                FALSE, D3DMULTISAMPLE_3_SAMPLES, NULL ) ) )
    return S_OK;

```

The preceding code will return S_OK if the device supports the full-screen D3DMULTISAMPLE_3_SAMPLES multisampling method with the surface format.

See the remarks in [D3DMULTISAMPLE_TYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dmultisample-type) for additional information on working with and setting multisample types and quality levels.

## See also

[IDirect3D9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3d9)