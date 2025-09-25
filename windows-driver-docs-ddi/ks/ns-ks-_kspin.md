# _KSPIN structure

## Description

The KSPIN structure describes an instantiated pin.

## Members

### `Descriptor`

A pointer to the pin descriptor for this particular pin. See [KSPIN_DESCRIPTOR_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin_descriptor_ex) for more information.

### `Bag`

This member specifies the KSOBJECT_BAG (the KSOBJECT_BAG structure is equivalent to type PVOID) for this particular pin instance. [Object Bags](https://learn.microsoft.com/windows-hardware/drivers/stream/object-bags) are structures used to associate dynamic memory with a specific AVStream object. Anything in the pin object bag is automatically cleaned up when the pin is closed.

### `Context`

A pointer to a buffer. Clients can use **Context** to associate context information with a specific pin instance. Typically, this is used for pin/stream extensions and is allocated in the create dispatch provided in the pin dispatch table. Note that any dynamic memory allocated for context information should be placed in the pin instance's object bag using [KsAddItemToObjectBag](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksadditemtoobjectbag). **Context** is initialized to the value of the **Context** member of the parent [KSFILTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter) at the time the pin is created. See [AVStream Object Hierarchy](https://learn.microsoft.com/windows-hardware/drivers/stream/avstream-object-hierarchy).

### `Id`

This member specifies the pin type identifier. This is the index into the array of pin descriptors provided for the given filter type.

### `Communication`

This member specifies KSPIN_COMMUNICATION_NONE, KSPIN_COMMUNICATION_SINK, KSPIN_COMMUNICATION_SOURCE, KSPIN_COMMUNICATION_BOTH or KSPIN_COMMUNICATION_BRIDGE. See [KSPROPERTY_PIN_COMMUNICATION](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-pin-communication) for the meaning of each value.

### `ConnectionIsExternal`

This member specifies a Boolean value that, if **TRUE**, indicates that the connected pin does not support the AVStream connection handshake. If **FALSE**, indicates that the connected pin supports the AVStream connection handshake. This is an indication of whether the connection between this pin and the pin it is connected to is a connection between two AVStream pins.

### `ConnectionInterface`

This member contains a [KSPIN_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/stream/kspin-interface-structure) structure that identifies the interface being used for the connection. This information is supplied by the graph builder when the pin is created.

### `ConnectionMedium`

This member contains a [KSPIN_MEDIUM](https://learn.microsoft.com/windows-hardware/drivers/stream/kspin-medium-structure) structure that identifies the connection medium this pin should use. This information is supplied by the graph builder when the pin is created.

### `ConnectionPriority`

This member contains a [KSPRIORITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kspriority) structure that specifies the priority of the connection. This information is supplied by the graph builder when the pin is created.

### `ConnectionFormat`

A pointer to a [KSDATAFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksdataformat) structure that specifies the data format of the connection. This information is initially supplied by the graph builder when the pin is created and may be changed through property access or by format change messages inserted into the stream. Access to this member is synchronized by the filter control mutex. This member should not be changed by the client.

### `AttributeList`

A pointer to a [KSMULTIPLE_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksmultiple_item) structure that specifies the list of attributes, supplied during pin creation, to describe the connection. Specifies the direction of data flow for this pin (KSPIN_DATAFLOW_IN or KSPIN_DATAFLOW_OUT). This information is a static attribute of the pin and appears in the pin descriptor. It is cached here for access at IRQL above PASSIVE_LEVEL.

### `StreamHeaderSize`

This member indicates the size in bytes of each [KSSTREAM_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksstream_header) structure for this pin. Typically used for output pins, a client can set this to any value greater than **sizeof** *(KSSTREAM_HEADER)* and have extended stream headers allocated (each stream header will be **StreamHeaderSize** bytes long). If a client does not set this member, this indicates that no extended information follows stream headers. In such a situation, each stream header is precisely **sizeof** *(KSSTREAM_HEADER)*. Clients can set this in the pin creation dispatch.

### `DataFlow`

This member specifies the direction of data flow for the pin. Possible settings are **KSPIN_DATAFLOW_IN** and KSPIN_DATAFLOW_OUT. This information is a static attribute of the pin and appears in relevant [KSPIN_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kspin_descriptor) structure. It is cached here for access at IRQL above PASSIVE_LEVEL.

### `DeviceState`

This member contains an enumeration of type [KSSTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ne-ks-ksstate) that identifies the state to which the pin has been told to transition. Not necessarily the same as the state of the pipe, which is reported through [AVStrMiniPinSetDeviceState](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnkspinsetdevicestate). Initially KSSTATE_STOP, this member is changed when AVStream receives a connection state property set IOCTL. Access is synchronized using the [filter control mutex](https://learn.microsoft.com/windows-hardware/drivers/stream/filter-control-mutex-in-avstream). Minidrivers should not change this member. See note in Remarks section below. Also see the *ClientState* member.

### `ResetState`

This member contains an enumeration of type KSRESET that identifies the current reset state of the pin. Possible settings are KSRESET_BEGIN and KSRESET_END. This member is initially set to KSRESET_END and is changed through property access. Access to this member is synchronized by the [filter control mutex](https://learn.microsoft.com/windows-hardware/drivers/stream/filter-control-mutex-in-avstream). The client should not change this member.

### `ClientState`

This member specifies the [KSSTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ne-ks-ksstate) at which the pin is currently set. Updated immediately before [AVStrMiniPinSetDeviceState](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnkspinsetdevicestate) is called. If this callback routine fails, AVStream rolls back *ClientState* to its previous value. Minidrivers that fail state transitions and that check this member during processing should be aware of this sequence of events.

## Remarks

In many ways, pins are the focus of filter behavior. This is reflected in the fact that the pin structure has a large number of members. Many minidrivers need to refine pin behavior and maintain additional pin-associated context. For filters with fairly conventional pin behavior, no additional refinement or context is required. In many cases, default pin behavior is sufficient; the pins are accessed using [Filter-Centric Processing](https://learn.microsoft.com/windows-hardware/drivers/stream/filter-centric-processing).

For synchronization purposes, the lifetime of this object is the interval starting when the minidriver's PreCreate dispatch function is called and ending when the minidriver's Close dispatch function returns, assuming the function does not return STATUS_PENDING. If it does return STATUS_PENDING, the object's lifetime ends when the client indicates completion of the close request by calling [KsCompletePendingRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kscompletependingrequest).

If the minidriver needs to determine whether it has been told to go to a specific [KSSTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ne-ks-ksstate), comparing the value of the **DeviceState** member of KSPIN to that state is not a reliable method. Instead, either look at the *ClientState* member, or create a variable in the **SetDeviceState** callback and then check this variable. **SetDeviceState** is a member of [KSPIN_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin_dispatch).

Also see [Object Bags](https://learn.microsoft.com/windows-hardware/drivers/stream/object-bags).

## See also

[KSPIN_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kspin_descriptor)

[KSPIN_DESCRIPTOR_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin_descriptor_ex)

[KSPIN_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin_dispatch)

[KsAddItemToObjectBag](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksadditemtoobjectbag)

[KsCompletePendingRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kscompletependingrequest)