## Description

The **Value** (put_Value) property modifies the value of the [IPrintSchemaParameterInitializer](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintschemaparameterinitializer) object.

In PrintTicket XML, that's the value of the **psf:Value** child element for the **psf:ParameterInit** element.

This property is write-only.

## Parameters

### `pVar`

Defines the **VARIANT** parameter *pVar*.

## Return value

Returns an **HRESULT** value. If the property call was not successful, it returns the appropriate **HRESULT** error code.

## Remarks

The **Value** (put_Value) property passes the new value as a Variant. Here is what the receiving function expects in the Variant type, and where the function will look for the new value, depending on the different parameter data types:

| Parameter DataType | Variant type | Variant value |
|--|--|--|
| PrintSchemaParameterDataType_Integer | V_VT(pVar) is VT_I4 | V_I4(pVar) |
| PrintSchemaParameterDataType_NumericString | V_VT(pVar) is VT_BSTR | V_BSTR(pVar) |
| PrintSchemaParameterDataType_String | V_VT(pVar) is VT_BSTR | V_BSTR(pVar) |

If the input **Variant** type does not match the parameter data type as shown in the preceding table, then the put_Value property call will return **E_INVALIDARG**.

In the case of the **PrintSchemaParameterDataType_NumericString** parameter data type, the function will also validate that the V_BSTR(pVar) string only contains numeric characters. If the function finds any non-numeric characters, then the put_Value property call will return **E_INVALIDARG**.

## See also

[IPrintSchemaParameterInitializer](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintschemaparameterinitializer)