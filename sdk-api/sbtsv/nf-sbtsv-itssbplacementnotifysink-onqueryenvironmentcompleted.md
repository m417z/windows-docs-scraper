# ITsSbPlacementNotifySink::OnQueryEnvironmentCompleted

## Description

Notifies Remote Desktop Connection Broker (RD Connection Broker) that the environment
specified by the [ITsSbClientConnection](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbclientconnection) object is already hosting the correct target.

## Parameters

### `pEnvironment` [in]

A pointer to an [ITsSbEnvironment](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbenvironment) environment object.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITsSbClientConnection](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbclientconnection)

[ITsSbEnvironment](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbenvironment)

[ITsSbPlacement](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbplacement)

[ITsSbPlacementNotifySink](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbplacementnotifysink)