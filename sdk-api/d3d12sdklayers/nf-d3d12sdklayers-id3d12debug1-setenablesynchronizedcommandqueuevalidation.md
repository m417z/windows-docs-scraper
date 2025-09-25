# ID3D12Debug1::SetEnableSynchronizedCommandQueueValidation

## Description

Enables or disables dependent command queue synchronization when using a D3D12 device with the debug layer enabled.

## Parameters

### `Enable`

Type: **BOOL**

TRUE to enable Dependent Command Queue Synchronization, otherwise FALSE.

## Remarks

Dependent Command Queue Synchronization is a D3D12 Debug Layer feature that gives the debug layer the ability to track resource states more accurately when enabled. Dependent Command Queue Synchronization is enabled by default.

When Dependent Command Queue Synchronization is enabled, the debug layer holds back actual submission of GPU work until all outstanding fence [Wait](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12commandqueue-wait) conditions are met. This gives the debug layer the ability to make reasonable assumptions about GPU state (such as resource states) on the CPU-timeline when multiple command queues are potentially doing concurrent work.

With Dependent Command Queue Synchronization disabled, all resource states tracked by the debug layer are cleared each time [ID3D12CommandQueue::Signal](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12commandqueue-signal) is called. This results in significantly less useful resource state validation.

Disabling Dependent Command Queue Synchronization may reduce some debug layer performance overhead when using multiple command queues. However, it is suggested to leave it enabled unless this overhead is problematic. Note that applications that use only a single command queue will see no performance changes with Dependent Command Queue Synchronization disabled.

## See also

[ID3D12Debug1](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/nn-d3d12sdklayers-id3d12debug1)