# ID2D1Device::CreateDeviceContext

## Description

Creates a new device context from a Direct2D device.

## Parameters

### `options`

Type: **[D2D1_DEVICE_CONTEXT_OPTIONS](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_device_context_options)**

The options to be applied to the created device context.

### `deviceContext` [out]

Type: **const [ID2D1DeviceContext](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1devicecontext)****

When this method returns, contains the address of a pointer to the new device context.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If it fails, it returns an **HRESULT** error code.

## Remarks

The new device context will not have a selected target bitmap. The caller must create and select a bitmap as the target surface of the context.

## See also

[ID2D1Device](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1device)

[ID2D1DeviceContext](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1devicecontext)

[ID2D1DeviceContext::SetTarget](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-settarget)