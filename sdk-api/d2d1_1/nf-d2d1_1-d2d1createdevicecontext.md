# D2D1CreateDeviceContext function

## Description

Creates a new Direct2D device context associated with a DXGI surface.

## Parameters

### `dxgiSurface` [in]

The DXGI surface the Direct2D device context is associated with.

### `creationProperties` [in, optional]

The properties to apply to the Direct2D device context.

### `d2dDeviceContext` [out]

When this function returns, contains the address of a pointer to a Direct2D device context.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| HRESULT | Description |
| --- | --- |
| S_OK | No error occurred. |
| E_OUTOFMEMORY | Direct2D could not allocate sufficient memory to complete the call. |
| E_INVALIDARG | An invalid value was passed to the method. |

## Remarks

This function will also create a new [ID2D1Factory1](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1factory1) that can be retrieved through [ID2D1Resource::GetFactory](https://learn.microsoft.com/windows/desktop/api/d2d1/nf-d2d1-id2d1resource-getfactory).

This function will also create a new [ID2D1Device](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1device) that can be retrieved through [ID2D1DeviceContext::GetDevice](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-getdevice).

The DXGI device will be specified implicitly through *dxgiSurface*.

If *creationProperties* are not specified, the Direct2D device will inherit its threading mode from the DXGI device implied by *dxgiSurface* and debug tracing will not be enabled.

## See also

[D2D1CreateDevice](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-d2d1createdevice)

[D2D1CreateDeviceContext](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-d2d1createdevicecontext)

[D2D1_CREATION_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ns-d2d1_1-d2d1_creation_properties)

[ID2D1Device](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1device)

[ID2D1Factory](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1factory)

[ID2D1Resource::GetFactory](https://learn.microsoft.com/windows/desktop/api/d2d1/nf-d2d1-id2d1resource-getfactory)