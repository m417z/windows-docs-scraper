# D3DKMTPresent function

## Description

The **D3DKMTPresent** function submits a present command to the Microsoft DirectX graphics kernel subsystem (*Dxgkrnl.sys*).

## Parameters

### `unnamedParam1` [in]

**pData**: A pointer to a [**D3DKMT_PRESENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_present) structure that describes parameters for presenting.

## Return value

**D3DKMTPresent** returns an NTSTATUS value, such as one of the following values:

| **Return code** | **Description** |
|:--|:--|
| **STATUS_SUCCESS** | The present was successfully performed. |
| **STATUS_DEVICE_REMOVED** | The graphics adapter was stopped or the display context was reset. |
| **STATUS_INVALID_PARAMETER** | Parameters were validated and determined to be incorrect. |
| **STATUS_NO_MEMORY** | **D3DKMTPresent** could not complete because of insufficient memory. |
| **STATUS_GRAPHICS_ALLOCATION_INVALID** | The primary surface handle was invalidated because of a display mode change. If the OpenGL installable client driver (ICD) receives this error code, it should reopen or re-create the primary handle, replace all references in the command buffer to the old handle with the new handle, and then resubmit the buffer. |
| **STATUS_GRAPHICS_GPU_EXCEPTION_ON_DEVICE** | An error occurred on the rendering device context that the **hContext** member of [**D3DKMT_PRESENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_present) specifies. |

> [!NOTE]
> The **STATUS_GRAPHICS_GPU_EXCEPTION_ON_DEVICE** error code does not indicate the initiation of a Timeout Detection and Recovery (TDR) process or that the GPU stopped responding. For example, the DirectX graphics kernel subsystem puts a device into an error state if the display miniport driver indicated that a DMA buffer that was submitted from this device caused a fault or if the video memory manager could not page-in all of the allocations that are required for a DMA buffer even after splitting the DMA buffer. After a device is in an error state, it cannot perform any more operations and must be destroyed and re-created. The ICD can call the [D3DKMTGetDeviceState](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtgetdevicestate) function to determine a more precise reason for the error.

## Remarks

The **D3DKMTPresent** function might return STATUS_INVALID_PARAMETER, depending on the combination of parameter values (that is, values in members of the [**D3DKMT_PRESENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_present) structure that **pData** points to). The following list describes the most common combinations of parameter values that might cause **D3DKMTPresent** to return STATUS_INVALID PARAMETER:

* The **hDestination** member is non-**NULL** and at least one of the following conditions is true:
  * The **pSrcSubRects** member is **NULL**.
  * The **SubRectCnt** member is 0.
  * The **Blt** bit-field flag of the **Flags** member is not set.
  * The **SrcRectValid** bit-field flag of **Flags** is not set.
  * The **ColorFill** bit-field flag of **Flags** is set.
  * The **Flip**, **FlipDoNotFlip**, **FlipDoNotWait**, or **FlipRestart** bit-field flag of **Flags** is set.
  * The **SrcColorKey** or **DstColorKey** bit-field flag of **Flags** is set.
  * The **hSource** member is equal to **hDestination**.
  * The source and destination are not a primary surface.

* The **Flip** bit-field flag of **Flags** is set and at least one of the following conditions is true:
  * The **ColorFill** bit-field flag of **Flags** is set.
  * The **Blt** bit-field flag of **Flags** is set.
  * The **SrcColorKey** or **DstColorKey** bit-field flag of **Flags** is set.
  * The **SrcRectValid** or **DstRectValid** bit-field flag of **Flags** is set.
  * The **Rotate** bit-field flag of **Flags** is set.
  * The **RestrictVidPnSource** bit-field flag of **Flags** is set.
  * The source is not a primary surface.
  * The display miniport driver does not support the flip interval that the **FlipInterval** member specifies.
  * The [**D3DKMTSetDisplayMode**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtsetdisplaymode) function was not previously called.

* The **ColorFill** bit-field flag of **Flags** is set and one of the following conditions is true:
  * **pSrcSubRects** is **NULL**.
  * **SubRectCnt** is 0.
  * The **Blt** bit-field flag of **Flags** is set.
  * The **Flip**, **FlipDoNotFlip**, **FlipDoNotWait**, or **FlipRestart** bit-field flag of **Flags** is set.
  * The **SrcColorKey** or **DstColorKey** bit-field flag of **Flags** is set.
  * The **SrcRectValid** bit-field flag of **Flags** is set.

* The **Blt** bit-field flag of **Flags** is set and one of the following conditions is true:
  * **pSrcSubRects** is **NULL**.
  * **SubRectCnt** is 0.
  * The **ColorFill** bit-field flag of **Flags** is set.
  * The **Flip**, **FlipDoNotFlip**, **FlipDoNotWait**, or **FlipRestart** bit-field flag of **Flags** is set.

User-mode graphics drivers that call **D3DKMTPresent** for blit style present, with the **Blt** bit-field flag of **Flags** set, need to take special care to ensure that all previously submitted work to the context(s) being presented from is fully drainable. Failure to do so can result in the application deadlocking itself, or in some corner cases deadlocking the current user desktop. A context is fully drainable if it only contains waits on the GPU sync object where the corresponding signal has already been queued to the GPU scheduler database and where that signal itself is not behind another undrainable wait. In other words, if the user space of all processes in the system was paused immediately after the call to **D3DKMTPresent**, the wait would get satisfied once the dependent rendering chain already queued to the GPU scheduler would finish rendering. A driver must never call blit present on a context that is dependent on a GPU wait which is not currently satisfied and expected to be satisfied by some later operation originating from this or another process.

### Examples

The following code example demonstrates how an OpenGL ICD can use **D3DKMTPresent** to present data.

```cpp
HRESULT Present(D3DKMT_HANDLE hDevice,
                HWND hWnd,
                RECT* pSrcRect,
                 RECT* pDstRect)
{
    D3DKMT_PRESENT PresentData = {0};

    PresentData.hDevice = hDevice;
    PresentData.Flags.Blt =
    PresentData.Flags.DstRectValid =
    PresentData.Flags.SrcRectValid = TRUE;
    PresentData.hWindow = hWnd;
    PresentData.DstRect = *pDstRect;
    PresentData.SrcRect = *pSrcRect;
    PresentData.SubRectCnt = 1;
    PresentData.pSrcSubRects = pSrcRect;

    if (NT_SUCCESS((*pfnKTPresent)(&PresentData))) {
        return S_OK;
    }
    return E_FAIL;
}
```

## See also

[**D3DKMTGetDeviceState**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtgetdevicestate)

[**D3DKMTSetDisplayMode**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtsetdisplaymode)

[**D3DKMT_PRESENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_present)