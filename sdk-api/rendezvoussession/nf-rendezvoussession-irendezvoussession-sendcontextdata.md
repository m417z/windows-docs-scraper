# IRendezvousSession::SendContextData

## Description

Sends the context data to the remote [RendezvousApplication](https://learn.microsoft.com/previous-versions/windows/desktop/remoteassist/remoteassist-rendezvousapplication).

## Parameters

### `bstrData` [in]

A **BSTR** specifying context data for the application.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The context data was sent successfully. |
| **E_INVALIDARG** | The context data passed to the method is not valid. |
| **E_OUTOFMEMORY** | There is not enough memory available to send the context data. |