# ID3D12CommandQueue::GetClockCalibration

## Description

This method samples the CPU and GPU timestamp counters at the same moment in time.

## Parameters

### `pGpuTimestamp` [out]

Type: **UINT64***

The value of the GPU timestamp counter.

### `pCpuTimestamp` [out]

Type: **UINT64***

The value of the CPU timestamp counter.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the [Direct3D 12 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d12/d3d12-graphics-reference-returnvalues).

## Remarks

For more information, refer to [Timing](https://learn.microsoft.com/windows/desktop/direct3d12/timing).

## See also

[ID3D12CommandQueue](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12commandqueue)