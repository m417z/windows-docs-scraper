## Description

Describes a tensor that will be stored in a Direct3D 12 buffer resource. The corresponding tensor type is [DML_TENSOR_TYPE_BUFFER](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_tensor_type), and the corresponding binding type is [DML_BINDING_TYPE_BUFFER](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_binding_type).

## Members

### `DataType`

Type: [**DML_TENSOR_DATA_TYPE**](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_tensor_data_type)

The type of the values in the tensor.

### `Flags`

Type: [**DML_TENSOR_FLAGS**](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_tensor_flags)

Specifies additional options for the tensor.

### `DimensionCount`

Type: [**UINT**](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)

The number of dimensions of the tensor. This member determines the size of the *Sizes* and *Strides* arrays (if provided). In DirectML, the dimension count may range from 1 up to 8, depending on the operator. Most operators support at least 4 dimensions.

### `Sizes`

Type: **const [UINT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)***

The size, in elements, of each dimension in the tensor. Specifying a size of zero in any dimension is invalid, and will result in an error. For operators where the axes have semantic meaning (for example, batch, channel, depth, height, width), the *Sizes* member is always specified in the order {N, C, H, W} if *DimensionCount* is 4, and {N, C, D, H, W} if *DimensionCount* is 5. Otherwise, the dimensions generally have no particular meaning.

### `Strides`

Type: **const [UINT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)***

Optional. Determines the number of elements (not bytes) to linearly traverse in order to reach the next element in that dimension. For example, a stride of 5 in dimension 1 means that the distance between elements (n) and (n+1) in that dimension is 5 elements when traversing the buffer linearly. For operators where the axes have semantic meaning (for example, batch, channel, depth, height, width), the *Strides* member is always specified in the order {N, C, H, W} if *DimensionCount* is 4, and {N, C, D, H, W} if *DimensionCount* is 5.

*Strides* can be used to express broadcasting (by specifying a stride of 0) as well as padding (for example, by using a stride larger than the physical size of a row, to pad the end of a row).

If *Strides* is not specified, each dimension in the tensor is considered to be contiguously packed, with no additional padding.

### `TotalTensorSizeInBytes`

Type: **[UINT64](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Defines a minimum size in bytes for the buffer that will contain this tensor. *TotalTensorSizeInBytes* must be at least as large as the minimum implied size given the sizes, strides, and data type of the tensor. You can calculate the minimum implied size by calling the [DMLCalcBufferTensorSize](https://learn.microsoft.com/windows/ai/directml/dml-helper-functions#dmlcalcbuffertensorsize) utility free function.

Providing a *TotalTensorSizeInBytes* that is larger than the minimum implied size may enable additional optimizations by allowing DirectML to elide bounds checking in some cases if the *TotalTensorSizeInBytes* defines sufficient padding beyond the end of the tensor data.

When binding this tensor, the size of the buffer range must be at least as large as the *TotalTensorSizeInBytes*. For output tensors, this has the additional effect of permitting DirectML to write to any memory within the *TotalTensorSizeInBytes*. That is, your application mustn't assume that DirectML will preserve any padding bytes inside output tensors that are inside the *TotalTensorSizeInBytes*.

The total size of a buffer tensor may not exceed (2^32 - 1) elements—for example, 16GB for a **FLOAT32** tensor.

### `GuaranteedBaseOffsetAlignment`

Type: [**UINT**](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)

Optional. Defines a minimum guaranteed alignment in bytes for the base offset of the buffer range that will contain this tensor, or 0 to provide no minimum guaranteed alignment. If specified, this value must be a power of two that is at least as large as the element size.

When binding this tensor, the offset in bytes of the buffer range from the start of the buffer must be a multiple of the *GuaranteedBaseOffsetAlignment*, if provided.

Buffer tensors always have a minimum alignment of 16 bytes. However, providing a larger value for the *GuaranteedBaseOffsetAlignment* may allow DirectML to achieve better performance, because a larger alignment enables the use of vectorized load/store instructions.

Although this member is optional, for best performance we recommend that you align tensors to boundaries of 32 bytes or more, where possible.

## See also

[Binding in DirectML](https://learn.microsoft.com/windows/ai/directml/dml-binding)