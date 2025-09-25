# PEER_DATA structure

## Description

The **PEER_DATA** structure contains binary data.

## Members

### `cbData`

Size of **pbData**, in bytes. It is possible for this value to be set to zero if **pbData** contains no data.

### `pbData`

Pointer to a buffer.

### `pbData.size_is`

### `pbData.size_is.cbData`

## See also

[PEER_EVENT_INCOMING_DATA](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_event_incoming_data)

[PEER_RECORD](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_record)

[PFNPEER_FREE_SECURITY_DATA](https://learn.microsoft.com/windows/desktop/api/p2p/nc-p2p-pfnpeer_free_security_data)

[PFNPEER_SECURE_RECORD](https://learn.microsoft.com/windows/desktop/api/p2p/nc-p2p-pfnpeer_secure_record)