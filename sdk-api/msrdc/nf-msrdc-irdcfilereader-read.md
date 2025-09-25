# IRdcFileReader::Read

## Description

The **Read** method reads the specified amount
of data starting at the specified position.

## Parameters

### `offsetFileStart` [in]

Offset from the start of the data at which to start the read.

### `bytesToRead` [in]

Number of bytes to be read.

### `bytesActuallyRead` [out]

Address of a **ULONG** that will receive the number of bytes read.

### `buffer` [out]

Address of the buffer that receives the data read. This buffer must be at least
*bytesToRead* bytes in size.

### `eof` [out]

Address of a **BOOL** that is set to **TRUE** if the end of
the file has been read.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Typically RDC will read the file sequentially from start to end. When reading signatures, the file may be read
more than once.

If the **BOOL** pointed to by the *eof* parameter is not **TRUE**
on return then the value pointed to by the *bytesActuallyRead* parameter must equal the
*bytesToRead* parameter. If the value pointed to by the *eof*
parameter is set, then the value pointed to by the *bytesActuallyRead* parameter can be
any value between zero and the *bytesToRead* parameter.

## See also

[IRdcFileReader](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-irdcfilereader)