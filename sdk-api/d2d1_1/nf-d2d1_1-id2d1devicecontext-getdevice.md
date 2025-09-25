# ID2D1DeviceContext::GetDevice

## Description

Gets the device associated with a device context.

## Parameters

### `device` [out]

Type: **[ID2D1Device](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1device)****

When this method returns, contains the address of a pointer to a Direct2D device associated with this device context.

## Remarks

The application can retrieve the device even if it is created from an earlier render target code-path. The application must use an [ID2D1DeviceContext](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1devicecontext) interface and then call **GetDevice**. Some functionality for controlling all of the resources for a set of device contexts is maintained only on an [ID2D1Device](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1device) object.

## See also

[ID2D1Device](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1device)

[ID2D1DeviceContext](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1devicecontext)