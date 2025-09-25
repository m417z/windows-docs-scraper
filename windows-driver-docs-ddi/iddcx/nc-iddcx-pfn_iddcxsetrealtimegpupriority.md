## Description

**PFN_IDDCXSETREALTIMEGPUPRIORITY** is a pointer to an OS callback function through which to raise the GPU priority of a DirectX device to realtime.

## Parameters

### `DriverGlobals` [in]

Pointer to an [**IDD_DRIVER_GLOBALS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idd_driver_globals) structure containing system-defined per-driver data.

### `SwapChainObject` [in]

An [**IDDCX_SWAPCHAIN**](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx-objects) object that represents the swapchain the provided DXGI device will process.

### `pIn` [in]

Pointer to a [**IDARG_IN_SETREALTIMEGPUPRIORITY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_setrealtimegpupriority) structure with additional input arguments about the DXGI device.

## Return value

If the routine succeeds it return S_OK. Otherwise, it returns an [appropriate NTSTATUS error code](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) such as the following.

| Error code | Meaning |
| ---------- | ------- |
| E_INVALIDARG | An invalid swapchain object was provided. |
| E_NOTIMPL | The GPU priority boost is not supported. See Remarks. |

## Remarks

An indirect display driver (IDD) should not use this pointer to directly call the function that it points to. IDDs should instead call [**IddCxSetRealtimeGPUPriority**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxsetrealtimegpupriority).

Setting realtime priority is not supported on WDDM 1.*x* devices; **IddCxSetRealtimeGPUPriority** will return E_NOTIMPL for such devices.

## See also

[**IddCxSetRealtimeGPUPriority**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxsetrealtimegpupriority)