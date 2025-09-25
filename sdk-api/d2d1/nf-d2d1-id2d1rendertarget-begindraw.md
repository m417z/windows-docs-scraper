# ID2D1RenderTarget::BeginDraw

## Description

Initiates drawing on this render target.

## Remarks

Drawing operations can only be issued between a **BeginDraw** and [EndDraw](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-enddraw) call.

BeginDraw and EndDraw are used to indicate that a render target is in use by the Direct2D system. Different implementations of [ID2D1RenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1rendertarget) might behave differently when **BeginDraw** is called. An [ID2D1BitmapRenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1bitmaprendertarget) may be locked between **BeginDraw**/[EndDraw](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-enddraw) calls, a DXGI surface render target might be acquired on **BeginDraw** and released on **EndDraw**, while an [ID2D1HwndRenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1hwndrendertarget) may begin batching at **BeginDraw** and may present on **EndDraw**, for example.

The BeginDraw method must be called before rendering operations can be called, though state-setting and state-retrieval operations can be performed even outside of **BeginDraw**/[EndDraw](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-enddraw).

After **BeginDraw** is called, a render target will normally build up a batch of rendering commands, but defer processing of these commands until either an internal buffer is full, the [Flush](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-flush) method is called, or until [EndDraw](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-enddraw) is called. The **EndDraw** method causes any batched drawing operations to complete, and then returns an HRESULT indicating the success of the operations and, optionally, the tag state of the render target at the time the error occurred. The **EndDraw** method always succeeds: it should not be called twice even if a previous **EndDraw** resulted in a failing HRESULT.

If [EndDraw](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1rendertarget-enddraw) is called without a matched call to **BeginDraw**, it returns an error indicating that **BeginDraw** must be called before **EndDraw**.

Calling **BeginDraw** twice on a render target puts the target into an error state where nothing further is drawn, and returns an appropriate HRESULT and error information when **EndDraw** is called.

## Examples

The following example uses an [ID2D1HwndRenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1hwndrendertarget) to draw text to a window.

```cpp
//  Called whenever the application needs to display the client
//  window. This method writes "Hello, World"
//
//  Note that this function will automatically discard device-specific
//  resources if the Direct3D device disappears during function
//  invocation, and will recreate the resources the next time it's
//  invoked.
//
HRESULT DemoApp::OnRender()
{
    HRESULT hr;

    hr = CreateDeviceResources();

    if (SUCCEEDED(hr))
    {
        static const WCHAR sc_helloWorld[] = L"Hello, World!";

        // Retrieve the size of the render target.
        D2D1_SIZE_F renderTargetSize = m_pRenderTarget->GetSize();

        m_pRenderTarget->BeginDraw();

        m_pRenderTarget->SetTransform(D2D1::Matrix3x2F::Identity());

        m_pRenderTarget->Clear(D2D1::ColorF(D2D1::ColorF::White));

        m_pRenderTarget->DrawText(
            sc_helloWorld,
            ARRAYSIZE(sc_helloWorld) - 1,
            m_pTextFormat,
            D2D1::RectF(0, 0, renderTargetSize.width, renderTargetSize.height),
            m_pBlackBrush
            );

        hr = m_pRenderTarget->EndDraw();

        if (hr == D2DERR_RECREATE_TARGET)
        {
            hr = S_OK;
            DiscardDeviceResources();
        }
    }

    return hr;
}

```

## See also

[ID2D1RenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1rendertarget)