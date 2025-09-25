# IXpsOMCanvas::GetAccessibilityLongDescription

## Description

Gets the long (detailed) textual description of the object's contents. This text is used by accessibility clients to describe the object.

## Parameters

### `longDescription` [out, retval]

The long (detailed) textual description of the object's contents. A **NULL** pointer is returned if this text has not been set.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *longDescription* is **NULL**. |

## Remarks

The property returned by this method corresponds to the **AutomationProperties.HelpText** attribute of the **Canvas** element in the document markup.

This method allocates the memory used by the string that is returned in *longDescription*. If *longDescription* is not **NULL**, use the **SignatureDefinitions** function to free the memory.

## See also

[IXpsOMCanvas](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomcanvas)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))