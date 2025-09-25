# ID2D1DCRenderTarget::BindDC

## Description

Binds the render target to the device context to which it issues drawing commands.

## Parameters

### `hDC`

Type: **const HDC**

The device context to which the render target issues drawing commands.

### `pSubRect` [in]

Type: **const [RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect)***

The dimensions of the handle to a device context (HDC) to which the render target is bound.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) error code.

## Remarks

Before you can render with the DC render target, you must use its **BindDC** method to associate it with a GDI DC. You do this each time you use a different DC, or the size of the area you want to draw to changes.

## Examples

In the preceding code, *m_pD2DFactory* is a pointer to an [ID2D1Factory](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1factory), and *m_pDCRT* is a pointer to an [ID2D1DCRenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1dcrendertarget).

The next code example binds a DC to the [ID2D1DCRenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1dcrendertarget).

```cpp
HRESULT DemoApp::OnRender(const PAINTSTRUCT &ps)
{

```

```cpp
// Get the dimensions of the client drawing area.
GetClientRect(m_hwnd, &rc);

```

```cpp
// Bind the DC to the DC render target.
hr = m_pDCRT->BindDC(ps.hdc, &rc);

```

## See also

[Direct2D and GDI Interoperation Overview](https://learn.microsoft.com/windows/win32/Direct2D/direct2d-and-gdi-interoperation-overview)

[ID2D1DCRenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1dcrendertarget)