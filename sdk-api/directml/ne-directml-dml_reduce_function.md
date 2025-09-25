## Description

Defines constants that specify the specific reduction algorithm to use for the DirectML reduce operator (as described by the [DML_REDUCE_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_reduce_operator_desc) structure).

## Constants

### `DML_REDUCE_FUNCTION_ARGMAX`

Indicates a reduction function that computes the indices of the max elements of the input tensor's elements along the specified axis, int32 {i j k ..} = maxindex(X Y Z …).

### `DML_REDUCE_FUNCTION_ARGMIN`

Indicates a reduction function that computes the indices of the min elements of the input tensor's elements along the specified axis, int32 {i j k ..} = minindex(X Y Z …).

### `DML_REDUCE_FUNCTION_AVERAGE`

Indicates a reduction function that computes the mean of the input tensor's elements along the specified axes, x = (x1 + x2 + ... + xn) / n.

### `DML_REDUCE_FUNCTION_L1`

Indicates a reduction function that computes the L1 norm of the input tensor's elements along the specified axes, x = \|x1\| + \|x2\| + ... + \|xn\|.

### `DML_REDUCE_FUNCTION_L2`

Indicates a reduction function that computes the L2 norm of the input tensor's elements along the specified axes, x = sqrt(x1^2 + x2^2 + ... + xn^2).

### `DML_REDUCE_FUNCTION_LOG_SUM`

Indicates a reduction function that computes the log sum of the input tensor's elements along the specified axes, x = log(x1 + x2 + ... + xn).

### `DML_REDUCE_FUNCTION_LOG_SUM_EXP`

Indicates a reduction function that computes the log sum exponent of the input tensor's elements along the specified axes, x = log(exp(x1) + exp(x2) + ... + exp(xn)).

### `DML_REDUCE_FUNCTION_MAX`

Indicates a reduction function that computes the max of the input tensor's elements along the specified axes, x = max(max(max(x1, x2), x3), ..., xn).

### `DML_REDUCE_FUNCTION_MIN`

Indicates a reduction function that computes the min of the input tensor's elements along the specified axes, x = min(min(min(x1, x2), x3), ..., xn).

### `DML_REDUCE_FUNCTION_MULTIPLY`

Indicates a reduction function that computes the product of the input tensor's elements along the specified axes, x = (x1 * x2 * ... * xn).

### `DML_REDUCE_FUNCTION_SUM`

Indicates a reduction function that computes the sum of the input tensor's elements along the specified axes, x = (x1 + x2 + ... + xn).

### `DML_REDUCE_FUNCTION_SUM_SQUARE`

Indicates a reduction function that computes the sum square of the input tensor's elements along the specified axes, x = x1^2 + x2^2 + ... + xn^2.

## See also

* [DML_REDUCE_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_reduce_operator_desc)