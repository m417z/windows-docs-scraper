# PFND3DDDI_RENDERCB callback function

## Description

The **pfnRenderCb** function submits the current command buffer for rendering to the display miniport driver.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in, out]

A pointer to a [D3DDDICB_RENDER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_render) structure that describes the current command buffer to render.

## Return value

**pfnRenderCb** returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|The command buffer was successfully rendered.|
|D3DDDIERR_PRIVILEGEDINSTRUCTION|The display miniport driver detected a privileged instruction in the command buffer; privileged instructions cannot be present in a command buffer.|
|D3DDDIERR_ILLEGALINSTRUCTION|The display miniport driver detected instructions that graphics hardware cannot support.|
|D3DDDIERR_INVALIDHANDLE|The display miniport driver detected an invalid handle in the command buffer.|
|D3DDDIERR_CANTRENDERLOCKEDALLOCATION|The video memory manager detected references to a locked allocation in the allocation list. Note that the video memory manager returns this error only if it could not reposition the allocation to an AGP or system memory segment.|
|D3DDDIERR_INVALIDUSERBUFFER|The display miniport driver detected an underrun or overrun of data or instructions. That is, the driver received less or more instructions or data than it expected.|
|E_OUTOFMEMORY|pfnRenderCb could not complete because of insufficient memory.|
|E_INVALIDARG|Parameters were validated and determined to be incorrect.|

This function might also return other HRESULT values.

## Remarks

When the user-mode display driver must submit the current command buffer for rendering to the display miniport driver (for example, during a call to the user-mode display driver's [Flush](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfworkitem-flush) or Flush(D3D10) function), the user-mode display driver must call the **pfnRenderCb** function. The user-mode display driver should set the *hDevice* parameter to the value the Microsoft Direct3D runtime supplied during the [CreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createdevice) or CreateDevice(D3D10) call. In the [D3DDDICB_RENDER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_render) structure that is pointed to by the *pData* parameter, the user-mode display driver should also set:

* The **CommandLength** member to the number of bytes of commands in the command buffer that start from offset zero.
* The **CommandOffset** member to nonzero if the user-mode display driver must specify an offset to the first hardware command in the command buffer.
* The **NumAllocations** member to the number of elements in the allocation list.
* The **NumPatchLocations** member to the number of elements in the patch-location list.

After a call to **pfnRenderCb**, the user-mode display driver must determine the base address and size of the command buffer that it should use for its next submission from the values that are returned in the **pNewCommandBuffer** and **NewCommandBufferSize** members of [D3DDDICB_RENDER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_render). Similarly, the driver must determine the base address and number of elements of the next allocation list and patch-location list from the values that are returned in the **pNewAllocationList** and **NewAllocationListSize** members and **pNewPatchLocationList** and **NewPatchLocationListSize** members respectively.

If the user-mode display driver detects that most of the command buffer flushes are because the driver runs out of space in the command buffer, allocation list, or patch-location list, the driver can request for them to be resized. To resize the command buffer, the driver sets the **ResizeCommandBuffer** bit-field flag in the **Flags** member of [D3DDDICB_RENDER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_render) and puts the requested size in the **NewCommandBufferSize** member of D3DDDICB_RENDER. Similarly, to resize the allocation list, the driver sets the **ResizeAllocationList** bit-field flag in the **Flags** member of D3DDDICB_RENDER and puts the requested number of elements in the **NewAllocationListSize** member of D3DDDICB_RENDER. To resize the patch-location list, the driver sets the **ResizePatchLocationList** bit-field flag in the **Flags** member of D3DDDICB_RENDER and puts the requested number of elements in the **NewPatchLocationListSize** member of D3DDDICB_RENDER.

**Note** Even though the driver can request that the command buffer and the allocation and patch-location lists be resized, the video memory manager might not be able to comply. Therefore, regardless of whether the call to **pfnRenderCb** is successful, the driver should verify the values that are returned in the **NewCommandBufferSize**, **NewAllocationListSize**, and **NewPatchLocationListSize** members of D3DDDICB_RENDER.

If the user-mode display driver sets the **hContext** member of the [D3DDDICB_RENDER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_render) structure that is pointed to by the *pData* parameter to **NULL**, the Microsoft Direct3D runtime sends the rendering operation to the default context of the device. If the user-mode display driver sets **hContext** to a valid handle that the [pfnCreateContextCb](https://learn.microsoft.com/previous-versions/ff568895(v=vs.85)) function previously returned and that represents a device context, the Direct3D runtime sends the rendering operation to that context. **Direct3D Version 11 Note:** For more information about how the driver calls **pfnRenderCb**, see [Changes from Direct3D 10](https://learn.microsoft.com/windows-hardware/drivers/display/changes-from-direct3d-10).

#### Examples

The following code example shows how to submit the current command buffer for rendering to the display miniport driver. This code example generates the allocation list after the command buffer and patch list are generated. This is not optimal for performance because the command buffer is parsed more than necessary. However, this implementation is easier to show. In a production driver, generating the command buffer at the same time as the allocation and patch lists is more efficient.

```cpp
VOID CD3DContext::SubmitDXVABuffer(DWORD Size) {
    D3DDDICB_RENDER     renderCBData = {0};
    DWORD               dwAllocationListUsed;
    HRESULT             hr;

    if (GenerateAllocationListFromCmdBuf(R200UpdateQSParamsForDXVASubmit(m_pR200Ctx, Size), m_sContexts[MULTI_ENGINE_NODE_VIDEO].pHwCmdBufAllocList, m_dwHwCmdBufAllocListSize, &dwAllocationListUsed) == FALSE)
    {
        DBG_BREAK;
        return;
    }

    // 3-D and video packets must be in sync. If the last packet that was sent went to
    // the 3-D engine, that packet must finish before the new packet runs on the hardware.

    renderCBData.CommandOffset  = 0;
    renderCBData.CommandLength  = Size + sizeof(UMD_CMDBUF_INFO);
    renderCBData.NumAllocations = dwAllocationListUsed;
    renderCBData.hContext = m_sContexts[MULTI_ENGINE_NODE_VIDEO].hContext;

    // Copy command-buffer data from the internal buffer to the buffer that was created by dxgkrnl
    memcpy(m_sContexts[MULTI_ENGINE_NODE_VIDEO].pHwCmdBuf, m_pHwCmdBuf + GetCmdBufPreambleSize(m_pR200Ctx), renderCBData.CommandLength);

    m_d3dCallbacks.pfnRenderCb(m_hD3D, &renderCBData);

        // Makes video the last engine that work was submitted to
        m_LastEngineSubmit = MULTI_ENGINE_NODE_VIDEO;
    }
```

## See also

[CreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createdevice)

[D3DDDICB_RENDER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_render)

[D3DDDI_DEVICECALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicecallbacks)

[Flush](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfworkitem-flush)

[pfnCreateContextCb](https://learn.microsoft.com/previous-versions/ff568895(v=vs.85))