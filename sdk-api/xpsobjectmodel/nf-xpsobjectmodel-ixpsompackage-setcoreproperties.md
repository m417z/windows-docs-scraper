# IXpsOMPackage::SetCoreProperties

## Description

Sets the [IXpsOMCoreProperties](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomcoreproperties) interface of the XPS package.

## Parameters

### `coreProperties` [in]

The [IXpsOMCoreProperties](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomcoreproperties) interface pointer to be assigned to the package.
A **NULL** pointer releases any previously assigned core properties interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **XPS_E_NO_CUSTOM_OBJECTS** | *coreProperties* does not point to a recognized interface implementation. Custom implementation of XPS Document API interfaces is not supported. |

## See also

[IXpsOMCoreProperties](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomcoreproperties)

[IXpsOMPackage](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompackage)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))