# ID3D11DeviceContext::Flush

## Description

Sends queued-up commands in the command buffer to the graphics processing unit (GPU).

## Remarks

Most applications don't need to call this method. If an application calls this method when not necessary, it incurs a performance penalty.
Each call to **Flush** incurs a significant amount of overhead.

When Microsoft Direct3D state-setting, present, or draw commands are called by an application, those commands are queued into an internal command buffer.
**Flush** sends those commands to the GPU for processing. Typically, the Direct3D runtime sends these commands to the GPU automatically whenever the runtime determines that
they need to be sent, such as when the command buffer is full or when an application maps a resource. **Flush** sends the commands manually.

We recommend that you use **Flush** when the CPU waits for an arbitrary amount of time (such as when
you call the [Sleep](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-sleep) function).

Because **Flush** operates asynchronously, it can return either before or after the GPU finishes executing the queued graphics commands. However, the graphics commands eventually always complete. You can call the [ID3D11Device::CreateQuery](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-createquery) method with the [D3D11_QUERY_EVENT](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_query) value to create an event query; you can then use that event query in a call to the [ID3D11DeviceContext::GetData](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-getdata) method to determine when the GPU is finished processing the graphics commands.

Microsoft Direct3D 11 defers the destruction of objects. Therefore, an application can't rely upon objects immediately being destroyed. By calling **Flush**, you destroy any
objects whose destruction was deferred. If an application requires synchronous destruction of an object, we recommend that the application release all its
references, call [ID3D11DeviceContext::ClearState](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-clearstate), and then call **Flush**.

### Deferred Destruction Issues with Flip Presentation Swap Chains

Direct3D 11 defers the destruction of objects like views and resources until it can efficiently destroy them. This deferred destruction can cause problems with flip presentation model swap chains. Flip presentation model swap chains have the [DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL](https://learn.microsoft.com/windows/desktop/api/dxgi/ne-dxgi-dxgi_swap_effect) flag set. When you create a flip presentation model swap chain, you can associate only one swap chain at a time with an [HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types), **IWindow**, or composition surface. If an application attempts to destroy a flip presentation model swap chain and replace it with another swap chain, the original swap chain is not destroyed when the application immediately frees all of the original swap chain's references.

Most applications typically use the [IDXGISwapChain::ResizeBuffers](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgiswapchain-resizebuffers) method for the majority of scenarios where they replace new swap chain buffers for old swap chain buffers. However, if an application must actually destroy an old swap chain and create a new swap chain, the application must force the destruction of all objects that the application freed. To force the destruction, call [ID3D11DeviceContext::ClearState](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-clearstate) (or otherwise ensure no views are bound to pipeline state), and then call **Flush** on the immediate context. You must force destruction before you call [IDXGIFactory2::CreateSwapChainForHwnd](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgifactory2-createswapchainforhwnd), [IDXGIFactory2::CreateSwapChainForCoreWindow](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgifactory2-createswapchainforcorewindow), or [IDXGIFactory2::CreateSwapChainForComposition](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgifactory2-createswapchainforcomposition) again to create a new swap chain.

## See also

[ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext)