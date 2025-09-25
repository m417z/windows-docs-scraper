# IOpcUri::GetRelativeUri

## Description

 Forms a relative URI for a specified part, relative to the URI represented by the current OPC URI object.

## Parameters

### `targetPartUri` [in]

A pointer to the [IOpcPartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcparturi) interface of the part URI object that represents the part name from which the relative URI is formed.

### `relativeUri` [out, retval]

A pointer to the [IUri](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/ms775038(v=vs.85)) interface of the URI of the part, relative to the current OPC URI object.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | At least one of the *targetPartUri*, and *relativePartUri* parameters is **NULL**. |
| ****CreateUri** function error** | An **HRESULT** error code from the [CreateUri](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/ms775098(v=vs.85)) function. |
| **WinINet error** | An **HRESULT** error code from a [WinINet](https://learn.microsoft.com/windows/desktop/WinInet/wininet-reference) API. |

## Remarks

Example input and output:

| Input [IOpcPartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcparturi) represents | Current [IOpcUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcuri) represents | Returned relative [IUri](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/ms775038(v=vs.85)) represents |
| --- | --- | --- |
| /mydoc/markup/page.xml | /mydoc/markup/picture.jpg | picture.jpg |
| /mydoc/markup/page.xml | /mydoc/picture.jpg | ../picture.jpg |
| /mydoc/markup/page.xml | /mydoc/images/pictures.jpg | ../images/pictures.jpg |

### Support on Previous Windows Versions

The behavior and performance of this method is the same on all supported Windows versions. For more information, see [Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview), and [Platform Update for Windows Vista](https://learn.microsoft.com/windows/desktop/win7ip/platform-update-for-windows-vista-portal).

#### Thread Safety

Packaging objects are not thread-safe.

For more information, see the [Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview).

## See also

[Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview)

[IOpcUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcuri)

**Overviews**

[Packaging API Reference](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-reference)

[Packaging API Samples](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-samples)

[Packaging Errors](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-errors)

[Platform Update for Windows Vista](https://learn.microsoft.com/windows/desktop/win7ip/platform-update-for-windows-vista-portal)

**Reference**