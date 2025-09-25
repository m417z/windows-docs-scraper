# DCompositionCreateDevice3 function

## Description

Creates a new DirectComposition device object, which can be used to create other DirectComposition objects.

## Parameters

### `renderingDevice` [in, optional]

Type: **IUnknown***

An optional pointer to a DirectX device to be used to create DirectComposition surface objects. Must be a pointer to an object implementing the [IDXGIDevice](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgidevice) or [ID2D1Device](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1device) interfaces.

### `iid` [in]

Type: **REFIID**

The identifier of the interface to retrieve. This must be one of __uuidof(IDCompositionDevice) or __uuidof(IDCompositionDesktopDevice).

### `dcompositionDevice` [out]

Type: **void****

Receives an interface pointer to the newly created device object. The pointer is of the type specified by the *iid* parameter. This parameter must not be NULL.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.