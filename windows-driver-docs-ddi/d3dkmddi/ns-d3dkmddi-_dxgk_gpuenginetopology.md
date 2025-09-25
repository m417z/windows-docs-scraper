# _DXGK_GPUENGINETOPOLOGY structure

## Description

The DXGK_GPUENGINETOPOLOGY structure describes the graphics processing unit (GPU)-engine topology that a driver can support.

## Members

### `NbAsymetricProcessingNodes` [out]

The number of parallel engines that the GPU supports. If the driver does not set the **MultiEngineAware** bit-field flag in the **SchedulingCaps** member of the [DXGK_DRIVERCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_drivercaps) structure, the Microsoft DirectX graphics kernel subsystem ignores the setting of **NbAsymetricProcessingNodes**.

### `Reserved` [out]

An array of 32-bit values that are reserved for future use. The **DXGK_MAX_ASYMETRICAL_PROCESSING_NODES** constant, which is defined as 64, indicates the maximum number of asymmetrical processing nodes that the driver can signal.

## See also

[DXGK_DRIVERCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_drivercaps)