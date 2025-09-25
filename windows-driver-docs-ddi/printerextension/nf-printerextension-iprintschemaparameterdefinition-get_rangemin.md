## Description

The **RangeMin** property gets the minimum value of the allowed data range.

This property is read-only.

## Parameters

### `pRangeMin`

Defines the **INT** parameter *pRangeMin*.

## Return value

Returns an **HRESULT** value. If the property call was not successful, it returns the appropriate **HRESULT** error code.

## Remarks

For the **PrintSchemaParameterDataType_Integer** data type, the value returned by **RangeMin** maps to the **psf:MinValue** property value of the Print Schema parameter definition. This minimum value shows the minimum integer value that the driver supports.

For the **PrintSchemaParameterDataType_NumericString** and **PrintSchemaParameterDataType_String** data types, this maps to the **psf:MinLength** property value of the Print Schema parameter definition. This minimum value shows the minimum length of string that the driver supports.

## See also

[IPrintSchemaParameterDefinition](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintschemaparameterdefinition)