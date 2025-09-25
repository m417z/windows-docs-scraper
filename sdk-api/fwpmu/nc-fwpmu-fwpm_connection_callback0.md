# FWPM_CONNECTION_CALLBACK0 callback function

## Description

The **FWPM_CONNECTION_CALLBACK0** function is used to add custom behavior to the connection object subscription process.

## Parameters

### `context` [in, out]

Type: **void***

Optional context pointer. It contains the value of the *context* parameter of the [FwpmConnectionSubscribe0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmconnectionsubscribe0) function.

### `eventType` [in]

Type: [FWPM_CONNECTION_EVENT_TYPE](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ne-fwpmtypes-fwpm_connection_event_type)

The type of connection object change event.

### `connection` [in]

Type: [FWPM_CONNECTION0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_connection0)*

The connection object change information.

## Remarks

Call [FwpmConnectionSubscribe0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmconnectionsubscribe0) to register this callback function.

## See also

[FWPM_CONNECTION0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_connection0)

[FWPM_CONNECTION_EVENT_TYPE](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ne-fwpmtypes-fwpm_connection_event_type)

[FwpmConnectionSubscribe0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmconnectionsubscribe0)