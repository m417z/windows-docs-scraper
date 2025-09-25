# IXpsOMStoryFragmentsResource::GetOwner

## Description

Gets a pointer to the [IXpsOMPage](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompage) interface that contains this resource.

## Parameters

### `owner` [out, retval]

A pointer to the [IXpsOMPage](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompage) interface that contains this resource. If the resource is not part of a page, a **NULL** pointer is returned.

## Return value

If the method succeeds, it returns S_OK; otherwise, it returns an **HRESULT** error code.

## See also

[IXpsOMPage](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompage)

[IXpsOMStoryFragmentsResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomstoryfragmentsresource)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)