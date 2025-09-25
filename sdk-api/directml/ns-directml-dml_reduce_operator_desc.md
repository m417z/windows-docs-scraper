## Description

Outputs the reduction of elements (sum, product, minimum, and so on) within one or more dimensions of the input tensor.

Each output element is the result of applying a reduction function on a subset of the input tensor. A reduction function, such as *sum*, maps `N` input elements to a single output element. The input elements involved in each reduction are determined by the provided input axes: `N` is equal to the product of the sizes of the reduced axes. If all input axes are specified, then the operator performs a reduction on the entire input tensor and produces a single output element.

## Members

### `Function`

Type: [**DML_REDUCE_FUNCTION**](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_reduce_function)

Specifies the reduction function to apply to the input.

### `InputTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

The tensor to read from.

### `OutputTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

The tensor to write the results to. Each output element is the result of a reduction on a subset of elements from the *InputTensor*.

- *DimensionCount* must match *InputTensor.DimensionCount* (the rank of the input tensor is preserved).
- *Sizes* must match *InputTensor.Sizes*, except for dimensions included in the reduced *Axes*, which must be size 1.

### `AxisCount`

Type: [**UINT**](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)

The number of axes to reduce. This field determines the size of the *Axes* array.

### `Axes`

Type: \_Field\_size\_(AxisCount) **const [UINT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)***

The axes along which to reduce. Values must be in the range `[0, InputTensor.DimensionCount - 1]`.

## Examples

The following examples all use this same two-dimensional input tensor.

```
InputTensor: (Sizes:{3, 3}, DataType:FLOAT32)
[[1, 2, 3],
 [3, 0, 4],
 [2, 4, 2]]
```

### Example 1. Applying *sum* to columns

```
Function: DML_REDUCE_FUNCTION_SUM
AxisCount: 1
Axes: {0}
OutputTensor: (Sizes:{1, 3}, DataType:FLOAT32)
[[6,  // sum({1, 3, 2})
  6,  // sum({2, 0, 4})
  9]] // sum({3, 4, 2})
```

### Example 2. Applying *sum* to rows

```
Function: DML_REDUCE_FUNCTION_SUM
AxisCount: 1
Axes: {1}
OutputTensor: (Sizes:{3, 1}, DataType:FLOAT32)
[[6], // sum({1, 2, 3})
 [7], // sum({3, 0, 4})
 [8]] // sum({2, 4, 2})
```

### Example 3.Applying *sum* to all axes (the entire tensor)

```
Function: DML_REDUCE_FUNCTION_SUM
AxisCount: 2
Axes: {0, 1}
OutputTensor: (Sizes:{1, 1}, DataType:FLOAT32)
[[21]]  // sum({1, 2, 3, 3, 0, 4, 2, 5, 2})
```

## Availability
This operator was introduced in `DML_FEATURE_LEVEL_1_0`.

## Tensor constraints
* The input and output tensor data types must match except when using the ARGMAX and ARGMIN functions, which always output an integral data type.
* The output sizes must be the same as the input sizes except for the reduced axes, which must be 1.

## Tensor support according to function
### ARGMIN and ARGMAX
##### DML_FEATURE_LEVEL_4_1 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 1 to 8 | FLOAT32, FLOAT16, INT64, INT32, INT16, INT8, UINT64, UINT32, UINT16, UINT8 |
| OutputTensor | Output | 1 to 8 | INT64, INT32, UINT64, UINT32 |

#### DML_FEATURE_LEVEL_3_0 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 1 to 8 | FLOAT32, FLOAT16, INT32, INT16, INT8, UINT32, UINT16, UINT8 |
| OutputTensor | Output | 1 to 8 | INT64, INT32, UINT64, UINT32 |

#### DML_FEATURE_LEVEL_2_1 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 4 | FLOAT32, FLOAT16, INT32, INT16, INT8, UINT32, UINT16, UINT8 |
| OutputTensor | Output | 4 | UINT32 |

#### DML_FEATURE_LEVEL_1_0 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 4 | FLOAT32, FLOAT16 |
| OutputTensor | Output | 4 | UINT32 |

### AVERAGE, L2, LOG_SUM, and LOG_SUM_EXP
##### DML_FEATURE_LEVEL_3_0 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 1 to 8 | FLOAT32, FLOAT16 |
| OutputTensor | Output | 1 to 8 | FLOAT32, FLOAT16 |

##### DML_FEATURE_LEVEL_1_0 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 4 | FLOAT32, FLOAT16 |
| OutputTensor | Output | 4 | FLOAT32, FLOAT16 |

### L1 and SUM_SQUARE
##### DML_FEATURE_LEVEL_5_0 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 1 to 8 | FLOAT32, FLOAT16, INT64, INT32, UINT64, UINT32 |
| OutputTensor | Output | 1 to 8 | FLOAT32, FLOAT16, INT64, INT32, UINT64, UINT32 |

#### DML_FEATURE_LEVEL_3_0 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 1 to 8 | FLOAT32, FLOAT16 |
| OutputTensor | Output | 1 to 8 | FLOAT32, FLOAT16 |

#### DML_FEATURE_LEVEL_1_0 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 4 | FLOAT32, FLOAT16 |
| OutputTensor | Output | 4 | FLOAT32, FLOAT16 |

### MIN and MAX
##### DML_FEATURE_LEVEL_5_0 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 1 to 8 | FLOAT32, FLOAT16, INT64, INT32, INT16, INT8, UINT64, UINT32, UINT16, UINT8 |
| OutputTensor | Output | 1 to 8 | FLOAT32, FLOAT16, INT64, INT32, INT16, INT8, UINT64, UINT32, UINT16, UINT8 |

#### DML_FEATURE_LEVEL_3_0 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 1 to 8 | FLOAT32, FLOAT16, INT32, INT16, INT8, UINT32, UINT16, UINT8 |
| OutputTensor | Output | 1 to 8 | FLOAT32, FLOAT16, INT32, INT16, INT8, UINT32, UINT16, UINT8 |

#### DML_FEATURE_LEVEL_2_1 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 4 | FLOAT32, FLOAT16, INT32, UINT32 |
| OutputTensor | Output | 4 | FLOAT32, FLOAT16, INT32, UINT32 |

#### DML_FEATURE_LEVEL_1_0 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 4 | FLOAT32, FLOAT16 |
| OutputTensor | Output | 4 | FLOAT32, FLOAT16 |

### MULTIPLY and SUM
##### DML_FEATURE_LEVEL_5_0 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 1 to 8 | FLOAT32, FLOAT16, INT64, INT32, UINT64, UINT32 |
| OutputTensor | Output | 1 to 8 | FLOAT32, FLOAT16, INT64, INT32, UINT64, UINT32 |

#### DML_FEATURE_LEVEL_3_0 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 1 to 8 | FLOAT32, FLOAT16, INT32, UINT32 |
| OutputTensor | Output | 1 to 8 | FLOAT32, FLOAT16, INT32, UINT32 |

#### DML_FEATURE_LEVEL_2_1 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 4 | FLOAT32, FLOAT16, INT32, UINT32 |
| OutputTensor | Output | 4 | FLOAT32, FLOAT16, INT32, UINT32 |

#### DML_FEATURE_LEVEL_1_0 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 4 | FLOAT32, FLOAT16 |
| OutputTensor | Output | 4 | FLOAT32, FLOAT16 |

## See also

Feature level 3_0 introduced these stand-alone operators that supersede the functionality available with [DML_REDUCE_FUNCTION_ARGMAX](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_reduce_function) and **DML_REDUCE_FUNCTION_ARGMIN**.

* [DML_ARGMAX_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_argmax_operator_desc)
* [DML_ARGMIN_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_argmin_operator_desc)