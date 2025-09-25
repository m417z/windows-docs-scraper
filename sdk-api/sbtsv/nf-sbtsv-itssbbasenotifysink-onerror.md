# ITsSbBaseNotifySink::OnError

## Description

Reports an error condition to Remote Desktop Connection Broker (RD Connection Broker).

## Parameters

### `hrError` [in]

The error condition.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Calling this method stops further processing on the client connection and causes the connection to fail.

## See also

[ITsSbBaseNotifySink](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbbasenotifysink)