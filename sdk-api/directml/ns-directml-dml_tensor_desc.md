## Description

A generic container for a DirectML tensor description.

## Members

### `Type`

Type: [**DML_TENSOR_TYPE**](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_tensor_type)

The type of the tensor description. See [DML_TENSOR_TYPE](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_tensor_type) for the available types.

### `Desc`

Type: **const void***

A pointer to the tensor description. The type of the pointed-to struct must match the value specified in *Type*.