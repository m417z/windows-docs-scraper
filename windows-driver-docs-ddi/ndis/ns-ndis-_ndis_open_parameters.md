# _NDIS_OPEN_PARAMETERS structure

## Description

The NDIS_OPEN_PARAMETERS structure defines the open parameters when a protocol driver calls the
[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex) function.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
NDIS_OPEN_PARAMETERS structure. Set the
**Type** member of the structure that
**Header** specifies to NDIS_OBJECT_TYPE_OPEN_PARAMETERS, the
**Revision** member to NDIS_OPEN_PARAMETERS_REVISION_1, and the
**Size** member to the NDIS_SIZEOF_OPEN_PARAMETERS_REVISION_1.

### `AdapterName`

A Unicode string that contains the name of the miniport adapter that NDIS passed to
[ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex) in the
**AdapterName** member of the
*BindParameters* parameter. This name can identify a physical adapter (that is, a NIC) or a virtual
adapter that is associated with an intermediate driver.

### `MediumArray`

A pointer to an array of
**NdisMedium*Xxx*** values that lists the types of media the caller can support. This list is a subset of the
[NDIS_MEDIUM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_medium) types.

### `MediumArraySize`

The number of elements in the
**MediumArray** member.

### `SelectedMediumIndex`

A pointer to a driver-provided UINT variable that contains an index into the
**MediumArray** array. NDIS writes this index which identifies the media type that the underlying
driver uses.

### `FrameTypeArray`

A pointer to an array of NET_FRAME_TYPE values, specifying the frame types that you want the
protocol driver to receive. The frame type is a USHORT value that follows the destination and source MAC
address in Ethernet frames. In the presence of VLAN tags, this value follows the destination, source MAC
address, and VLAN tag. NET_FRAME_TYPE is defined as follows:

```
typedef USHORT  NET_FRAME_TYPE;
typedef NET_FRAME_TYPE *PNET_FRAME_TYPE;
```

**Note** NDIS uses the frame type values that the protocol driver provides in this array as
a hint to optimize the receive indications that NDIS sends to the protocol driver. NDIS does not
guarantee that a protocol driver will receive only packets with frame types that match the types in the
array.

### `FrameTypeArraySize`

The number of elements in the
**FrameTypeArray** member. This number must be equal to or less than
NDIS_MAX_FRAME_TYPES_PER_OPEN.

## Remarks

A protocol driver passes an NDIS_OPEN_PARAMETERS structure when it calls the
[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex) function to open a
miniport adapter.

## See also

[NDIS_MEDIUM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_medium)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex)

[ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex)