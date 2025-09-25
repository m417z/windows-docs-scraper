# IDXGIDeviceSubObject::GetDevice

## Description

Retrieves the device.

## Parameters

### `riid` [in]

Type: **REFIID**

The reference id for the device.

### `ppDevice` [out]

Type: **void****

The address of a pointer to the device.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

A code that indicates success or failure (see [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error)).

## Remarks

The type of interface that is returned can be any interface published by the device. For example, it could be an IDXGIDevice * called pDevice, and therefore the REFIID would be obtained by calling __uuidof(pDevice).

## See also

[DXGI Interfaces](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-interfaces)

[IDXGIDeviceSubObject](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgidevicesubobject)