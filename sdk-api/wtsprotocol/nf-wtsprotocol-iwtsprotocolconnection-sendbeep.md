# IWTSProtocolConnection::SendBeep

## Description

[**IWTSProtocolConnection::SendBeep** is no longer available for use as of Windows Server 2012.]

Sends a sound pulse to the console speaker on the client.

The beep() function does not cause **SendBeep** to be called. To work around this issue, the user must enable Remote Desktop Services audio redirection capabilities to remotely hear beep sounds.

## Parameters

### `Frequency` [in]

An integer that contains the pulse frequency ranging from 37 to 32,767 Hertz.

### `Duration` [in]

An integer that contains the pulse duration, in milliseconds.

## See also

[IWTSProtocolConnection](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwtsprotocolconnection)