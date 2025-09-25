## Description

Gets the option with the given name.

## Parameters

### `bstrName` [in]

The name of the option.

### `bstrNamespaceUri` [in]

The namespace URI of the option.

### `ppOption` [out, retval]

The returned option.

## Return value

This method returns an **HRESULT** value, if the call was successful. Otherwise it returns the appropriate error code.

## Remarks

When the requested feature, option or property is not found, this method returns S_FALSE and sets a NULL pointer on the output object of the feature, option or property.

So if the [IPrintSchemaTicket](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintschematicket) object does not contain the specified feature, option or property, the app must obtain an [IPrintSchemaCapabilities](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintschemacapabilities) object and query it via [IPrintSchemaCapabilities::GetFeatureByKeyName](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nf-printerextension-iprintschemacapabilities-getfeaturebykeyname) or via [IPrintSchemaCapabilities::GetFeature](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nf-printerextension-iprintschemacapabilities-getfeature).

## See also

[IPrintSchemaCapabilities](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintschemacapabilities)

[IPrintSchemaFeature](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintschemafeature)

[IPrintSchemaOption](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintschemaoption)

[IPrintSchemaTicket](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintschematicket)