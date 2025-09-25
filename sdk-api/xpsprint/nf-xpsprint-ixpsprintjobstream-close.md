# IXpsPrintJobStream::Close

## Description

[IXpsPrintJobStream::Close is not supported and may be altered or unavailable in the future. ]

Closes the stream and indicates to the print job that the entire document has been written to the print queue by the application.

## Return value

If the method succeeds, it returns S_OK; otherwise, it returns an **HRESULT** error code.

## Remarks

After **Close** has been called, all subsequent attempts to write data to the stream will fail.

## See also

[Documents](https://learn.microsoft.com/previous-versions/windows/desktop/dd316975(v=vs.85))

[IXpsPrintJobStream](https://learn.microsoft.com/windows/desktop/api/xpsprint/nn-xpsprint-ixpsprintjobstream)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)