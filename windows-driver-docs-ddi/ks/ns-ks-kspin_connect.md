# KSPIN_CONNECT structure

## Description

Clients use the KSPIN_CONNECT structure to describe the connection they request from a driver in a [KsCreatePin](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kscreatepin) call.

## Members

### `Interface`

Specifies the [KSPIN_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/stream/kspin-interface-structure) to use for this connection.

### `Medium`

A structure of type [KSPIN_MEDIUM](https://learn.microsoft.com/windows-hardware/drivers/stream/kspin-medium-structure) that specifies the medium to use for this connection.

### `PinId`

Specifies the pin type ID number. If the PinToHandle field is not **NULL**, this field contains the identifier of the source pin to which the request is being sent. Otherwise this field refers to the sink pin that is being connected to. If a pin can support being both a source and sink in communications, then this is the implicit method of telling it how it should act in the connection.

### `PinToHandle`

Specifies what type of destination pin the create is intended for, and in the case of a source destination, what pin to connect to. This member is **NULL** when a client requests a connection to itself. Otherwise, it is the target of the connection request. In the case of a source destination, this contains the handle of the pin instance to establish a connection to. In the case of a sink destination, this field contains **NULL**, and is not otherwise used.

### `Priority`

A structure of type [KSPRIORITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kspriority) that specifies the priority for the connection, usually KSPRIORITY_NORMAL. See the [KSPROPERTY_CONNECTION_PRIORITY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-connection-priority) property for details.

## Remarks

If the KSPIN_CONNECT.PinToHandle element is not **NULL**, IRP_MJ_CREATE instructs the device to connect the source KSPIN_CONNECT.PinId pin to the KSPIN_CONNECT.PinToHandle pin instance. Otherwise, this is a request from a client for connection to the KSPIN_CONNECT.PinId pin using the KSPIN_CONNECT.Medium method and a specific data format specified after the connection structure. In either case, the device driver may fail this request if this connection cannot be accepted.

## See also

[KSPIN_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/stream/kspin-interface-structure)

[KSPROPERTY_CONNECTION_PRIORITY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-connection-priority)

[KsCreatePin](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kscreatepin)