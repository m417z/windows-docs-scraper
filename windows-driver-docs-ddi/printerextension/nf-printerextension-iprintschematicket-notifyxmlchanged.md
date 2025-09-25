## Description

Notifies the print system that the XML DOM object has changed.

## Return value

This method returns an **HRESULT** value.

## Remarks

If the client retrieves the XML DOM object of the PrintTicket by calling [IPrintSchemaElement::XmlNode](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nf-printerextension-iprintschemaelement-get_xmlnode), and makes direct modifications to the PrintTicket using XMLDOM APIs, then it is the responsibility of the client to call **IPrintSchemaTicket::NotifyXmlChanged** to notify the system that the PrintTicket content has been modified.

## See also

[IPrintSchemaElement::XmlNode](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nf-printerextension-iprintschemaelement-get_xmlnode)

[IPrintSchemaTicket](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintschematicket)