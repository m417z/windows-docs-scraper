## Description

Gets the XML node for the value child element of a Property or a ScoredProperty element with the given name.

## Parameters

### `bstrName` [in]

The base value of the name attribute of the Property or the ScoredProperty element.

### `bstrNamespaceUri` [in]

The namespace URI value of the name attribute of the Property or the ScoredProperty element.

### `ppXmlValueNode`

The XML node for the value child element.

## Return value

Returns an **HRESULT** value. If the method call was not successful, it returns the appropriate **HRESULT** error code.

## Remarks

When the requested feature, option or property is not found, this method returns S_FALSE and sets a NULL pointer on the output object of the feature, option or property.

If the [IPrintSchemaTicket](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintschematicket) object does not contain the specified feature, option or property, the app must obtain an [IPrintSchemaCapabilities](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintschemacapabilities) object and query it via [IPrintSchemaCapabilities::GetFeatureByKeyName](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nf-printerextension-iprintschemacapabilities-getfeaturebykeyname) or via [IPrintSchemaCapabilities::GetFeature](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nf-printerextension-iprintschemacapabilities-getfeature).

## See also

[IPrintSchemaCapabilities](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintschemacapabilities)

[IPrintSchemaOption](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintschemaoption)

[IPrintSchemaTicket](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintschematicket)