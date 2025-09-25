# IXpsOMPageReference::SetPrintTicketResource

## Description

Sets the [IXpsOMPrintTicketResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomprintticketresource) interface pointer of the page-level print ticket resource that is to be assigned to the page.

## Parameters

### `printTicketResource` [in]

A pointer to the [IXpsOMPrintTicketResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomprintticketresource) interface of the page-level print ticket resource that is to be assigned to the page. If a print ticket has already been set, a **NULL** pointer releases it.

## Return value

If the method succeeds, it returns S_OK; otherwise, it returns an **HRESULT** error code.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **XPS_E_NO_CUSTOM_OBJECTS** | *printTicketResource* does not point to a recognized interface implementation. Custom implementation of XPS Document API interfaces is not supported. |

## See also

[IXpsOMPageReference](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompagereference)

[IXpsOMPrintTicketResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomprintticketresource)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)