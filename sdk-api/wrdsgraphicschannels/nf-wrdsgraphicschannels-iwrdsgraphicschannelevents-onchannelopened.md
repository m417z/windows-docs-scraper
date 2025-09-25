# IWRdsGraphicsChannelEvents::OnChannelOpened

## Description

Called when the channel has been opened and is ready for use, or when an error occurs when a channel is opened. The RemoteFX graphics services calls the [IWRdsGraphicsChannel::Open](https://learn.microsoft.com/windows/desktop/api/wrdsgraphicschannels/nf-wrdsgraphicschannels-iwrdsgraphicschannel-open) method to open a channel. You must call the **OnChannelOpened** method to notify the RemoteFX graphics services that the channel is open and ready for use, or if an error occurs.

## Parameters

### `OpenResult` [in]

An **HRESULT** value that specifies the result of the open operation. If this parameter contains **S_OK**, *pOpenContext* is valid.

### `pOpenContext` [in]

A user-defined interface pointer that is passed as the *pOpenContext* parameter in the [IWRdsGraphicsChannel::Open](https://learn.microsoft.com/windows/desktop/api/wrdsgraphicschannels/nf-wrdsgraphicschannels-iwrdsgraphicschannel-open) method.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWRdsGraphicsChannel::Open](https://learn.microsoft.com/windows/desktop/api/wrdsgraphicschannels/nf-wrdsgraphicschannels-iwrdsgraphicschannel-open)

[IWRdsGraphicsChannelEvents](https://learn.microsoft.com/windows/desktop/api/wrdsgraphicschannels/nn-wrdsgraphicschannels-iwrdsgraphicschannelevents)