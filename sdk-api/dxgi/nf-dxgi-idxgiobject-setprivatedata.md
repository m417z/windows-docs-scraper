# IDXGIObject::SetPrivateData

## Description

Sets application-defined data to the object and associates that data with a GUID.

## Parameters

### `Name` [in]

Type: **[REFGUID](https://learn.microsoft.com/openspecs/windows_protocols/ms-oaut/6e7d7108-c213-40bc-8294-ac13fe68fd50)**

A GUID that identifies the data. Use this GUID in a call to [GetPrivateData](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgiobject-getprivatedata) to get the data.

### `DataSize`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The size of the object's data.

### `pData` [in]

Type: **const void***

A pointer to the object's data.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) values.

## Remarks

**SetPrivateData** makes a copy of the specified data and stores it with the object.

Private data that **SetPrivateData** stores in the object occupies the same storage space as private data that is stored by associated Direct3D objects (for example, by a Microsoft Direct3D 11 device through [ID3D11Device::SetPrivateData](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-setprivatedata) or by a Direct3D 11 child device through [ID3D11DeviceChild::SetPrivateData](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicechild-setprivatedata)).

The [debug layer](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-layers) reports memory leaks by outputting a list of object interface pointers along with their friendly names. The default friendly name is "<unnamed>". You can set the friendly name so that you can determine if the corresponding object interface pointer caused the leak. To set the friendly name, use the **SetPrivateData** method and the well-known private data GUID (**WKPDID_D3DDebugObjectName**) that is in D3Dcommon.h. For example, to give pContext a friendly name of *My name*, use the following code:

```

static const char c_szName[] = "My name";
hr = pContext->SetPrivateData( WKPDID_D3DDebugObjectName, sizeof( c_szName ) - 1, c_szName );

```

You can use **WKPDID_D3DDebugObjectName** to track down memory leaks and understand performance characteristics of your applications. This information is reflected in the output of the [debug layer](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-layers) that is related to memory leaks ([ID3D11Debug::ReportLiveDeviceObjects](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/nf-d3d11sdklayers-id3d11debug-reportlivedeviceobjects)) and with the [event tracing](https://learn.microsoft.com/windows/desktop/direct3d11/direct3d-11-1-features) for Windows events that we've added to Windows 8.

## See also

[DXGI Interfaces](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-interfaces)

[IDXGIObject](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgiobject)