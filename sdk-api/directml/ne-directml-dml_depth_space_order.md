## Description

Defines constants controlling the transform applied in the DirectML operators [DML_OPERATOR_DEPTH_TO_SPACE1](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_operator_type) and **DML_OPERATOR_SPACE_TO_DEPTH1**. These are used within the [DML_DEPTH_TO_SPACE1_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_depth_to_space1_operator_desc) and [DML_SPACE_TO_DEPTH1_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_space_to_depth1_operator_desc) structures.

## Constants

### `DML_DEPTH_SPACE_ORDER_DEPTH_COLUMN_ROW`

Causes tensors used in [DML_DEPTH_TO_SPACE1_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_depth_to_space1_operator_desc) and [DML_SPACE_TO_DEPTH1_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_space_to_depth1_operator_desc) to be interpreted with the following layouts, where dimensions in parenthesis are flattened together.

- **Depth version**: [Batch, (BlockHeight, BlockWidth, Channels), Height, Width]
- **Space version**: [Batch, Channels, (Height, BlockHeight), (Width, BlockWidth)]

### `DML_DEPTH_SPACE_ORDER_COLUMN_ROW_DEPTH`

Causes tensors used in [DML_DEPTH_TO_SPACE1_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_depth_to_space1_operator_desc) and [DML_SPACE_TO_DEPTH1_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_space_to_depth1_operator_desc) to be interpreted with the following layouts, where dimensions in parenthesis are flattened together.

- **Depth version**: [Batch, (Channels, BlockHeight, BlockWidth), Height, Width]
- **Space version**: [Batch, Channels, (Height, BlockHeight), (Width, BlockWidth)]

## Remarks

See [DML_DEPTH_TO_SPACE1_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_depth_to_space1_operator_desc) and [DML_SPACE_TO_DEPTH1_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_space_to_depth1_operator_desc) documentation for examples showing the effect of these values.

## See also
* [DML_DEPTH_TO_SPACE1_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_depth_to_space1_operator_desc)
* [DML_SPACE_TO_DEPTH1_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_space_to_depth1_operator_desc)

## Availability
This enumeration was introduced in `DML_FEATURE_LEVEL_2_1`.