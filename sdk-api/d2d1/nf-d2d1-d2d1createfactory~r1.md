## Description

Creates a factory object that can be used to create Direct2D resources.

## Parameters

### `factoryType` [in]

Type: **[D2D1_FACTORY_TYPE](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_factory_type)**

The threading model of the factory and the resources it creates.

### `riid` [in]

Type: **REFIID**

A reference to the IID of [ID2D1Factory](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1factory) that is obtained by using `__uuidof(ID2D1Factory)`.

### `ppIFactory` [out]

Type: **void****

When this method returns, contains the address to a pointer to the new factory.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the function succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes) [error code](https://learn.microsoft.com/windows/win32/com/com-error-codes-10).

## Remarks

The [ID2D1Factory](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1factory) interface provides the starting point for Direct2D. In general, an object created from a single instance of a factory object can be used with other resources created from that instance, but not with resources created by other factory instances.

## See also

[Direct2D API Overview](https://learn.microsoft.com/windows/win32/Direct2D/the-direct2d-api)