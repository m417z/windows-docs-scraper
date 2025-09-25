# PFN_WdsTransportClientSessionStart callback function

## Description

The PFN_WdsTransportClientSessionStart callback is called at the start of a multicast session to indicate file size and other server side information about the file to the consumer.

## Parameters

### `hSessionKey` [in]

The handle belonging to the session that is being started.

### `pCallerData` [in]

Pointer to the caller specific data for this session. This data was specified in the call to WdsTransportClientStartSession.

### `ullFileSize`

#### - FileSize [in]

The total size of the file being transferred over multicast.