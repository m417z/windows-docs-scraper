# PFND3DDDI_DESTROYCONTEXTCB callback function

## Description

The D3D runtime's **pfnDestroyContextCb** function destroys a context that was created through a call to its [**pfnCreateContextCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createcontextcb) function.

## Parameters

### `hDevice`

[in] Handle to a display device (that is, the graphics context).

### `unnamedParam2`

[in] Pointer to a [**D3DDDICB_DESTROYCONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_destroycontext) structure that identifies the context to destroy.

## Return value

**pfnDestroyContextCb** returns an HRESULT to indicate the success or failure of the context deletion request. Common return values include:

|Return code|Description|
|--- |--- |
|S_OK|The context was successfully destroyed.|
|E_INVALIDARG|Parameters were validated and determined to be incorrect.|

## Remarks

If the specified context has not finished the work that is currently queued to it, the **pfnDestroyContextCb** function blocks until the context finishes its work and then returns.

**pfnDestroyContextCb** returns an error if the context to destroy currently owns a synchronization object.

For information about how the driver calls **pfnDestroyContextCb** starting in Direct3D version 11, see [Changes from Direct3D 10](https://learn.microsoft.com/windows-hardware/drivers/display/changes-from-direct3d-10).

The following code example shows how to destroy the default context for a display device.

```cpp
    if (m_d3dCallbacks.pfnDestroyContextCb) {
        D3DDDICB_DESTROYCONTEXT DestroyContext;
        DestroyContext.hContext = m_sContexts[MULTI_ENGINE_NODE_3D].hContext;
        m_d3dCallbacks.pfnDestroyContextCb(m_hD3D, &DestroyContext);
        m_sContexts[MULTI_ENGINE_NODE_3D].hContext = NULL;
    }
```

## See also

[**D3DDDICB_DESTROYCONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_destroycontext)

[**pfnCreateContextCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createcontextcb)