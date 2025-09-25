# DML_OPERATOR_DESC structure

## Description

A generic container for an operator description. You construct DirectML operators using the parameters specified
in this struct. See [IDMLDevice::CreateOperator](https://learn.microsoft.com/windows/win32/api/directml/nf-directml-idmldevice-createoperator) for additional details.

## Members

### `Type`

Type: [**DML_OPERATOR_TYPE**](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_operator_type)

The type of the operator description. See [DML_OPERATOR_TYPE](https://msdn.microsoft.com/2D66A3DB-FE61-4EC2-B626-DD008FF14802) for the available types.

### `Desc`

Type: **const void***

A pointer to the operator description. The type of the pointed-to struct must match the value specified in *Type.*