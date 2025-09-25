## Description

Gets a feature from the PrintCapabilities based on a given key name.

## Parameters

### `bstrKeyName` [in]

The key name of the feature.

### `ppFeature` [out, retval]

The returned feature.

## Return value

This method returns an **HRESULT** value.

## Remarks

Only the following feature key names are recognized. The key names are equivalent to public Print Schema feature names as shown in the following table. The table also shows the features that have specialized option types (by default the option type is [IPrintSchemaOption](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintschemaoption)).

| Name | Print schema feature public name | Specialized option type |
|--|--|--|
| DocumentBinding | DocumentBinding or JobBindAllDocuments | |
| DocumentCollate | DocumentCollate | |
| DocumentDuplex | JobDuplexAllDocumentsContiguously | |
| DocumentHolePunch | DocumentHolePunch or JobHolePunch | |
| DocumentInputBin | JobInputBin, DocumentInputBin or PageInputBin | |
| DocumentNUp | JobNUpAllDocumentsContiguously | [IPrintSchemaNUpOption](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintschemanupoption) |
| DocumentStaple | JobStapleAllDocuments or DocumentStaple | |
| PageMediaSize | PageMediaSize | [IPrintSchemaPageMediaSizeOption](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintschemapagemediasizeoption) |
| PageMediaType | PageMediaType | |
| PageOrientation | PageOrientation | |
| PageOutputColor | PageOutputColor | |
| PageOutputQuality | PageOutputQuality | |

When the requested feature, option or property is not found, this method returns S_FALSE and sets a NULL pointer on the output object of the feature, option or property.

So if the [IPrintSchemaTicket](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintschematicket) object does not contain the specified feature, option or property, the app must obtain an [IPrintSchemaCapabilities](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintschemacapabilities) object and query it via **IPrintSchemaCapabilities::GetFeatureByKeyName** or via [IPrintSchemaCapabilities::GetFeature](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nf-printerextension-iprintschemacapabilities-getfeature).

## See also

[IPrintSchemaCapabilities](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintschemacapabilities)

[IPrintSchemaNUpOption](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintschemanupoption)

[IPrintSchemaOption](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintschemaoption)

[IPrintSchemaPageMediaSizeOption](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintschemapagemediasizeoption)