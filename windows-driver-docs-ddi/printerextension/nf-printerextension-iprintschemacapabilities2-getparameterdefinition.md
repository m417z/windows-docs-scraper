## Description

The **GetParameterDefinition** method retrieves the [IPrintSchemaParameterDefinition](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintschemaparameterdefinition) object, and it represents the **psf:ParameterDef** element in the PrintCapabilites XML.

 The keyword name and keyword namespace URI specify the **IPrintSchemaParameterDefinition** object to be retrieved.

## Parameters

### `bstrName` [in]

The keyword name

### `bstrNamespaceUri` [in]

The keyword namespace URI

### `ppParameterDefinition` [out, retval]

The **IPrintSchemaParameterDefinition** object

## Return value

The **GetParameterDefinition** method returns an **HRESULT** value. If the property call was not successful, it returns the appropriate **HRESULT** error code.

## Remarks

To be consistent with [IPrintSchemaCapabilities::GetFeature](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nf-printerextension-iprintschemacapabilities-getfeature), the **GetParameterDefinition** method works for any **psf:ParameterDef** element that is defined in the public keyword namespaces. The **GetParameterDefinition** method also works for any IHV-defined private keyword namespace that uses either the StringParamType or the IntegerParamType data type.

When you use the **psf:ParameterDef** element with the QNameParamType or the DecimalParamType data type, **GetParameterDefinition** will return HRESULT_FROM_WIN32 (ERROR_NOT_SUPPORTED).

For more information about the data types that you can use with the **psf:ParameterDef** element, see section 2.1.3.1 of the [Print Schema Specification](https://download.microsoft.com/download/d/e/c/deca6e6b-3e81-48e7-b7ef-6d92a547d03c/print-schema-spec-2-0.zip).

## See also

[IPrintSchemaCapabilities2](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintschemacapabilities2)

[IPrintSchemaParameterDefinition](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintschemaparameterdefinition)

[Print Schema Specification](https://download.microsoft.com/download/d/e/c/deca6e6b-3e81-48e7-b7ef-6d92a547d03c/print-schema-spec-2-0.zip)