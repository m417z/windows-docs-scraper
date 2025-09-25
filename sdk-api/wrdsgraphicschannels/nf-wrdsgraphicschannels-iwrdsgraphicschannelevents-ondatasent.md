# IWRdsGraphicsChannelEvents::OnDataSent

## Description

Called when the [IWRdsGraphicsChannel::Write](https://learn.microsoft.com/windows/desktop/api/wrdsgraphicschannels/nf-wrdsgraphicschannels-iwrdsgraphicschannel-write) method is called and the data has been sent. After this method has been called, the *pBuffer* parameter passed to the [IWRdsGraphicsChannel::Write](https://learn.microsoft.com/windows/desktop/api/wrdsgraphicschannels/nf-wrdsgraphicschannels-iwrdsgraphicschannel-write) method is no longer needed and can be freed or reused.

## Parameters

### `pWriteContext` [in]

A user-defined interface pointer that is passed as the *pContext* parameter in the [IWRdsGraphicsChannel::Write](https://learn.microsoft.com/windows/desktop/api/wrdsgraphicschannels/nf-wrdsgraphicschannels-iwrdsgraphicschannel-write) method.

### `bCancelled` [in]

Contains **TRUE** if the connection was dropped during the write, or **FALSE** otherwise.

### `pBuffer` [in]

A pointer to a buffer that contains the data that was sent. The *cbBuffer* parameter contains the length of this buffer.

### `cbBuffer` [in]

The length, in bytes, of the data in *pBuffer*.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWRdsGraphicsChannel::Write](https://learn.microsoft.com/windows/desktop/api/wrdsgraphicschannels/nf-wrdsgraphicschannels-iwrdsgraphicschannel-write)

[IWRdsGraphicsChannelEvents](https://learn.microsoft.com/windows/desktop/api/wrdsgraphicschannels/nn-wrdsgraphicschannels-iwrdsgraphicschannelevents)