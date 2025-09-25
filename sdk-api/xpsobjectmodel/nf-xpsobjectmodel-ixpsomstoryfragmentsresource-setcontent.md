# IXpsOMStoryFragmentsResource::SetContent

## Description

Sets the read-only stream to be associated with this resource.

## Parameters

### `sourceStream` [in]

The read-only stream to be associated with this resource.

### `partName` [in]

The part name to be assigned to this resource.

## Return value

If the method succeeds, it returns S_OK; otherwise, it returns an **HRESULT** error code.

## Remarks

The calling method should treat this stream as a single-threaded apartment (STA) model object and not re-enter any of the stream interface's methods.

For more information about the content of a StoryFragments part, see the [XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification).

Because [GetStream](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomstoryfragmentsresource-getstream) gets a clone of the stream that is set by this method, the provided stream should have an efficient cloning method. A stream with an inefficient cloning method will reduce the performance of **GetStream**.

## See also

[IOpcPartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcparturi)

[IXpsOMStoryFragmentsResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomstoryfragmentsresource)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)