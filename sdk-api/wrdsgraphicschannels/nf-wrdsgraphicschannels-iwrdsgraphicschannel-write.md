# IWRdsGraphicsChannel::Write

## Description

Called to send data to the virtual channel.

## Parameters

### `cbSize` [in]

The length, in bytes, of the data in *pBuffer*.

### `pBuffer` [in]

A pointer to a buffer that contains the data that was sent. The *cbBuffer* parameter contains the length of this buffer.

The implementation will take ownership of this buffer until the [IWRdsGraphicsChannelEvents::OnDataSent](https://learn.microsoft.com/windows/desktop/api/wrdsgraphicschannels/nf-wrdsgraphicschannels-iwrdsgraphicschannelevents-ondatasent) method is called. Before that time, this buffer must not be modified or freed.

### `pContext` [in]

A user-defined interface pointer that is passed as the *pWriteContext* parameter in the [IWRdsGraphicsChannelEvents::OnDataSent](https://learn.microsoft.com/windows/desktop/api/wrdsgraphicschannels/nf-wrdsgraphicschannels-iwrdsgraphicschannelevents-ondatasent) method.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWRdsGraphicsChannel](https://learn.microsoft.com/windows/desktop/api/wrdsgraphicschannels/nn-wrdsgraphicschannels-iwrdsgraphicschannel)

[IWRdsGraphicsChannelEvents::OnDataSent](https://learn.microsoft.com/windows/desktop/api/wrdsgraphicschannels/nf-wrdsgraphicschannels-iwrdsgraphicschannelevents-ondatasent)