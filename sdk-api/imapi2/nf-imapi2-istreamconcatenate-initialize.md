# IStreamConcatenate::Initialize

## Description

Initializes this stream from two input streams.

## Parameters

### `stream1` [in]

An **IStream** interface of the first stream to add to this stream.

### `stream2` [in]

An **IStream** interface of the second stream to add to this stream.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |
| **E_OUTOFMEMORY** | Failed to allocate the required memory.<br><br>Value: 0x8007000E |
| **E_INVALIDARG** | One or more arguments are not valid.<br><br>Value: 0x80070057 |

## Remarks

When using the [IStreamConcatenate](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-istreamconcatenate) interface, the following scenarios will result in undefined behaviors, and should be avoided:

* Each partial stream composing the MsftStreamConcatenate object is actually the same stream.
* Any of the concatenated streams are modified (read from, written to, or seeked on) outside of IMAPI.

## See also

[IStreamConcatenate](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-istreamconcatenate)

[IStreamConcatenate::Initialize2](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-istreamconcatenate-initialize2)