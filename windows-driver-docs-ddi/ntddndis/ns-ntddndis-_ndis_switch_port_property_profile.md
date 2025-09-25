# _NDIS_SWITCH_PORT_PROPERTY_PROFILE structure

## Description

The **NDIS_SWITCH_PORT_PROPERTY_PROFILE** structure specifies a policy property for a Hyper-V extensible switch port that the extensible switch extension saves in its own policy store instead of in the Hyper-V policy store. In this case, policy definitions are identified by property profiles within the driver's policy store.

## Members

### `Header`

The type, revision, and size of the **NDIS_SWITCH_PORT_PROPERTY_PROFILE** structure. This member is formatted as an [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The **Type** member of **Header** must be set to NDIS_OBJECT_TYPE_DEFAULT. To specify the version of the **NDIS_SWITCH_PORT_PROPERTY_PROFILE** structure, the **Revision** member of **Header** must be set to the following value:

#### NDIS_SWITCH_PORT_PROPERTY_PROFILE_REVISION_1

Original version for NDIS 6.30 and later.

Set the **Size** member to NDIS_SIZEOF_NDIS_SWITCH_PROPERTY_PROFILE_REVISION_1.

### `Flags`

A ULONG value that contains a bitwise **OR** of flags. This member is reserved for NDIS.

### `ProfileName`

An NDIS_SWITCH_PORT_PROPERTY_PROFILE_NAME value that specifies the user-friendly name of the profile property.

### `ProfileId`

A GUID value that uniquely identifies the profile property.

### `VendorName`

An NDIS_VENDOR_NAME value that specifies the user-friendly name of the vendor that defined the port profile.

### `VendorId`

A GUID value that identifies the vendor that defined the port profile.

### `ProfileData`

### `NetCfgInstanceId`

A GUID value that specifies the **NetCfgInstanceId** registry value of the underlying network adapter connection for which the property is applied.

The **NetCfgInstanceId** value is specified for the network adapter connection through an object identifier (OID) set request of [OID_SWITCH_NIC_CREATE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-nic-create).

### `PciLocation`

A structure that specifies the PCI location of the underlying physical network adapter that is specified by the **NetCfgInstanceId** member.

For more information, see the Remarks section.

### `PciLocation.PciSegmentNumber`

A value that specifies the group of PCI buses on which the physical network adapter is attached.

### `PciLocation.PciBusNumber`

A value that specifies the current PCI bus number on which the physical network adapter is attached.

### `PciLocation.PciDeviceNumber`

A value that specifies the device number for the physical network adapter on the PCI bus.

**Note** The PCI device number is also known as the *PCI slot number*.

### `PciLocation.PciFunctionNumber`

A value that specifies the function number of a logical device on the physical network adapter.

### `CdnLabelId`

A UINT32 value that specifies a unique identifier for the data that is contained in the **CdnLabel** member.

### `CdnLabel`

An NDIS_SWITCH_PORT_PROPERTY_PROFILE_CDN_LABEL value that specifies the PCI Express (PCIe) CDN label for the location of the physical network adapter. A CDN label provides consistent device locations across similar hardware locations.

## Remarks

The **NDIS_SWITCH_PORT_PROPERTY_PROFILE** structure is used by the extension to reference a policy property within a private policy store instead of the Hyper-V policy store. This allows the independent software vendor (ISV) to populate and manage this private policy store through private channels and interfaces. Vendors can distinguish their profiles from other vendors' profiles using the *VendorName* and *VendorId* fields.

**Note** Port policy properties specified by an **NDIS_SWITCH_PORT_PROPERTY_PROFILE** structure are transparent to the extensible switch interface.

The **NDIS_SWITCH_PORT_PROPERTY_PROFILE** structure is used in the following OID set requests:

* [OID_SWITCH_PORT_PROPERTY_ADD](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-port-property-add)
* [OID_SWITCH_PORT_PROPERTY_UPDATE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-port-property-update)

The **NDIS_SWITCH_PORT_PROPERTY_PROFILE** structure follows the [NDIS_SWITCH_PORT_PROPERTY_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_parameters) structure in the buffer that is associated with these OID set requests. The **InformationBuffer** member of the [NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure contains a pointer to this buffer.

**Note** The **NDIS_SWITCH_PORT_PROPERTY_PROFILE_NAME** and **NDIS_SWITCH_PORT_PROPERTY_PROFILE_CDN_LABEL** data types are type-defined by the [IF_COUNTED_STRING](https://learn.microsoft.com/windows/win32/api/ifdef/ns-ifdef-if_counted_string_lh) structure. A string that is defined by this structure does not have to be null-terminated. However, the length of the string must be set in the **Length** member of this structure. If the string is null-terminated, the **Length** member must not include the terminating null character.

The **PciLocation** and **CdnLabel** members are only relevant if the property profile specifies a policy for an underlying physical network adapter that is attached to the extensible switch external network adapter. For example, if the external network adapter is bound to an extensible switch team of adapters, these members could specify policies for a single adapter from that team. For more information about the extensible switch team, see [Types of Physical Network Adapter Configurations](https://learn.microsoft.com/windows-hardware/drivers/network/types-of-physical-network-adapter-configurations).

## See also

[IF_COUNTED_STRING](https://learn.microsoft.com/windows/win32/api/ifdef/ns-ifdef-if_counted_string_lh)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request)

[NDIS_SWITCH_PORT_PROPERTY_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_parameters)

[OID_SWITCH_NIC_CREATE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-nic-create)

[OID_SWITCH_PORT_PROPERTY_ADD](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-port-property-add)

[OID_SWITCH_PORT_PROPERTY_UPDATE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-port-property-update)