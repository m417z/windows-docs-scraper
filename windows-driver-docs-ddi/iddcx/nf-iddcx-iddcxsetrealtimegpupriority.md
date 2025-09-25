## Description

An indirect display driver (IDD) calls **IddCxSetRealtimeGPUPriority** to raise the GPU priority of a DirectX device to realtime.

## Parameters

### `SwapChainObject` [in]

An [**IDDCX_SWAPCHAIN**](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx-objects) object that represents the swapchain the provided DXGI device will process.

### `pIn` [in]

Pointer to a [**IDARG_IN_SETREALTIMEGPUPRIORITY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_setrealtimegpupriority) structure with additional input arguments about the DXGI device.

## Return value

**IddCxSetRealtimeGPUPriority** returns STATUS_SUCCESS (S_OK) if the call succeeds. Otherwise, it returns an [appropriate NTSTATUS error code](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) such as the following.

| Error code | Meaning |
| ---------- | ------- |
| E_INVALIDARG | An invalid swapchain object was provided. |
| E_NOTIMPL | The GPU priority boost is not supported. See Remarks. |

## Remarks

An IDD can call this function to ensure GPU work for processing a frame is completed in a timely manner.

On success the GPU priority for the provided DXGI device will be raised to realtime. This means any GPU work scheduled by this device will have higher priority than any regular application can set. The OS picks the exact realtime priority level to set; the chosen level in the realtime priority band might change in future OS releases.

Setting realtime priority is not supported on WDDM 1.*x* devices; **IddCxSetRealtimeGPUPriority** will return E_NOTIMPL for such devices.

## See also

[**IDARG_IN_SETREALTIMEGPUPRIORITY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_setrealtimegpupriority)