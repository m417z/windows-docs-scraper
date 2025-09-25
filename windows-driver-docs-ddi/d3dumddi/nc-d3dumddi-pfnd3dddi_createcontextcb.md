# PFND3DDDI_CREATECONTEXTCB callback function

## Description

The Direct3D runtime's **pfnCreateContextCb** callback function creates a context.

## Parameters

### `hDevice`

[in] Handle to the device for which the context is to be created.

### `unnamedParam2`

[in/out] Pointer to a [**D3DDDICB_CREATECONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_createcontext) structure that the driver fills with the necessary information for creating the context. This structure includes details such as node ordinal, engine affinity, and flags that specify the behavior and capabilities of the context to be created. Upon successful completion, the runtime updates this structure with information about the newly created context.

## Return value

**pfnCreateContextCb** returns an HRESULT to indicate the success or failure of the context creation request. Common return values include:

| Return code | Meaning |
| ----------- | ------- |
| S_OK | The context was successfully created. |
| E_OUTOFMEMORY | There is insufficient memory to create the context. |
| E_INVALIDARG | One or more of the provided arguments are invalid. |

## Remarks

The user-mode display driver (UMD) must explicitly call **pfnCreateContextCb** from its [**CreateDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createdevice) implementation to create a GPU context associated with the device. GPU contexts are GPU threads of execution on a newly created device.

The context encapsulates state and command buffers that the GPU uses to perform rendering operations. UMD is responsible for managing the lifecycle of contexts it creates, including their eventual destruction to free up resources.

For more information about the creation of a rendering device, see [Windows Display Driver Model (WDDM) operation flow](https://learn.microsoft.com/windows-hardware/drivers/display/windows-vista-and-later-display-driver-model-operation-flow).

## See also

[**D3DDDICB_CREATECONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_createcontext)

[**pfnDestroyContextCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_destroycontextcb)