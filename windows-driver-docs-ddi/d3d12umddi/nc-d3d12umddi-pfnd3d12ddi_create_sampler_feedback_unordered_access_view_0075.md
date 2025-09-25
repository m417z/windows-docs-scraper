# PFND3D12DDI_CREATE_SAMPLER_FEEDBACK_UNORDERED_ACCESS_VIEW_0075 callback function

## Description

Used to create a sampler feedback with unordered access view.

## Parameters

### `hDrvDevice` [in]

A handle to the display device (graphics context).

### `hDrvTargetedResource` [in]

Handle to targeted resource.

### `hDrvFeedbackResource` [in]

Handle to feedback resource.

### `DestDescriptor` [in]

A [D3D12DDI_CPU_DESCRIPTOR_HANDLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_cpu_descriptor_handle) structure that defines the destination target.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CREATE_SAMPLER_FEEDBACK_UNORDERED_ACCESS_VIEW_0075 Pfnd3d12ddiCreateSamplerFeedbackUnorderedAccessView0075;

// Definition

VOID Pfnd3d12ddiCreateSamplerFeedbackUnorderedAccessView0075
(
    D3D12DDI_HDEVICE hDrvDevice,
    D3D12DDI_HRESOURCE hDrvTargetedResource,
    D3D12DDI_HRESOURCE hDrvFeedbackResource,
    D3D12DDI_CPU_DESCRIPTOR_HANDLE DestDescriptor
)
{...}

PFND3D12DDI_CREATE_SAMPLER_FEEDBACK_UNORDERED_ACCESS_VIEW_0075

```

## Remarks

See the [D3D Sampler Feedback Specification](https://microsoft.github.io/DirectX-Specs/d3d/SamplerFeedback.html) for more information.

## See also

[D3D12DDI_CPU_DESCRIPTOR_HANDLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_cpu_descriptor_handle)