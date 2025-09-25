# IPrintWriteStreamFlush::FlushData

## Description

The FlushData method flushes buffered data to a data stream while leaving the stream open, allowing the caller to write additional data to the stream. Writing to the stream is done using the [IPrintWriteStream::WriteBytes](https://learn.microsoft.com/windows-hardware/drivers/ddi/filterpipeline/nf-filterpipeline-iprintwritestream-writebytes) method.

## Return value

The FlushData method returns an HRESULT value.

## Remarks

Only the last filter in the print filter pipeline benefits from the flush. The data is flushed to the port monitor. However, the port monitor has the option of using buffers.

### Examples

The following code snippet shows how to flush data to a data stream. Note that error checking has been omitted for clarity.

```cpp
// Flushing data to a data stream
// ------------------------------
// Declare a pointer to an IPrintWriteStreamFlush interface
IPrintWriteStreamFlush *pIFlush;

// Retrieve a pointer to an IPrintWriteStream interface
// by using the RequestWriter() method in InitializeFilter()
IPrintWriteStream      *pIWrite;

HRESULT hr = pIWrite->QueryInterface(IID_IPrintWriteStreamFlush, reinterpret_cast<void **>(&pIFlush));

hr = pIWrite->WriteBytes(buf, cb, &cbWritten);

hr = pIFlush->FlushData();
```

## See also

[IPrintWriteStream::WriteBytes](https://learn.microsoft.com/windows-hardware/drivers/ddi/filterpipeline/nf-filterpipeline-iprintwritestream-writebytes)

[IPrintWriteStreamFlush](https://learn.microsoft.com/windows-hardware/drivers/ddi/filterpipeline/nn-filterpipeline-iprintwritestreamflush)