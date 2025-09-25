# IDMLDeviceChild::GetDevice

## Description

Retrieves the DirectML device that was used to create this object.

## Parameters

### `riid`

Type: **REFIID**

A reference to the globally unique identifier (GUID) of the interface that you wish to be returned in *ppv*. This is expected to be the GUID of [IDMLDevice](https://learn.microsoft.com/windows/win32/api/directml/nn-directml-idmldevice).

### `ppv` [out]

Type: **void****

A pointer to a memory block that receives a pointer to the DirectML device. This is the address of a pointer to an [IDMLDevice](https://learn.microsoft.com/windows/win32/api/directml/nn-directml-idmldevice), representing the DirectML device.

## Return value

Type: [**HRESULT**](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDMLDeviceChild](https://learn.microsoft.com/windows/win32/api/directml/nn-directml-idmldevicechild)