# WDS_TRANSPORTCLIENT_REQUEST structure

## Description

This structure is used by the [WdsTransportClientStartSession](https://learn.microsoft.com/windows/desktop/api/wdstci/nf-wdstci-wdstransportclientstartsession) function.

## Members

### `ulLength`

The length of this structure in bytes.

### `ulApiVersion`

The version of the API that the caller is built against. The multicast client may reject the request based on this value.

This member must contain the following value.

| Value | Meaning |
| --- | --- |
| **WDS_TRANSPORT_CLIENT_CURRENT_API_VERSION**<br><br>1 | The current version. |

### `ulAuthLevel`

This member can contain one of the following values.

| Value | Meaning |
| --- | --- |
| **WDS_TRANSPORTCLIENT_AUTH**<br><br>0x1 | Authentication information about this user will be sent to the server. The server will use this information to determine if the user has access to this file. |
| **WDS_TRANSPORTCLIENT_NO_AUTH**<br><br>0x2 | No authentication information will be sent to the server. If the server is not configured to accept these requests, the request will fail. |

### `pwszServer`

Server name.

### `pwszNamespace`

Namespace of the object to retrieve.

### `pwszObjectName`

Specifies the name of the object to retrieve. Object names are
provider dependent.

### `ulCacheSize`

Specifies how much data in bytes the consumer can store in its queue. Once
this threshold is reached, the client will not send any more writes to
the consumer until some memory is released with
WdsTransportClientCompleteWrite.

### `ulProtocol`

Specifies the protocol to be used for this transfer.

This member can contain the following value.

| Value | Meaning |
| --- | --- |
| **WDS_TRANSPORTCLIENT_PROTOCOL_MULTICAST**<br><br>0x00000001 | The file will be transferred using an efficient multicast protocol. |

### `pvProtocolData`

Protocol data structure for the protocol. The structure is **NULL** for **WDS_TRANSPORTCLIENT_PROTOCOL_MULTICAST** protocol.

### `ulProtocolDataLength`

The length of the protocol data pointed to by **pvProtocolData**.