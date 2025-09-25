## Description

The **RangeMax** property gets the maximum value of the allowed data range.

This property is read-only.

## Parameters

### `pRangeMax`

Defines the **INT** parameter *pRangeMax*.

## Return value

Returns an **HRESULT** value. If the property call was not successful, it returns the appropriate **HRESULT** error code.

## Remarks

For the **PrintSchemaParameterDataType_Integer** data type, the value returned by **RangeMax** maps to the **psf:MaxValue** property value of the Print Schema parameter definition. This maximum value shows the maximum integer value that the driver supports.

For the **PrintSchemaParameterDataType_NumericString** and **PrintSchemaParameterDataType_String** data types, this maps to the **psf:MaxLength** property value of the Print Schema parameter definition. This maximum value shows the maximum length of string that the driver supports.

## See also

[IPrintSchemaParameterDefinition](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintschemaparameterdefinition)