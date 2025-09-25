# PFN_WdsTransportClientSessionStartEx callback function

## Description

The PFN_WdsTransportClientSessionStart callback is called at the start of a multicast session to indicate file size and other server side information about the file to the consumer.

## Parameters

### `hSessionKey` [in]

The handle belonging to the session that is being started.

### `pCallerData` [in]

Pointer to the caller specific data for this session. This data was specified in the call to WdsTransportClientStartSession.

### `Info` [in]

This parameter receives a pointer to a [TRANSPORTCLIENT_SESSION_INFO](https://learn.microsoft.com/windows/desktop/api/wdstci/ns-wdstci-transportclient_session_info) structure.