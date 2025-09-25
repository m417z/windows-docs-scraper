## Description

Gets the IXMLDOMNode object associated with this item.

This property is read-only.

## Parameters

### `ppXmlNode`

Defines the **IUnknown** parameter *ppXmlNode*.

## Return value

Returns an **HRESULT** value. If the property call was not successful, it returns the appropriate **HRESULT** error code.

## Remarks

When you dereference the *ppXmlNode* parameter (using *ppXmlNode ), you obtain a pointer to an interface of type **IUnknown**. Use this pointer to call the **QueryInterface** method, to access the underlying [IXMLDOMElement](https://learn.microsoft.com/previous-versions/windows/desktop/ms760248(v=vs.85)) object.print.

## See also

[IPrintSchemaCapabilities](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintschemacapabilities)

[IPrintSchemaElement](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintschemaelement)

[IPrintSchemaTicket](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintschematicket)

[IPrintSchemaTicket::NotifyXmlChanged](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nf-printerextension-iprintschematicket-notifyxmlchanged)

[IPrintSchemaTicket_GetCapabilities](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nf-printerextension-iprintschematicket-getcapabilities)

[IXMLDOMElement](https://learn.microsoft.com/previous-versions/windows/desktop/ms760248(v=vs.85))