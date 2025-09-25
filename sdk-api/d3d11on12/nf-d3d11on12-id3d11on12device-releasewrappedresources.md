# ID3D11On12Device::ReleaseWrappedResources

## Description

Releases D3D11 resources that were wrapped for D3D 11on12.

## Parameters

### `ppResources` [in]

Type: **ID3D11Resource***

Specifies a pointer to a set of D3D11 resources, defined by [ID3D11Resource](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11resource).

### `NumResources`

Type: **UINT**

Count of the number of resources.

## Remarks

Call this method prior to calling Flush, to insert resource barriers to the appropriate "out" state, and to mark that they should then be expected to be in the "in" state.
If no resource list is provided, all wrapped resources are transitioned.
These resources will be marked as “not acquired” in hazard tracking until [ID3D11On12Device::AcquireWrappedResources](https://learn.microsoft.com/windows/desktop/api/d3d11on12/nf-d3d11on12-id3d11on12device-acquirewrappedresources) is called.

Keyed mutex resources cannot be provided to this method; use [IDXGIKeyedMutex::ReleaseSync](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgikeyedmutex-releasesync) instead.

#### Examples

Render text over D3D12 using D2D via the 11On12 device.

```cpp
// Render text over D3D12 using D2D via the 11On12 device.
void D3D1211on12::RenderUI()
{
    D2D1_SIZE_F rtSize = m_d2dRenderTargets[m_frameIndex]->GetSize();
    D2D1_RECT_F textRect = D2D1::RectF(0, 0, rtSize.width, rtSize.height);
    static const WCHAR text[] = L"11On12";

    // Acquire our wrapped render target resource for the current back buffer.
    m_d3d11On12Device->AcquireWrappedResources(m_wrappedBackBuffers[m_frameIndex].GetAddressOf(), 1);

    // Render text directly to the back buffer.
    m_d2dDeviceContext->SetTarget(m_d2dRenderTargets[m_frameIndex].Get());
    m_d2dDeviceContext->BeginDraw();
    m_d2dDeviceContext->SetTransform(D2D1::Matrix3x2F::Identity());
    m_d2dDeviceContext->DrawTextW(
        text,
        _countof(text) - 1,
        m_textFormat.Get(),
        &textRect,
        m_textBrush.Get()
        );
    ThrowIfFailed(m_d2dDeviceContext->EndDraw());

    // Release our wrapped render target resource. Releasing
    // transitions the back buffer resource to the state specified
    // as the OutState when the wrapped resource was created.
    m_d3d11On12Device->ReleaseWrappedResources(m_wrappedBackBuffers[m_frameIndex].GetAddressOf(), 1);

    // Flush to submit the 11 command list to the shared command queue.
    m_d3d11DeviceContext->Flush();
}

```

Refer to the [Example Code in the D3D12 Reference](https://learn.microsoft.com/windows/desktop/direct3d12/notes-on-example-code).

## See also

[ID3D11On12Device](https://learn.microsoft.com/windows/desktop/api/d3d11on12/nn-d3d11on12-id3d11on12device)