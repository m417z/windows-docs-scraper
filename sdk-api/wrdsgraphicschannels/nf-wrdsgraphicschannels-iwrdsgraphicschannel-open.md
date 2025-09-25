# IWRdsGraphicsChannel::Open

## Description

Called to open a channel. When the channel is completely open and ready for use, you must call the [IWRdsGraphicsChannelEvents::OnChannelOpened](https://learn.microsoft.com/windows/desktop/api/wrdsgraphicschannels/nf-wrdsgraphicschannels-iwrdsgraphicschannelevents-onchannelopened) method.

## Parameters

### `pChannelEvents` [in]

Type: **[IWRdsGraphicsChannelEvents](https://learn.microsoft.com/windows/desktop/api/wrdsgraphicschannels/nn-wrdsgraphicschannels-iwrdsgraphicschannelevents)***

A pointer to an [IWRdsGraphicsChannelEvents](https://learn.microsoft.com/windows/desktop/api/wrdsgraphicschannels/nn-wrdsgraphicschannels-iwrdsgraphicschannelevents) interface that will receive notifications relating to the channel created.

### `pOpenContext` [in]

Type: **IUnknown***

A user-defined interface pointer that is passed as the *pOpenContext* parameter in the [IWRdsGraphicsChannelEvents::OnChannelOpened](https://learn.microsoft.com/windows/desktop/api/wrdsgraphicschannels/nf-wrdsgraphicschannels-iwrdsgraphicschannelevents-onchannelopened) method.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWRdsGraphicsChannel](https://learn.microsoft.com/windows/desktop/api/wrdsgraphicschannels/nn-wrdsgraphicschannels-iwrdsgraphicschannel)

[IWRdsGraphicsChannelEvents::OnChannelOpened](https://learn.microsoft.com/windows/desktop/api/wrdsgraphicschannels/nf-wrdsgraphicschannels-iwrdsgraphicschannelevents-onchannelopened)