# ID3D12CommandQueue::GetTimestampFrequency

## Description

This method is used to determine the rate at which the GPU timestamp counter increments.

## Parameters

### `pFrequency` [out]

Type: **UINT64***

The GPU timestamp counter frequency (in ticks/second).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the [Direct3D 12 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d12/d3d12-graphics-reference-returnvalues).

## Remarks

For more information, refer to [Timing](https://learn.microsoft.com/windows/desktop/direct3d12/timing).

## See also

[ID3D12CommandQueue](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12commandqueue)