# AUTHZ_RPC_INIT_INFO_CLIENT structure

## Description

The **AUTHZ_RPC_INIT_INFO_CLIENT** structure initializes a remote resource manager for a client.

## Members

### `version`

Version of the structure. The highest currently supported version is AUTHZ_RPC_INIT_INFO_CLIENT_VERSION_V1.

### `ObjectUuid`

Null-terminated string representation of the resource manager UUID. Only the following values are valid.

* Use “5fc860e0-6f6e-4fc2-83cd-46324f25e90b” for remote effective access evaluation that ignores central policy.
* Use “9a81c2bd-a525-471d-a4ed-49907c0b23da” for remote effective access evaluation that takes central policy into account.

### `ProtSeq`

Null-terminated string representation of a protocol sequence. This can be the following value.

* “ncacn_ip_tcp”.

### `NetworkAddr`

Null-terminated string representation of a network address. The network-address format is associated with the protocol sequence.

### `Endpoint`

Null-terminated string representation of an endpoint. The endpoint format and content are associated with the protocol sequence. For example, the endpoint associated with the protocol sequence [ncacn_np](https://learn.microsoft.com/windows/desktop/Midl/ncacn-np) is a pipe name in the format **\\***Pipe***\\***PipeName*.

### `Options`

Null-terminated string representation of network options. The option string is associated with the protocol sequence.

### `ServerSpn`

Server Principal Name (SPN) of the server. If this member is missing, it is constructed from **NetworkAddr** assuming "host" service class.

## Remarks

For a sample that uses this structure, see the [Effective access rights for files sample](https://github.com/microsoft/Windows-classic-samples/tree/master/Samples/Security/EffectiveAccessRights).