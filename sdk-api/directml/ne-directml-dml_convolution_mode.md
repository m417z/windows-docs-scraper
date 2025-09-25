## Description

Defines constants that specify a mode for the DirectML convolution operator (as described by the [DML_CONVOLUTION_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_convolution_operator_desc) structure).

## Constants

### `DML_CONVOLUTION_MODE_CONVOLUTION`

Specifies the convolution mode. When used along with [DML_CONVOLUTION_DIRECTION_FORWARD](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_convolution_direction), this flips the filter along the height and width axes.

### `DML_CONVOLUTION_MODE_CROSS_CORRELATION`

Specifies the cross-correlation mode. If in doubt, use this mode—it is appropriate for the vast majority of machine learning (ML) model inference. When used along with [DML_CONVOLUTION_DIRECTION_BACKWARD](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_convolution_direction), this flips the filter along the height and width axes.

## See also

[DML_CONVOLUTION_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_convolution_operator_desc)