# IWRdsProtocolConnection::GetLastInputTime

## Description

Retrieves the last time the protocol received user input.

## Parameters

### `pLastInputTime` [out]

A pointer to a **ULONG64** value that receives the number of milliseconds that has elapsed since the protocol last received input.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWRdsProtocolConnection](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwrdsprotocolconnection)