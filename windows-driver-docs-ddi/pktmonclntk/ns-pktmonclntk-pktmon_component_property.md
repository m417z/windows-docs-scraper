## Description

The **PKTMON_COMPONENT_PROPERTY** structure defines various properties for a Packet Monitor component.

## Members

### `Id`

Specifies the identifier for the component property. This field is of type **[PKTMON_COMPONENT_PROPERTY_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmondefk/ne-pktmondefk-pktmon_component_property_id)**.

### `IfIndex`

Specifies the interface index. Use this field when the property ID is **PktMonCompProp_IfIndex**.

### `MiniportIfIndex`

Specifies the miniport interface index. Use this field when the property ID is **PktMonCompProp_MiniportIfIndex**.

### `LowerIfIndex`

Specifies the lower interface index. Use this field when the property ID is **PktMonCompProp_LowerIfIndex**.

### `VmsExtIfIndex`

Specifies the VMS extension interface index. Use this field when the property ID is **PktMonCompProp_VmsExtIfIndex**.

### `LowestIfIndex`

Specifies the lowest interface index. Use this field when the property ID is **PktMonCompProp_LowestIfIndex**.

### `NdisMedium`

Specifies the NDIS medium type. Use this field when the property ID is **PktMonCompProp_NdisMedium**.

### `IpIfIndex`

Specifies the IP interface index. Use this field when the property ID is **PktMonCompProp_IpIfIndex**.

### `Vsid`

Specifies the virtual subnet ID. Use this field when the property ID is **PktMonCompProp_Vsid**.

### `Vlan`

Specifies the VLAN ID. Use this field when the property ID is **PktMonCompProp_Vlan**.

### `CompartmentId`

Specifies the compartment ID. Use this field when the property ID is **PktMonCompProp_CompartmentId**.

### `OptDataPath`

Specifies the optional data path. Use this field when the property ID is **PktMonCompProp_OptDataPath**.

### `NdisObject`

Specifies the NDIS object type. Use this field when the property ID is **PktMonCompProp_NdisObject**.

### `EtherType`

Specifies the EtherType. Use this field when the property ID is **PktMonCompProp_EtherType**.

### `IfGuid`

Specifies the interface GUID. Use this field when the property ID is **PktMonCompProp_IfGuid**.

### `MacAddress`

Specifies the MAC address. Use this field when the property ID is **PktMonCompProp_PhysAddress**.

### `VMSwitchName[PKTMON_MAX_PROPERTY_LENGTH_BYTES]`

Specifies the name of the VM switch. Use this field when the property ID is **PktMonCompProp_VMSwitchName**.

### `SockAddr`

Specifies the socket address. Use this field when the property ID is **PktMonCompProp_IpAddress**.

## Remarks

## See also

- **[PktMon**ClntSetComponentProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntk/nf-pktmonclntk-pktmonclntsetcomponentproperty)**
- **[PKTMON_COMPONENT_PROPERTY_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmondefk/ne-pktmondefk-pktmon_component_property_id)**