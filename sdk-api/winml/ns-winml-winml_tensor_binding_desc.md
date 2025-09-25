# WINML_TENSOR_BINDING_DESC structure

## Description

**These APIs have been deprecated and should no longer be used:** Please use [Windows.AI.MachineLearning](https://learn.microsoft.com/uwp/api/windows.ai.machinelearning) instead.

Contains description properties of the tensor binding.

## Members

### `DataType`

A [WINML_TENSOR_DATA_TYPE](https://learn.microsoft.com/windows/desktop/api/winml/ne-winml-winml_tensor_data_type) containing the WinML tensor data type.

### `NumDimensions`

The WinML tensor dimension count.

### `pShape`

A pointer to the shape of the WinML tensor.

### `DataSize`

The size of tensor data in bytes.

### `pData`

Pointer to the tensor data.