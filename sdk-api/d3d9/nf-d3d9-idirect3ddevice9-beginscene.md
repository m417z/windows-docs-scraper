# IDirect3DDevice9::BeginScene

## Description

Begins a scene.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. The method will fail with D3DERR_INVALIDCALL if **IDirect3DDevice9::BeginScene** is called
while already in a **IDirect3DDevice9::BeginScene**/[IDirect3DDevice9::EndScene](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-endscene) pair. This happens only
when **IDirect3DDevice9::BeginScene** is called twice without first calling **IDirect3DDevice9::EndScene**.

## Remarks

Applications must call **IDirect3DDevice9::BeginScene** before performing any rendering and must call [IDirect3DDevice9::EndScene](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-endscene)
when rendering is complete and before calling **IDirect3DDevice9::BeginScene** again.

If **IDirect3DDevice9::BeginScene** fails, the device was unable to begin the scene, and there is no need to
call [IDirect3DDevice9::EndScene](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-endscene). In fact, calls to **IDirect3DDevice9::EndScene** will fail if the
previous **IDirect3DDevice9::BeginScene** failed. This applies to any application that creates multiple swap chains.

There should be one **IDirect3DDevice9::BeginScene**/[IDirect3DDevice9::EndScene](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-endscene) pair between any successive calls to
present (either [IDirect3DDevice9::Present](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-present) or [IDirect3DSwapChain9::Present](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3dswapchain9-present)). **IDirect3DDevice9::BeginScene** should
be called once before any rendering is performed, and **IDirect3DDevice9::EndScene** should be called once after all rendering for a frame has been
submitted to the runtime. Multiple non-nested **IDirect3DDevice9::BeginScene**/**IDirect3DDevice9::EndScene** pairs between calls to present
are legal, but having more than one pair may incur a performance hit.
To enable maximal parallelism between the CPU and the graphics accelerator, it is advantageous to
call **IDirect3DDevice9::EndScene** as far ahead of calling present as possible.

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)