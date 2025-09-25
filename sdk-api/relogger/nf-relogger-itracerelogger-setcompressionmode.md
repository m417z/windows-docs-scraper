# ITraceRelogger::SetCompressionMode

## Description

The **SetCompressionMode** method enables or disables compression on the relogged trace.

## Parameters

### `CompressionMode` [in]

Type: **BOOLEAN**

True if compression is enabled; otherwise, false.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

By default, compression will be enabled on a relogged trace.

Compression mode is not supported on Windows 7. By default, Compression mode it is set to **false** on Windows 7. When this method is called, it returns **E_NOTIMPL** when called on Windows 7.

Compression mode is set to **true** on Windows 8 or Windows Server 2012.

Compressed trace files can only be decoded in Windows 8 or Windows Server 2012.

## See also

[ITraceRelogger](https://learn.microsoft.com/windows/desktop/api/relogger/nn-relogger-itracerelogger)