# IDMLDevice::GetParentDevice

## Description

Retrieves the Direct3D 12 device that was used to create this DirectML device.

## Parameters

### `riid`

Type: **REFIID**

A reference to the globally unique identifier (GUID) of the interface that you wish to be returned in *ppv*. This is expected to be the GUID of [ID3D12Device](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12device).

### `ppv` [out]

Type: **void****

A pointer to a memory block that receives a pointer to the device. This is the address of a pointer to an [ID3D12Device](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12device), representing the device.

## Return value

Type: [**HRESULT**](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDMLDevice](https://learn.microsoft.com/windows/win32/api/directml/nn-directml-idmldevice)