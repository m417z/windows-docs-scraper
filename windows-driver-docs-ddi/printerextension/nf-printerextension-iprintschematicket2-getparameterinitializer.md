## Description

The **GetParameterInitializer** method retrieves the [IPrintSchemaParameterInitializer](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintschemaparameterinitializer) object, and it represents the `` element in the PrintTicket XML.

The keyword name and keyword namespace URI specify the **IPrintSchemaParameterInitializer** object to be retrieved.

## Parameters

### `bstrName` [in]

The keyword name.

### `bstrNamespaceUri` [in]

The keyword namespace URI.

### `ppParameterInitializer` [out, retval]

The [IPrintSchemaParameterInitializer](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintschemaparameterinitializer) object.

## Return value

The **GetParameterInitializer** method returns an **HRESULT** value. If the property call was not successful, it returns the appropriate **HRESULT** error code.

## See also

[IPrintSchemaParameterInitializer](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintschemaparameterinitializer)

[IPrintSchematicket2](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintschematicket2)