## Description

Performs a (standard layers) one-layer gated recurrent unit (GRU) function on the input. This operator uses multiple gates to perform this layer. These gates are performed multiple times in a loop dictated by the sequence length dimension and the *SequenceLengthsTensor*.

### Equation for the forward direction

![equation for the forward direction](https://learn.microsoft.com/windows/win32/api/directml/images/gru_forward.png)

### Equation for the backward direction

![equation for the backward direction](https://learn.microsoft.com/windows/win32/api/directml/images/gru_backward.png)

### Equation legend

![equation legend](https://learn.microsoft.com/windows/win32/api/directml/images/gru_legend.png)

## Members

### `InputTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

A tensor containing the input data, X. Packed (and potentially padded) into one 4D tensor with the *Sizes* of `{ 1, seq_length, batch_size, input_size }`. seq_length is the dimension that is mapped to the index, t. The tensor doesn't support the **DML_TENSOR_FLAG_OWNED_BY_DML** flag.

### `WeightTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

A tensor containing the weight data, W. Concatenation of W_[zrh] and W_B[zrh] (if bidirectional). The tensor has *Sizes* `{ 1, num_directions, 3 * hidden_size, input_size }`. The tensor doesn't support the **DML_TENSOR_FLAG_OWNED_BY_DML** flag.

### `RecurrenceTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

A tensor containing the recurrence data, R. Concatenation of R_[zrh] and R_B[zrh] (if bidirectional). The tensor has *Sizes* `{ 1, num_directions, 3 * hidden_size, hidden_size }`. The tensor doesn't support the **DML_TENSOR_FLAG_OWNED_BY_DML** flag.

### `BiasTensor`

Type: \_Maybenull\_ **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

An optional tensor containing the bias data, B. Concatenation of (W_b[zrh], R_b[zrh]) and (W_Bb[zrh], R_Bb[zrh]) (if bidirectional). The tensor has *Sizes* `{ 1, 1, num_directions, 6 * hidden_size }`. The tensor doesn't support the **DML_TENSOR_FLAG_OWNED_BY_DML** flag.

### `HiddenInitTensor`

Type: \_Maybenull\_ **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

An optional tensor containing the hidden node initializer tensor, H_t-1 for the first loop index t. If not specified, then defaults to 0. This tensor has *Sizes* `{ 1, num_directions, batch_size, hidden_size }`. The tensor doesn't support the **DML_TENSOR_FLAG_OWNED_BY_DML** flag.

### `SequenceLengthsTensor`

Type: \_Maybenull\_ **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

An optional tensor containing an independent seq_length for each element in the batch. If not specified, then all sequences in the batch have length seq_length. This tensor has *Sizes* `{ 1, 1, 1, batch_size }`. The tensor doesn't support the **DML_TENSOR_FLAG_OWNED_BY_DML** flag.

### `OutputSequenceTensor`

Type: \_Maybenull\_ **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

An optional tensor with which to write the concatenation of all the intermediate output values of the hidden nodes, H_t. This tensor has *Sizes* `{ seq_length, num_directions, batch_size, hidden_size }`. seq_length is mapped to the loop index t.

### `OutputSingleTensor`

Type: \_Maybenull\_ **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

An optional tensor with which to write the last output value of the hidden nodes, H_t. This tensor has *Sizes* `{ 1, num_directions, batch_size, hidden_size }`.

### `ActivationDescCount`

Type: [**UINT**](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)

This field determines the size of the *ActivationDescs* array.

### `ActivationDescs`

Type: \_Field\_size\_(ActivationDescCount) **const [DML_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_operator_desc)\***

An array of [DML_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_operator_desc) containing the descriptions of the activation operators, f() and g(). Both f() and g() are defined independently of direction, meaning that if [DML_RECURRENT_NETWORK_DIRECTION_FORWARD](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_recurrent_network_direction) or **DML_RECURRENT_NETWORK_DIRECTION_BACKWARD** are supplied in *Direction*, then two activations must be provided. If **DML_RECURRENT_NETWORK_DIRECTION_BIDIRECTIONAL** is supplied, then four activations must be provided. For bidirectional, activations must be provided f() and g() for forward followed by f() and g() for backwards.

### `Direction`

Type: **const [DML_RECURRENT_NETWORK_DIRECTION](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_recurrent_network_direction)\***

The direction of the operator—forward, backwards, or bidirectional.

### `LinearBeforeReset`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**TRUE** to specify that, when computing the output of the hidden gate, the linear transformation should be applied before multiplying by the output of the reset gate. Otherwise, **FALSE**.

## Availability
This operator was introduced in `DML_FEATURE_LEVEL_1_0`.

## Tensor constraints
*BiasTensor*, *HiddenInitTensor*, *InputTensor*, *OutputSequenceTensor*, *OutputSingleTensor*, *RecurrenceTensor*, and *WeightTensor* must have the same *DataType*.

## Tensor support
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 4 | FLOAT32, FLOAT16 |
| WeightTensor | Input | 4 | FLOAT32, FLOAT16 |
| RecurrenceTensor | Input | 4 | FLOAT32, FLOAT16 |
| BiasTensor | Optional input | 4 | FLOAT32, FLOAT16 |
| HiddenInitTensor | Optional input | 4 | FLOAT32, FLOAT16 |
| SequenceLengthsTensor | Optional input | 4 | UINT32 |
| OutputSequenceTensor | Optional output | 4 | FLOAT32, FLOAT16 |
| OutputSingleTensor | Optional output | 4 | FLOAT32, FLOAT16 |