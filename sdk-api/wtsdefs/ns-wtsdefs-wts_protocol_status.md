# WTS_PROTOCOL_STATUS structure

## Description

Contains information about the status of the protocol.

## Members

### `Output`

A [WTS_PROTOCOL_COUNTERS](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wts_protocol_counters) structure that contains the output protocol counters.

### `Input`

A [WTS_PROTOCOL_COUNTERS](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wts_protocol_counters) structure that contains the input protocol counters.

### `Cache`

A [WTS_CACHE_STATS](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wts_cache_stats) structure that contains protocol cache statistics.

### `AsyncSignal`

An integer that identifies an asynchronous signal for asynchronous protocols.

### `AsyncSignalMask`

An asynchronous signal mask.

### `Counters`

An array of up to 100 counters.

## Remarks

This structure is used by the [GetProtocolStatus](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nf-wtsprotocol-iwtsprotocolconnection-getprotocolstatus) method.