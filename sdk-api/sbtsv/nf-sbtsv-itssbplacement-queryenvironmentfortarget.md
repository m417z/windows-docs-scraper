# ITsSbPlacement::QueryEnvironmentForTarget

## Description

Determines whether the specified environment is ready to host
the target that was returned by load balancing.

## Parameters

### `pConnection` [in]

A pointer to an [ITsSbClientConnection](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbclientconnection) client connection object.

### `pPlacementSink` [in]

 A pointer to an [ITsSbPlacementNotifySink](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbplacementnotifysink) placement sink object.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Your plug-in should use the [ITsSbPlacementNotifySink](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbplacementnotifysink) object to report the state of the environment to Remote Desktop Connection Broker (RD Connection Broker).

After RD Connection Broker receives a load-balancing result, it calls **QueryEnvironmentForTarget**
to determine whether the environment is present and ready.

## See also

[ITsSbClientConnection](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbclientconnection)

[ITsSbPlacement](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbplacement)

[ITsSbPlacementNotifySink](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbplacementnotifysink)