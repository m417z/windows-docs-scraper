## Description

The PrintSchemaParameterDataType enumeration identifies the allowed data types for the Print Schema parameter.

## Constants

### `PrintSchemaParameterDataType_Integer`

Integer data type.
This maps to the Print Schema's IntegerParamType parameters.

### `PrintSchemaParameterDataType_NumericString`

String data type with only numeric chars allowed.
This maps to the Print Schema's StringParamType parameters, with UnitType = "numeric".

### `PrintSchemaParameterDataType_String`

String data type with arbitrary chars allowed.
This maps to the Print Schema's StringParamType parameters, with UnitType not equal to "numeric".

## See also

[IPrintSchemaParameterDefinition::DataType](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nf-printerextension-iprintschemaparameterdefinition-get_datatype)