# PFN_WdsTransportClientReceiveMetadata callback function

## Description

PFN_WdsTransportClientReceiveMetadata is an optional callback that a consumer may register to receive metadata type information about a file. This information is provided by the content provider and is opaque to the multicast client and server.

## Parameters

### `hSessionKey` [in]

The handle belonging to the session that is being started.

### `pCallerData` [in]

Pointer to the caller specific data for this session. This data was specified in the call to [WdsTransportClientStartSession](https://learn.microsoft.com/windows/desktop/api/wdstci/nf-wdstci-wdstransportclientstartsession) function.

### `pMetadata` [in]

Data provided by the content provider that is associated with this object in some manner.

### `ulSize` [in]

The size of the *pMetadata* buffer in bytes.