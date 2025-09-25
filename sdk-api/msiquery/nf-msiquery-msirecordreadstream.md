# MsiRecordReadStream function

## Description

The
**MsiRecordReadStream** function reads bytes from a record stream field into a buffer.

## Parameters

### `hRecord` [in]

Handle to the record.

### `iField` [in]

Specifies the field of the record.

### `szDataBuf` [out]

A buffer to receive the stream field. You should ensure the destination buffer is the same size or larger than the source buffer. See the Remarks section.

### `pcbDataBuf` [in, out]

Specifies the in and out buffer count. On input, this is the full size of the buffer. On output, this is the number of bytes that were actually written to the buffer. See the Remarks section.

## Return value

This function returns UINT.

## Remarks

To read a stream, set *pcbDataBuf* to the number of bytes that are to be transferred from stream to buffer each time the function is called. On return, the
**MsiRecordReadStream** resets *pcbDataBuf*  to the number of bytes that were actually transferred. If the buffer is smaller than the stream, the stream is repositioned when the buffer becomes full such that the next data in the stream is transferred by the next call to the function. When no more bytes are available,
**MsiRecordReadStream** returns ERROR_SUCCESS.

If you pass 0 for *szDataBuf* then *pcbDataBuf* is reset to the number of bytes in the stream remaining to be read.

The following code sample reads from a stream that is in field 1 of a record specified by hRecord and reads the entire stream 8 bytes at a time.

```cpp
char szBuffer[8];
PMSIHANDLE hRecord;
DWORD cbBuf = sizeof(szBuffer);
do
{
    if (MsiRecordReadStream(hRecord, 1, szBuffer,
        &cbBuf) != ERROR_SUCCESS)
        break; /* error */
}
while (cbBuf == 8);  //continue reading the stream while you receive a full buffer
//cbBuf will be less once you reach the end of the stream and cannot fill your
//buffer with stream data

```

See also
[OLE Limitations on Streams](https://learn.microsoft.com/windows/desktop/Msi/ole-limitations-on-streams).

## See also

[Record Processing Functions](https://learn.microsoft.com/windows/desktop/Msi/database-functions)