# IWTSProtocolConnection::GetProtocolHandles

## Description

[**IWTSProtocolConnection::GetProtocolHandles** is no longer available for use as of Windows Server 2012. Instead, use [IWRdsProtocolConnection::GetInputHandles](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nf-wtsprotocol-iwrdsprotocolconnection-getinputhandles) and [IWRdsProtocolConnection::GetVideoHandle](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nf-wtsprotocol-iwrdsprotocolconnection-getvideohandle).]

Retrieves keyboard, mouse, sound, and beep handles supported by the protocol.

## Parameters

### `pKeyboardHandle` [out]

A pointer to a keyboard handle. This is a handle to an [I8042prt keyboard driver](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/).

### `pMouseHandle` [out]

A pointer to a mouse handle. This is a handle to a [Mouclass driver](https://learn.microsoft.com/previous-versions/ff542367(v=vs.85)).

### `pBeepHandle` [out]

A pointer to a beep device handle. This handle is not used and must be set to **NULL**.

### `pVideoHandle` [out]

 A pointer to a video device handle. This is a handle to the video miniport driver for the remote session associated with the protocol.

## See also

[IWTSProtocolConnection](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwtsprotocolconnection)