# _BTHDDI_SDP_NODE_INTERFACE structure

## Description

The BTHDDI_SDP_NODE_INTERFACE structure provides functions for manipulating SDP records, including
converting them to and from a tree representation that profile drivers can more easily parse.

## Members

### `Interface`

A structure that describes the
**BTHDDI_SDP_NODE_INTERFACE** interface for use by profile drivers. For more information about this
structure, see
[INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_interface).

### `SdpCreateNodeTree`

A pointer to the
[SdpCreateNodeTree](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpcreatenodetree) function.

### `SdpFreeTree`

A pointer to the
[SdpFreeTree](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpfreetree) function
*.*

### `SdpCreateNodeNil`

A pointer to the
[SdpCreateNodeNil](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpcreatenodenil) function.

### `SdpCreateNodeBoolean`

A pointer to the
[SdpCreateNodeBoolean](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpcreatenodeboolean) function.

### `SdpCreateNodeUint8`

A pointer to the
[SdpCreateNodeUInt8](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpcreatenodeuint8) function.

### `SdpCreateNodeUint16`

A pointer to the
[SdpCreateNodeUInt16](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpcreatenodeuint16) function.

### `SdpCreateNodeUint32`

A pointer to the
[SdpCreateNodeUInt32](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpcreatenodeuint32) function.

### `SdpCreateNodeUint64`

A pointer to the
[SdpCreateNodeUInt64](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpcreatenodeuint64) function.

### `SdpCreateNodeUint128`

A pointer to the
[SdpCreateNodeUInt128](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpcreatenodeuint128) function.

### `SdpCreateNodeInt8`

A pointer to the
[SdpCreateNodeInt8](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpcreatenodeint8) function.

### `SdpCreateNodeInt16`

A pointer to the
[SdpCreateNodeInt16](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpcreatenodeint16) function.

### `SdpCreateNodeInt32`

A pointer to the
[SdpCreateNodeInt32](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpcreatenodeint32) function.

### `SdpCreateNodeInt64`

A pointer to the
[SdpCreateNodeInt64](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpcreatenodeint64) function.

### `SdpCreateNodeInt128`

A pointer to the
[SdpCreateNodeInt128](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpcreatenodeint128) function.

### `SdpCreateNodeUuid16`

A pointer to the
[SdpCreateNodeUUID16](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpcreatenodeuuid16) function.

### `SdpCreateNodeUuid32`

A pointer to the
[SdpCreateNodeUUID32](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpcreatenodeuuid32) function.

### `SdpCreateNodeUuid128`

A pointer to the
[SdpCreateNodeUUID128](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpcreatenodeuuid128) function.

### `SdpCreateNodeString`

A pointer to the
[SdpCreateNodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpcreatenodestring) function.

### `SdpCreateNodeUrl`

A pointer to the
[SdpCreateNodeUrl](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpcreatenodeurl) function.

### `SdpCreateNodeAlternative`

A pointer to the
[SdpCreateNodeAlternative](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpcreatenodealternative) function.

### `SdpCreateNodeSequence`

A pointer to the
[SdpCreateNodeSequence](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpcreatenodesequence) function.

### `SdpAddAttributeToTree`

A pointer to the
[SdpAddAttributeToTree](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpaddattributetotree) function.

### `SdpAppendNodeToContainerNode`

A pointer to the
[SdpAppendNodeToContainerNode](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpappendnodetocontainernode) function.

## Remarks

Profile drivers should specify the
**GUID_BTHDDI_SDP_NODE_INTERFACE** GUID to query for an instance of the BTHDDI_SDP_NODE_INTERFACE
structure from the Bluetooth driver stack.

All the members of this structure, other than the
**Interface** member, are function pointers.

## See also

[INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_interface)

[SdpAddAttributeToTree](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpaddattributetotree)

[SdpAppendNodeToContainerNode](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpappendnodetocontainernode)

[SdpCreateNodeAlternative](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpcreatenodealternative)

[SdpCreateNodeBoolean](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpcreatenodeboolean)

[SdpCreateNodeInt128](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpcreatenodeint128)

[SdpCreateNodeInt16](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpcreatenodeint16)

[SdpCreateNodeInt32](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpcreatenodeint32)

[SdpCreateNodeInt64](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpcreatenodeint64)

**SdpCreateNodeInt8**

[SdpCreateNodeNil](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpcreatenodenil)

[SdpCreateNodeSequence](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpcreatenodesequence)

[SdpCreateNodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpcreatenodestring)

[SdpCreateNodeTree](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpcreatenodetree)

[SdpCreateNodeUInt128](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpcreatenodeuint128)

[SdpCreateNodeUInt16](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpcreatenodeuint16)

[SdpCreateNodeUInt32](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpcreatenodeuint32)

[SdpCreateNodeUInt64](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpcreatenodeuint64)

[SdpCreateNodeUInt8](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpcreatenodeuint8)

[SdpCreateNodeUUID128](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpcreatenodeuuid128)

[SdpCreateNodeUUID16](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpcreatenodeuuid16)

[SdpCreateNodeUUID32](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpcreatenodeuuid32)

[SdpCreateNodeUrl](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpcreatenodeurl)

[SdpFreeTree](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdplib/nf-sdplib-sdpfreetree)