# D3DKMTRender function

## Description

The **D3DKMTRender** function submits the current command buffer to the Microsoft DirectX graphics kernel subsystem (*Dxgkrnl.sys*).

## Parameters

### `unnamedParam1`

*pData* [in, out]

A pointer to a [D3DKMT_RENDER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_render) structure that describes parameters for submitting the current command buffer to the graphics kernel subsystem.

## Return value

**D3DKMTRender** returns one of the following values:

| **Return code** | **Description** |
|:--|:--|
| **STATUS_SUCCESS** | The command buffer was successfully submitted. |
| **STATUS_DEVICE_REMOVED** | The graphics adapter was stopped or the display context was reset. |
| **STATUS_INVALID_PARAMETER** | Parameters were validated and determined to be incorrect. |
| **STATUS_NO_MEMORY** | [D3DKMTRender]() could not complete because of insufficient memory. |
| **STATUS_INVALID_HANDLE** | The OpenGL ICD detected an invalid handle in the command buffer. |
| **STATUS_PRIVILEGED_INSTRUCTION** | [D3DKMTRender]() detected nonprivileged instructions (that is, instructions that access memory beyond the privilege of the current CPU process). |

This function might also return other **NTSTATUS** values.

## Remarks

A command buffer typically contains many graphics commands.

If **D3DKMTRender** returns **STATUS_GRAPHICS_ALLOCATION_INVALID**, the OpenGL ICD should re-open or re-create the primary handle, replace all references in the command buffer to the previous handle with the new handle, and then call **D3DKMTRender** again to resubmit the buffer.

After a call to **D3DKMTRender**, the OpenGL ICD should determine the base address and size of the command buffer that it should use for its next submission from the values that are returned in the **pCommandBuffer** and **CommandBufferSize** members of the [D3DKMT_RENDER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_render) structure that is pointed to by the *pData* parameter.

For a device that uses guaranteed DMA buffer contract mode (for more information about this mode, see [Using the Guaranteed Contract DMA Buffer Model](https://learn.microsoft.com/windows-hardware/drivers/display/using-the-guaranteed-contract-dma-buffer-model)), the size of the DMA buffer that is available to the display miniport driver to translate the command buffer at the next submission is the same as the size of the command buffer itself. For such a device, the OpenGL ICD should also determine the size of the allocation list that will be available to the display miniport driver during the translation of the command buffer at the next submission from the value that is returned in the **AllocationListSize** member of [D3DKMT_RENDER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_render).

For devices that do not use guaranteed DMA buffer contract, the OpenGL ICD can use the information that is returned in the **CommandBufferSize** and **AllocationListSize** members to determine the size of the next DMA buffer and allocation list that will be available for translation. However, under low-memory conditions, the actual DMA buffer and allocation list that is provided to the display miniport driver might be smaller than required.

If the OpenGL ICD detects that most of the command buffer flushes are because the driver runs out of space in the command buffer or allocation list, the driver can request for them to be resized. To resize the command buffer, the driver sets the **ResizeCommandBuffer** bit-field flag in the **Flags** member of D3DKMT_RENDER and puts the requested size in the **CommandBufferSize** member of D3DKMT_RENDER. Similarly, to resize the allocation list, the driver sets the **ResizeAllocationList** bit-field flag in the **Flags** member of D3DKMT_RENDER and puts the requested number of elements in the **AllocationListSize** member of D3DKMT_RENDER.

> [!NOTE]
> Even though the driver can request for resizing of both the command buffer and the allocation list, the video memory manager might not be able to comply. Therefore, if the call to **D3DKMTRender** is successful, the driver should verify the values that are returned in the **pCommandBuffer**, **CommandBufferSize**, and **AllocationListSize** members.\
However, if the call to **D3DKMTRender** fails, the driver determines that the command buffer, the allocation list, or both were not resized. Therefore, the driver should not process the values that are returned in the **pCommandBuffer**, **CommandBufferSize**, and **AllocationListSize** members because they are invalid.

#### Examples

The following code example demonstrates how an OpenGL ICD can use **D3DKMTRender** to render 3-D primitives.

```cpp
HRESULT Render(D3DKMT_HANDLE hDevice, UINT CommandOffset, UINT CommandLength)
{
    D3DKMT_RENDER RenderData;

    memset(&RenderData, 0, sizeof(RenderData));
    RenderData.hDevice = hDevice;
    RenderData.CommandOffset = CommandOffset;
    RenderData.CommandLength = CommandLength;

    if (NT_SUCCESS((*pfnKTRender)(&RenderData))) {
        return S_OK;
    }
    return E_FAIL;
}
```

## See also

[D3DKMTGetDeviceState](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtgetdevicestate)

[D3DKMT_RENDER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_render)