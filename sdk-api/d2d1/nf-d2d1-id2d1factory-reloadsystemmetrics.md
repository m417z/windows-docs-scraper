## Description

Forces the factory to refresh any system defaults that it might have changed since factory creation.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) error code.

## Remarks

To ensure that the system DPI is current, you should call **ID2D1Factory.ReloadSystemMetrics** before calling the [GetDesktopDpi](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1factory-getdesktopdpi) method.

## See also

* [ID2D1Factory](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1factory)