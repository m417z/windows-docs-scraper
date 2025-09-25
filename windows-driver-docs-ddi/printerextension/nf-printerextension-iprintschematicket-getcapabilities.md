## Description

Gets an [IPrintSchemaCapabilities](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintschemacapabilities) object that represents the printer capabilities based on the current settings of this [IPrintSchemaTicket](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintschematicket) object.

## Parameters

### `ppCapabilities`

The returned [IPrintSchemaCapabilities](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintschemacapabilities) object.

## Return value

This method returns an **HRESULT** value.

## Remarks

Because this method retrieves a new PrintCapabilities document every time it is invoked, it is recommended that you invoke this method only when the [IPrintSchemaTicket](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintschematicket) object has been modified.

## See also

[IPrintSchemaCapabilities](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintschemacapabilities)

[IPrintSchemaElement::XmlNode](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nf-printerextension-iprintschemaelement-get_xmlnode)

[IPrintSchemaFeature::SelectedOption](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nf-printerextension-iprintschemafeature-get_selectedoption)

[IPrintSchemaTicket](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintschematicket)

[IPrintSchemaTicket::put_JobCopiesAllDocuments](https://learn.microsoft.com/windows/win32/api/rrascfg/nf-rrascfg-ieapproviderconfig-initialize)