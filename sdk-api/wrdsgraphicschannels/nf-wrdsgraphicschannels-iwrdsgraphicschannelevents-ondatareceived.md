# IWRdsGraphicsChannelEvents::OnDataReceived

## Description

Called when a full message is received from the server.

## Parameters

### `cbSize` [in]

The length, in bytes, of the data in *pBuffer*.

### `pBuffer` [in]

A pointer to a buffer that contains the data that was received. The *cbSize* parameter contains the length of this buffer.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWRdsGraphicsChannelEvents](https://learn.microsoft.com/windows/desktop/api/wrdsgraphicschannels/nn-wrdsgraphicschannels-iwrdsgraphicschannelevents)