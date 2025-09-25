## Description

Gets a named feature from the PrintCapabilities, by name and full namespace URI.

## Parameters

### `bstrName` [in]

The base value of the "name" attribute of the Feature element. For example, for the Print Schema feature, the tag looks like this , showing a base value of "JobOutputBin".

### `bstrNamespaceUri` [in]

The namespace URI value of the "name" attribute of the Feature element. For example, for the Print Schema feature, the tag looks like this , with a base name value of "JobOutputBin", and the namespace URI of the public Print Schema is "https://schemas.microsoft.com/windows/2003/08/printing/printschemakeywords".
If the feature is not defined in the public Print Schema, then this should be the URI of the private namespace that defines the feature.

### `ppFeature` [out, retval]

The returned feature.

## Return value

This method returns an **HRESULT** value.

## Remarks

When the requested feature, option or property is not found, this method returns S_FALSE and sets a NULL pointer on the output object of the feature, option or property.

So if the [IPrintSchemaTicket](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintschematicket) object does not contain the specified feature, option or property, the app must obtain an [IPrintSchemaCapabilities](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintschemacapabilities) object and query it via [IPrintSchemaCapabilities::GetFeatureByKeyName](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nf-printerextension-iprintschemacapabilities-getfeaturebykeyname) or via **IPrintSchemaCapabilities::GetFeature**.

## See also

[IPrintSchemaCapabilities](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintschemacapabilities)

[IPrintSchemaFeature](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintschemafeature)

[IPrintSchemaTicket](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintschematicket)