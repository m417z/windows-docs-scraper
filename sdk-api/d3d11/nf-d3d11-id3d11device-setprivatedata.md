# ID3D11Device::SetPrivateData

## Description

Set data to a device and associate that data with a guid.

## Parameters

### `guid` [in]

Type: **[REFGUID](https://learn.microsoft.com/openspecs/windows_protocols/ms-oaut/6e7d7108-c213-40bc-8294-ac13fe68fd50)**

Guid associated with the data.

### `DataSize` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Size of the data.

### `pData` [in, optional]

Type: **const void***

Pointer to the data to be stored with this device. If pData is **NULL**, DataSize must also be 0, and any data previously associated with the guid will be destroyed.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the following [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## Remarks

The data stored in the device with this method can be retrieved with [ID3D11Device::GetPrivateData](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-getprivatedata).

The data and guid set with this method will typically be application-defined.

The [debug layer](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-layers) reports memory leaks by outputting a list of object interface pointers along with their friendly names. The default friendly name is "<unnamed>". You can set the friendly name so that you can determine if the corresponding object interface pointer caused the leak. To set the friendly name, use the **SetPrivateData** method and the **WKPDID_D3DDebugObjectName** GUID that is in D3Dcommon.h. For example, to give pContext a friendly name of *My name*, use the following code:

```

static const char c_szName[] = "My name";
hr = pContext->SetPrivateData( WKPDID_D3DDebugObjectName, sizeof( c_szName ) - 1, c_szName );

```

## See also

[ID3D11Device](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11device)