# WINML_RESOURCE_BINDING_DESC structure

## Description

**These APIs have been deprecated and should no longer be used:** Please use [Windows.AI.MachineLearning](https://learn.microsoft.com/uwp/api/windows.ai.machinelearning) instead.

Contains description properties of the resource binding.

## Members

### `ElementType`

A [WINML_TENSOR_DATA_TYPE](https://learn.microsoft.com/windows/desktop/api/winml/ne-winml-winml_tensor_data_type) containing the element tensor data type.

### `NumDimensions`

The resource dimension count.

### `pShape`

A pointer to the shape of the resource.

### `pResource`

A pointer to an [ID3D12Resource](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12resource) describing the D3D12 resource.