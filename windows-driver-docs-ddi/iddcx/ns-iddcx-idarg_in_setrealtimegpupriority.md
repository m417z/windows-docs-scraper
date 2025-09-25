## Description

A **IDARG_IN_SETREALTIMEGPUPRIORITY** structure is passed to [**IddCxSetRealtimeGPUPriority**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxsetrealtimegpupriority) when an indirect display driver requests a bump in GPU priority.

## Members

### `pDevice`

[in] Pointer to an [**IDXGIDevice**](https://learn.microsoft.com/windows/win32/api/dxgi/nn-dxgi-idxgidevice) interface for the DXGI device that the caller is requesting realtime GPU priority for.

## See also

[**IddCxSetRealtimeGPUPriority**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxsetrealtimegpupriority)

[**IDXGIDevice**](https://learn.microsoft.com/windows/win32/api/dxgi/nn-dxgi-idxgidevice)