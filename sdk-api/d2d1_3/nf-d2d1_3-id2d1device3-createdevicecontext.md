# ID2D1Device3::CreateDeviceContext

## Description

Creates a new [ID2D1DeviceContext3](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1devicecontext3) from this Direct2D device.

## Parameters

### `options`

Type: **[D2D1_DEVICE_CONTEXT_OPTIONS](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_device_context_options)**

The options to be applied to the created device context.

### `deviceContext3` [out]

Type: **[ID2D1DeviceContext3](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1devicecontext3)****

When this method returns, contains a pointer to the new device context.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ID2D1Device3](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1device3)