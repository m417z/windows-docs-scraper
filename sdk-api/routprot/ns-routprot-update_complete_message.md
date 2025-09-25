# UPDATE_COMPLETE_MESSAGE structure

## Description

The
**UPDATE_COMPLETE_MESSAGE** structure contains information describing the completion status of an update operation.

## Members

### `InterfaceIndex`

Identifies the interface over which the update was performed.

### `UpdateType`

Indicates the type of information that was received in this update. This member is one of the following values:

| Value | Meaning |
| --- | --- |
| **DEMAND_UPDATE_ROUTES** | Routing information was reported to the routing table manager. |
| **DEMAND_UPDATE_SERVICES** | Services information that is accessible through the Services Table Management functions provided by the routing protocol. |

### `UpdateStatus`

Indicates the result of the update operation.

| Value | Meaning |
| --- | --- |
| **NO_ERROR** | The update was completed successfully. |
| **ERROR_CAN_NOT_COMPLETE** | The update was unsuccessful. |

## See also

[MESSAGE](https://learn.microsoft.com/windows/desktop/api/routprot/ns-routprot-message)

[Routing Protocol Interface Reference](https://learn.microsoft.com/windows/desktop/RRAS/routing-protocol-interface-reference)

[Routing Protocol Interface Structures](https://learn.microsoft.com/windows/desktop/RRAS/routing-protocol-interface-structures)