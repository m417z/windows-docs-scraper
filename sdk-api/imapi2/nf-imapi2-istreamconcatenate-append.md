# IStreamConcatenate::Append

## Description

Appends a stream to this stream.

## Parameters

### `stream` [in]

An **IStream** interface of the stream to append to this stream.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_NOTIMPL** | Not implemented.<br><br>Value: 0x80004001 |

## Remarks

You must call the [IStreamConcatenate::Initialize](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-istreamconcatenate-initialize) or [IStreamConcatenate::Initialize2](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-istreamconcatenate-initialize2) method prior to calling this method.

To append more than one stream to this stream, call the [IStreamConcatenate::Append2](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-istreamconcatenate-append2) method.

## See also

[IStreamConcatenate](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-istreamconcatenate)

[IStreamConcatenate::Append2](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-istreamconcatenate-append2)