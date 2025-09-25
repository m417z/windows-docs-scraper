# _D3DKMT_SUBMITCOMMANDFLAGS structure

## Description

Structure that identifies, in bit-field flags, information about a direct memory access (DMA) buffer to submit to the graphics processing unit (GPU).

## Members

### `NullRendering` [in]

A UINT value that specifies whether the driver should simulate the insertion of the DMA buffer into the ring (that is, whether the driver should generate the fence interrupt at the end of the DMA buffer); however, the driver should not actually run (render) the DMA buffer.

### `PresentRedirected` [in]

A UINT value that specifies whether the DMA buffer contains a redirected present operation, which is a present to a shared allocation that belongs to the Display Windows Manager.

### `Reserved`

Reserved for internal use.

## Remarks

## See also