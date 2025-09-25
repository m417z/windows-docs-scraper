# IXpsOMPrintTicketResource::GetStream

## Description

Gets a new, read-only copy of the stream that is associated with this resource.

## Parameters

### `stream` [out, retval]

A new, read-only copy of the stream that is associated with this resource.

## Return value

If the method succeeds, it returns S_OK; otherwise, it returns an **HRESULT** error code. For information about XPS document API return values, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

This method calls the [Packaging](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging) API. For information about the Packaging API return values, see [Packaging Errors](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-errors).

## Remarks

The [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) object returned by this method might return an error of E_PENDING, which indicates that the stream length has not been determined yet. This behavior is different from that of a standard **IStream** object.

This method calls the stream's **Clone** method to create the stream returned in *stream*. As a result, the performance of this method will depend on that of the stream's **Clone** method.

## See also

[IXpsOMPrintTicketResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomprintticketresource)

[Packaging Errors](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-errors)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))