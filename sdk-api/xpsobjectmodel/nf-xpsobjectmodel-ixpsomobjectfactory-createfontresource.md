# IXpsOMObjectFactory::CreateFontResource

## Description

Creates an [IXpsOMFontResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomfontresource) interface, which provides an [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) interface to the font resource.

## Parameters

### `acquiredStream` [in]

The read-only [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) interface to be associated with this font resource. This parameter must not be **NULL**.

**Important** Treat this stream as a Single-Threaded Apartment (STA) object; do not re-enter it.

**Caution** This stream is not to be obfuscated.

### `fontEmbedding` [in]

The [XPS_FONT_EMBEDDING](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_font_embedding) value that specifies the stream's embedding option.

### `partUri` [in]

The [IOpcPartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcparturi) interface that contains the part name to be assigned to this resource. This parameter must not be **NULL**.

### `isObfSourceStream` [in]

A Boolean value that indicates whether the stream referenced by *acquiredStream* is obfuscated.

| Value | Meaning |
| --- | --- |
| **TRUE** | The stream referenced by *acquiredStream* is obfuscated. |
| **FALSE** | The stream referenced by *acquiredStream* is not obfuscated. |

### `fontResource` [out, retval]

A pointer to the new [IXpsOMFontResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomfontresource) interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | One of the following errors has occurred:<br><br>* *fontEmbedding* is not a valid [XPS_FONT_EMBEDDING](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_font_embedding) value.<br>* *fontEmbedding* is [XPS_FONT_EMBEDDING_NORMAL](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_font_embedding) and *isObfSourceStream* is **TRUE**. |
| **E_POINTER** | *acquiredStream*, *partUri*, or *fontResource* is **NULL**. |

## Remarks

The value of *isObfSourceStream* describes the state of the *acquiredStream*-referenced stream at the time the font resource is created. All subsequent calls to [GetStream](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomfontresource-getstream) or [SetContent](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomfontresource-setcontent) will operate on unobfuscated versions of [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream).

An error is returned if *isObfSourceStream* is set to **TRUE** and *fontEmbedding* is set to [XPS_FONT_EMBEDDING_NORMAL](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_font_embedding), or if the name referenced by *partUri* does not conform to the syntax for obfuscated streams.

The code example that follows illustrates how this method is used to create a new interface.

```cpp

IXpsOMFontResource    *newInterface;
IOpcPartUri           *partUri;

// Note the implicit requirement that CoInitializeEx
//  has previously been called from this thread.

hr = CoCreateInstance(
    __uuidof(XpsOMObjectFactory),
    NULL,
    CLSCTX_INPROC_SERVER,
    _uuidof(IXpsOMObjectFactory),
    reinterpret_cast<LPVOID*>(&xpsFactory)
    );

if (SUCCEEDED(hr))
{
    // The partUriString and acquiredStream variables
    //   are defined outside of this example.
    hr = xpsFactory->CreatePartUri(partUriString, &partUri);
    if (SUCCEEDED(hr))
    {
        hr = xpsFactory->CreateFontResource (
            acquiredStream,
            XPS_FONT_EMBEDDING_NORMAL,    // normal
            partUri,
            FALSE,                        // not obfuscated
            &newInterface);
        if (SUCCEEDED(hr))
        {
            // use newInterface

            newInterface->Release();
        }
        partUri->Release();
    }
    xpsFactory->Release();
}
else
{
    // evaluate HRESULT error returned in hr
}

```

## See also

[IOpcPartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcparturi)

[IXpsOMFontResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomfontresource)

[IXpsOMObjectFactory](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomobjectfactory)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))

[XPS_FONT_EMBEDDING](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_font_embedding)