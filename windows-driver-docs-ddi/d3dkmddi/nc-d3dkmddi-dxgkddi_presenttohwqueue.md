# DXGKDDI_PRESENTTOHWQUEUE callback function

## Description

Copies content from a source allocation, given a handle to a hardware queue.

## Parameters

### `hHwQueue`

Handle to the hardware queue that the DMA buffer will be submitted to.

### `pPresent`

A pointer to a [DXGKARG_PRESENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_present) structure that contains information about the copy operation.

## Return value

*DXGKDDI_PRESENTTOHWQUEUE* returns one of the following values:

|Return code|Description|
| -- | -- |
|STATUS_SUCCESS|Successfully copied the content.|
|STATUS_NO_MEMORY or STATUS_INSUFFICIENT_RESOURCES|Could not allocate memory that was required for it to complete.|
|STATUS_GRAPHICS_INSUFFICIENT_DMA_BUFFER|The current direct memory access (DMA) buffer is depleted.|
|STATUS_GRAPHICS_CANNOTCOLORCONVERT|The display miniport driver detected a bit-block transfer (bitblt) for color conversion that the device could not perform. The Microsoft Direct3D runtime prevents the application from continuing, and the application receives a failure to copy content.|
|STATUS_PRIVILEGED_INSTRUCTION|Detected nonprivileged instructions (that is, instructions that access memory beyond the privilege of the current central processing unit [CPU] process).|
|STATUS_ILLEGAL_INSTRUCTION|Detected instructions that graphics hardware cannot support.|
|STATUS_INVALID_HANDLE|Detected an invalid handle in the command buffer.|
|STATUS_GRAPHICS_GPU_EXCEPTION_ON_DEVICE|The display miniport driver detected an error in the DMA stream. The graphics context device is placed in a lost state if the driver returns this error code.|

## Prototype

```cpp
//Declaration

DXGKDDI_PRESENTTOHWQUEUE DxgkddiPresenttohwqueue;

// Definition

NTSTATUS DxgkddiPresenttohwqueue
(
	IN_CONST_HANDLE hHwQueue
	INOUT_PDXGKARG_PRESENT pPresent
)
{...}

```

## Remarks

WDDM synchronization class: [Zero level](https://learn.microsoft.com/windows-hardware/drivers/display/threading-and-synchronization-zero-level)

## See also