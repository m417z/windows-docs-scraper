## Description

Checks each element of *InputTensor* for IEEE-754 -inf, inf, or both, depending on the given *InfinityMode*, and places the result (1 for true, 0 for false) into the corresponding element of *OutputTensor*.

```
f(x) = isinf(x) && (
       (x > 0 && InfinityMode == DML_IS_INFINITY_MODE_POSITIVE) ||
       (x < 0 && InfinityMode == DML_IS_INFINITY_MODE_NEGATIVE) ||
                 InfinityMode == DML_IS_INFINITY_MODE_EITHER)
```

## Members

### `InputTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

The input tensor to read from.

### `OutputTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

The output tensor to write the results to.

### `InfinityMode`

Type: **[DML_IS_INFINITY_MODE](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_is_infinity_mode)**

A [DML_IS_INFINITY_MODE](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_is_infinity_mode) determining the sign of the infinity to check for.

* If **DML_IS_INFINITY_MODE_EITHER**, then 1 will be returned if the element is -inf or inf, otherwise 0.
* If **DML_IS_INFINITY_MODE_POSITIVE**, then 1 will be returned if the element is inf, otherwise 0.
* If **DML_IS_INFINITY_MODE_NEGATIVE**`, then 1 will be returned if the element is -inf, otherwise 0.

## Remarks

## Availability
This operator was introduced in `DML_FEATURE_LEVEL_2_1`.

## Tensor constraints
*InputTensor* and *OutputTensor* must have the same *DimensionCount* and *Sizes*.

## Tensor support
### DML_FEATURE_LEVEL_3_0 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 1 to 8 | FLOAT32, FLOAT16 |
| OutputTensor | Output | 1 to 8 | UINT8 |

### DML_FEATURE_LEVEL_2_1 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 4 | FLOAT32, FLOAT16 |
| OutputTensor | Output | 4 | UINT8 |

## See also