# IXpsOMPageReference::SetPage

## Description

Sets the [IXpsOMPage](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompage) interface of the page reference.

## Parameters

### `page` [in]

The [IXpsOMPage](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompage) interface pointer of the page.

## Return value

If the method succeeds, it returns S_OK; otherwise, it returns an **HRESULT** error code.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *page* is **NULL**. |
| **XPS_E_NO_CUSTOM_OBJECTS** | *page* does not point to a recognized interface implementation. Custom implementation of XPS Document API interfaces is not supported. |

## Remarks

The page added by this method can be empty or fully constructed.

 If the incoming page has references to remote dictionary objects, those objects will not be imported into the document object by this call. They must be added in a separate call to the [IXpsOMPage::SetDictionaryResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompage-setdictionaryresource) or [IXpsOMCanvas::SetDictionaryResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomcanvas-setdictionaryresource) method.

If a page has been set, the calling method must first release that page before calling **SetPage** with a new page. To explain, once **SetPage** has been called with a new page, the original page cannot be discarded even if it still exists in the package.

## See also

[IXpsOMPage](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompage)

[IXpsOMPageReference](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompagereference)

[IXpsOMPageReference::DiscardPage](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompagereference-discardpage)

[IXpsOMPageReference::GetPage](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompagereference-getpage)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)