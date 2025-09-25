# SUPPORT_FUNCTIONS_50 structure

## Description

The
**SUPPORT_FUNCTIONS** structure is used by the router manager to pass the routing protocol a set of pointers to functions provided by the router manager.

## Members

### `_Align8`

### `dwVersion`

### `dwReserved`

### `DWORD`

TBD

### `BOOL`

TBD

#### - DemandDialRequest

The routing protocol calls
**DemandDialRequest** to initiate a demand-dial connection.

Pointer to the
[DemandDialRequest](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa373924(v=vs.85)) function provided by the router manager for the routing protocol.

#### ProtocolId

Specifies the identifier of the routing protocol on behalf of which the connection should be established. (Normally, this parameter is the identifier of the calling routing protocol.)

#### InterfaceIndex

Specifies the identifier of the interface for which the connection should be established.

#### - MIBEntryCreate

The routing protocol calls
**MIBEntryCreate** to execute a Create request of the router manager or a peer protocol DLL. Implement this function to handle SNMP-style requests.

Pointer to the
[MIBEntryCreate](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa374538(v=vs.85)) function provided by the router manager for the routing protocol.

#### dwRoutingPid

Specifies the identifier of the DLL that should process this request. This parameter may be the identifier of the router manager or the identifier of a routing protocol.

#### InputDataSize

Specifies the size, in bytes, of the data to pass with the Create request.

#### InputData

Pointer to the data to pass with the Create request.

#### - MIBEntryDelete

Pointer to the
[MIBEntryDelete](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa374539(v=vs.85)) function provided by the router manager for the routing protocol.

#### - MIBEntryGet

The routing protocol calls
**MIBEntryGet** to execute a Get request of the router manager or a peer protocol DLL. Implement this function to handle SNMP-style requests.

Pointer to the
[MIBEntryGet](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa374540(v=vs.85)) function provided by the router manager for the routing protocol.

#### dwRoutingPid

Specifies the identifier of the DLL that processes this request. This parameter can be the identifier of the router manager or the identifier of a routing protocol.

#### InputDataSize

Specifies the size, in bytes, of the data to pass with the Get request.

#### InputData

Pointer to the data to pass with the Get request.

#### OutputDataSize

A pointer to a **DWORD** variable:

On input, this variable contains the size, in bytes, of the output buffer.

On output, this variable contains the size, in bytes, of the data placed in the output buffer. If the initial size is not large enough, this variable contains the buffer size required to hold all of the output data.

#### OutputData

Receives the pointer to a buffer that holds the data from the MIB entry.

#### - MIBEntryGetFirst

The routing protocol calls
**MIBEntryGetFirst** to execute a Get First request of the router manager or a peer protocol DLL. Implement this function to handle SNMP-style requests.

Pointer to the
[MIBEntryGetFirst](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa374541(v=vs.85)) function provided by the router manager for the routing protocol.

#### dwRoutingPid

Specifies the identifier of the DLL that should process this request. This parameter can be the identifier of the router manager or the identifier of a routing protocol.

#### InputDataSize

Specifies the size, in bytes, of the data to pass with the Get First request.

#### InputData

Pointer to the data to pass with the Get First request.

#### OutputDataSize

A pointer to a **DWORD** variable:

On input, this variable specifies the size, in bytes, of the output buffer.

On output, this variable receives the size, in bytes, of the data placed in the output buffer. If the initial size is not large enough, this variable contains the buffer size required to hold all of the output data.

#### OutputData

Pointer to a buffer that receives the data from the MIB entry.

#### - MIBEntryGetNext

The routing protocol calls
**MIBEntryGetNext** to execute a Get Next request of the router manager or a peer protocol DLL. Implement this function to handle SNMP-style requests.

Pointer to the
[MIBEntryGetNext](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa374542(v=vs.85)) function provided by the router manager for the routing protocol.

#### dwRoutingPid

Specifies the identifier of the DLL that processes this request. This parameter can be the identifier of the router manager or the identifier of a routing protocol.

#### InputDataSize

Specifies the size, in bytes, of the data to pass with the Get Next request.

#### InputData

Pointer to the data to pass with the Get Next request.

#### OutputDataSize

A pointer to a **DWORD** variable:

On input, this variable specifies the size, in bytes, of the output buffer.

On output this variable receives the size, in bytes, of the data placed in the output buffer. If the initial size is not large enough, this variable contains the buffer size required to hold all of the output data.

#### OutputData

Pointer to a buffer that holds the data from the MIB entry.

#### - MIBEntrySet

The routing protocol calls
**MIBEntrySet** to execute an SNMP MIB-style Set request of the router manager or a peer protocol DLL.

Pointer to the
[MIBEntrySet](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa374543(v=vs.85)) function provided by the router manager for the routing protocol.

#### dwRoutingPid

Specifies the identifier of the DLL that processes this request. This parameter can be the identifier of the router manager or the identifier of a routing protocol.

#### InputDataSize

Specifies the size, in bytes, of the data to pass with the Set request.

#### InputData

Pointer to the data to pass with the Set request.

#### - SetInterfaceReceiveType

The routing protocol calls the
**SetInterfaceReceiveType** function to set the receive capability of the specified interface.

Pointer to the
[SetInterfaceReceiveType](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa382181(v=vs.85)) function provided by the router manager for the routing protocol.

#### ProtocolId

Specifies the identifier of the routing protocol that makes the call.

#### InterfaceIndex

Specifies the index of the interface on which to set the receive type.

#### InterfaceReceiveType

Specifies the receive type. This parameter must be one of the following values.

IR_PROMISCUOUS

IR_PROMISCUOUS_MULTICAST

#### bActivate

Specifies whether to activate the interface.

#### - ValidateRoute

The routing protocol calls the
**ValidateRoute** function to set the route preference and perform other route validation.

Pointer to the
[ValidateRoute](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa382342(v=vs.85)) function provided by the router manager for the routing protocol.

#### ProtocolId

Specifies the identifier of the routing protocol that makes the call.

#### RouteInfo

Pointer to information that describes the route to validate.

#### DestAddress

Pointer to information that describes the destination address. This parameter is optional and can be **NULL**.

## See also

[StartProtocol](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pstart_protocol)