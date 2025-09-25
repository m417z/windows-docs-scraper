# IXpsOMPageReference::DiscardPage

## Description

Discards the page from memory.

## Return value

If the method succeeds, it returns S_OK; otherwise, it returns an **HRESULT** error code.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_UNEXPECTED** | [DiscardPage](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompagereference-discardpage) has been called more than once or the page has not been loaded. |

## Remarks

If [SetPage](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompagereference-setpage) has not been called, calling **DiscardPage** and then [GetPage](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompagereference-getpage) will return the virtualized page from the source package. If **SetPage** has been called, calling **DiscardPage** and then **GetPage** will return **NULL**.

If the page referenced by this [IXpsOMPageReference](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompagereference) interface has been constructed entirely in memory and does not have a corresponding file, **DiscardPage** will delete the page from memory and the page's content will be lost. If the page has been constructed from a file, **DiscardPage** will delete the page from memory but will not alter the original file. The page can be reconstructed and read back into memory by calling [GetPage](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompagereference-getpage).

If the page has been constructed from a file and subsequently modified, **DiscardPage** will discard the page from memory, and any changes made to the page will be lost. Calling [GetPage](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompagereference-getpage) after this will re-read the original content from the file.

## See also

[IXpsOMPageReference](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompagereference)

[IXpsOMPageReference::GetPage](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompagereference-getpage)

[IXpsOMPageReference::SetPage](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompagereference-setpage)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)