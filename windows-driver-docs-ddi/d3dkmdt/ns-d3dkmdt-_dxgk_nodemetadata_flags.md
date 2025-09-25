# DXGK_NODEMETADATA_FLAGS structure

## Description

The **DXGK_NODEMETADATA_FLAGS** structure describes the capabilities of an engine on a GPU node.

## Members

### `ContextSchedulingSupported`

The engine supports the context-based scheduling model.

### `RingBufferFenceRelease`

The engine supports ring buffer fence release. Supported starting with Windows 10, version 1809.

### `SupportTrackedWorkload`

The engine supports tracked workloads. Available starting with Windows 10, version 1809.

### `UserModeSubmission`

The engine supports [user-mode work submission](https://learn.microsoft.com/windows-hardware/drivers/display/user-mode-work-submission). Supported starting with Windows 11, version 24H2.

### `SupportBuildTestCommandBuffer`

The engine supports [kernel-mode testing](https://learn.microsoft.com/windows-hardware/drivers/display/kernel-mode-testing-of-wddm-features). Supported starting with Windows 11, version 24H2.

### `MaxInFlightHwQueueBuffers`

The maximum number of command buffers submitted by the hardware scheduler to the kernel-mode driver. A value of zero indicates no limit. Available starting with Windows 10, version 1809.

### `Reserved`

Reserved.

### `Value`

An alternative way to access the structure members.

## See also

[**DXGK_NODEMETADATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgk_nodemetadata)

[**DXGKARG_GETNODEMETADATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgk_nodemetadata)

[**DxgkDdiGetNodeMetadata**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_getnodemetadata)