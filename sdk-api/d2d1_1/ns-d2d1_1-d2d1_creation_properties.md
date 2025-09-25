# D2D1_CREATION_PROPERTIES structure

## Description

Specifies the options with which the [Direct2D](https://learn.microsoft.com/windows/desktop/Direct2D/direct2d-portal) device, factory, and device context are created.

## Members

### `threadingMode`

The threading mode with which the corresponding root objects will be created.

### `debugLevel`

The debug level that the root objects should be created with.

### `options`

The device context options that the root objects should be created with.

## Remarks

The root objects referred to here are the [Direct2D](https://learn.microsoft.com/windows/desktop/Direct2D/direct2d-portal) device, Direct2D factory and the Direct2D device context.

## See also

[D2D1CreateDevice](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-d2d1createdevice)

[D2D1CreateDeviceContext](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-d2d1createdevicecontext)