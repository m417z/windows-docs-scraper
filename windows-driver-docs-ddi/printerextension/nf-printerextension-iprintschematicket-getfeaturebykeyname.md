## Description

Gets a feature from the PrintTicket based on the specified key name.

## Parameters

### `bstrKeyName` [in]

The key name of the feature.

### `ppFeature` [out, retval]

The returned feature.

## Return value

This method returns an **HRESULT** value.

## Remarks

See [IPrintSchemaCapabilities::GetFeatureByKeyName](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nf-printerextension-iprintschemacapabilities-getfeaturebykeyname) for the recognized feature key names, the key names' equivalent public Print Schema feature names, and the supported specialized option types.

When the requested feature, option or property is not found, this method returns S_FALSE and sets a NULL pointer on the output object of the feature, option or property.

So if the [IPrintSchemaTicket](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintschematicket) object does not contain the specified feature, option or property, the app must obtain an [IPrintSchemaCapabilities](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintschemacapabilities) object and query it via **IPrintSchemaCapabilities::GetFeatureByKeyName** or via [IPrintSchemaCapabilities::GetFeature](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nf-printerextension-iprintschemacapabilities-getfeature).

## See also

[IPrintSchemaCapabilities](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintschemacapabilities)

[IPrintSchemaCapabilities::GetFeature](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nf-printerextension-iprintschemacapabilities-getfeature)

[IPrintSchemaCapabilities::GetFeatureByKeyName](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nf-printerextension-iprintschemacapabilities-getfeaturebykeyname)

[IPrintSchemaFeature](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintschemafeature)

[IPrintSchemaTicket](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintschematicket)