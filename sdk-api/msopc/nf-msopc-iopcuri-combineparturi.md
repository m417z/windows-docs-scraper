# IOpcUri::CombinePartUri

## Description

Forms the part name of the part that is referenced by the specified relative URI.
The specified relative URI of the part is resolved against the URI represented as the current OPC URI object.

## Parameters

### `relativeUri` [in]

A pointer to the [IUri](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/ms775038(v=vs.85)) interface of the relative URI of the part.

To form the part URI object that represents the part name, this input URI is resolved against the URI represented as the current OPC URI object. Therefore, the input URI must be relative to the URI represented by the current OPC URI object.

This URI may include a fragment component; however, the fragment will be ignored and will not be included in the part name to be formed. A fragment component is preceded by a '#', as described in [RFC 3986: URI Generic Syntax](https://www.ietf.org/rfc/rfc3986.txt).

### `combinedUri` [out, retval]

A pointer to the [IOpcPartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcparturi) interface of the part URI object that represents the part name.

The part URI object is formed by resolving the relative URI in *relativeUri* against the URI represented by the current OPC URI object.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_FAIL** | The [CoInternetCombineUrl](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/ms775085(v=vs.85)) function returned an invalid size. |
| **E_POINTER** | At least one of the *relativeUri*, and *combinedUri* parameters is **NULL**. |
| **E_UNEXPECTED** | The size of the buffer required by the [CoInternetCombineUrl](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/ms775085(v=vs.85)) function changed unexpectedly. |
| **OPC_E_NONCONFORMING_URI**<br><br>0x80510001 | The part name does not conform to the rules specified in the *OPC* standards. |
| **OPC_E_RELATIVE_URI_REQUIRED**<br><br>0x80510002 | A part name cannot be an absolute URI. An absolute URI begins with a schema component followed by a ":", as described in [RFC 3986: URI Generic Syntax](https://www.ietf.org/rfc/rfc3986.txt). |
| **CoInternetCombineUrl function error** | An **HRESULT** error code from the [CoInternetCombineUrl](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/ms775085(v=vs.85)) function. |
| **CreateUri function error** | An **HRESULT** error code from the [CreateUri](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/ms775098(v=vs.85)) function. |
| **WinINet error** | An **HRESULT** error code from a [WinINet](https://learn.microsoft.com/windows/desktop/WinInet/wininet-reference) API. |

## Remarks

Example input and output:

| Input relative [IUri](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/ms775038(v=vs.85)) | Current [IOpcUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcuri) | Formed [IOpcPartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcparturi) |
| --- | --- | --- |
| picture.jpg | /mydoc/markup/page.xml | /mydoc/markup/picture.jpg |
| ../picture.jpg | /mydoc/markup/page.xml | /mydoc/picture.jpg |
| ../../images/picture.jpg | /mydoc/page.xml | /images/picture.jpg |

For information about how to use this method to help resolve a part name, see [Resolving a Part Name from a Target URI](https://learn.microsoft.com/previous-versions/windows/desktop/opc/resolving-a-part-name-from-a-relationship-s-target-uri).

### Support on Previous Windows Versions

The behavior and performance of this method is the same on all supported Windows versions. For more information, see [Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview), and [Platform Update for Windows Vista](https://learn.microsoft.com/windows/desktop/win7ip/platform-update-for-windows-vista-portal).

#### Thread Safety

Packaging objects are not thread-safe.

For more information, see the [Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview).

## See also

[ECMA-376 OpenXML](https://www.ecma-international.org/publications-and-standards/standards/ecma-376/)

**External Resources**

[Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview)

[IOpcUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcuri)

**Overviews**

[Packaging API Reference](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-reference)

[Packaging API Samples](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-samples)

[Packaging Errors](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-errors)

[Platform Update for Windows Vista](https://learn.microsoft.com/windows/desktop/win7ip/platform-update-for-windows-vista-portal)

[RFC 3986: URI Generic Syntax](https://www.ietf.org/rfc/rfc3986.txt)

**Reference**

[Resolving a Part Name from a Target URI](https://learn.microsoft.com/previous-versions/windows/desktop/opc/resolving-a-part-name-from-a-relationship-s-target-uri)