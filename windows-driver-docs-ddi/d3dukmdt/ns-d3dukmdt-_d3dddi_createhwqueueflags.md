# D3DDDI_CREATEHWQUEUEFLAGS structure

## Description

The **D3DDDI_CREATEHWQUEUEFLAGS** structure specifies flags to use when creating a hardware queue.

## Members

### `DisableGpuTimeout`

When set, indicates to the OS that the hardware queue being created is expected to submit DMA buffers that can take longer than 2 seconds to complete on the GPU, and consequently GPU timeout should be disabled.

### `NoBroadcastSignal`

When set, indicates to the OS that the hardware queue being created does not have application observable behavior, and it should not participate in D3D12 command queue fence broadcast signal operation. This flag was introduced in Windows 10, version 2004.

### `NoBroadcastWait`

When set, indicates to the OS that the hardware queue being created does not have application observable behavior, and it should not be blocked behind in D3D12 command queue fence wait operation. This flag was introduced in Windows 10, version 2004.

### `NoKmdAccess`

Reserved for system use.

### `UserModeSubmission`

When set, indicates to the OS that the hardware queue being created uses the user-mode submission model. Hardware queues created using this flag can't use the regular kernel-mode work submission path and must rely on the doorbell mechanism for work submission on the queue.

### `NativeProgressFence`

When set, indicates that the [**DXGKARG_CREATEHWQUEUE::hHwQueueProgressFence**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_createhwqueue) handle points to the driver handle of a native GPU fence object previously created using [**DxgkDdiCreateNativeFence**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createnativefence). For more information, see [Native GPU fence objects](https://learn.microsoft.com/windows-hardware/drivers/display/native-gpu-fence-objects). Available starting with Windows 11, version 24H2.

### `TestQueue`

When set, indicates that the hardware queue being created is a test queue for [kernel-mode testing](https://learn.microsoft.com/windows-hardware/drivers/display/kernel-mode-testing-of-wddm-features). Available starting with Windows 11, version 24H2.

### `Reserved`

Reserved for system use.

### `Value`

This value can be used to operate over the structure members collectively.

## See also

[**DxgkDdiCreateHwQueue**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createhwqueue)