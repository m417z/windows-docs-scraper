## Description

The **Value** (get_Value) property gets the current value of the [IPrintSchemaParameterInitializer](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintschemaparameterinitializer) object.

 In PrintTicket XML, that is the value of the **psf:Value** child element for the **psf:ParameterInit** element.

This property is read-only.

## Parameters

### `pVar`

Defines the **VARIANT** parameter *pVar*.

## Return value

Returns an **HRESULT** value. If the property call was not successful, it returns the appropriate **HRESULT** error code.

## Remarks

The **Value** (get_Value) property returns the current value of the **IPrintSchemaParameterInitializer** object in the form of a Variant variable. Here's how the value and type are stored in the Variant for the different parameter data types:

| Parameter DataType | Variant type | Variant value |
|--|--|--|
| PrintSchemaParameterDataType_Integer | V_VT(pVar) is VT_I4 | V_I4(pVar) |
| PrintSchemaParameterDataType_NumericString | V_VT(pVar) is VT_BSTR | V_BSTR(pVar) |
| PrintSchemaParameterDataType_String | V_VT(pVar) is VT_BSTR | V_BSTR(pVar) |

## See also

[IPrintSchemaParameterInitializer](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintschemaparameterinitializer)