# PCPROPERTY_ITEM structure

## Description

The **PCPROPERTY_ITEM** structure describes a property that is supported by a particular filter, pin, or node.

## Members

### `Set`

Specifies the property set. This member is a pointer to a GUID that uniquely identifies the property set. See the list of property-set GUIDs in [Audio Drivers Property Sets](https://learn.microsoft.com/windows-hardware/drivers/audio/audio-drivers-property-sets).

### `Id`

Specifies the property ID. This member identifies a property item within the property set. If the property set contains N items, valid property IDs are integers in the range 0 to N-1.

### `Flags`

Specifies the types of property requests that the driver supports. Set this member to the bitwise OR of some or all of the flag bits that appear in the following table.

| Flag bits | Type of property request |
| --- | --- |
| PCPROPERTY_ITEM_FLAG_GET | Request to get the current property data setting. |
| PCPROPERTY_ITEM_FLAG_SET | Request to set the current property data setting. |
| PCPROPERTY_ITEM_FLAG_DEFAULTVALUES | Request for the driver's default values for the property data. |
| PCPROPERTY_ITEM_FLAG_BASICSUPPORT | Request for basic support, which specifies which request types the driver handles for this property, and also specifies the valid data type and the valid ranges for the property data. |
| PCPROPERTY_ITEM_FLAG_SERIALIZESIZE | Request for the size of the property data for this property when it is serialized as part of a KSPROPERTY_TYPE_SERIALIZESET request. |
| PCPROPERTY_ITEM_FLAG_SERIALIZERAW | Request to serialize this property in a driver-dependent manner. This operation is the inverse of PCPROPERTY_ITEM_FLAG_UNSERIALIZERAW. |
| PCPROPERTY_ITEM_FLAG_UNSERIALIZERAW | Request to unserialize this property in a driver-dependent manner. This operation is the inverse of PCPROPERTY_ITEM_FLAG_SERIALIZERAW. |
| PCPROPERTY_ITEM_FLAG_SERIALIZE | PCPROPERTY_ITEM_FLAG_SERIALIZERAW | PCPROPERTY_ITEM_FLAG_UNSERIALIZERAW | PCPROPERTY_ITEM_FLAG_SERIALIZESIZE |

### `Handler`

Pointer to the property-handler routine. This member is a function pointer of type PCPFNPROPERTY_HANDLER, which is defined as follows:

```
  typedef NTSTATUS (*PCPFNPROPERTY_HANDLER)
  (
      IN PPCPROPERTY_REQUEST  PropertyRequest
  );
```

See the following Remarks section.

## Remarks

The **PCPROPERTY_ITEM** structure specifies a particular property item in an automation table. The [PCAUTOMATION_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ns-portcls-pcautomation_table) structure points to an array of **PCPROPERTY_ITEM** structures.

When calling the **Handler** routine, the caller passes in a single call parameter, which is a pointer to a [PCPROPERTY_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ns-portcls-_pcproperty_request) structure. This structure is allocated by the caller, and the caller frees it under either of the following conditions:

1. If the **Handler** routine returns any status code other than STATUS_PENDING, the caller frees the structure. In this case, the miniport driver should not attempt to access the structure after the **Handler** routine returns.
2. The **Handler** routine can also return STATUS_PENDING, in which case the miniport driver is obliged to call [PcCompletePendingPropertyRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pccompletependingpropertyrequest) at a later time to complete the pending property request. The **PcCompletePendingPropertyRequest** function frees the structure. After calling **PcCompletePendingPropertyRequest**, the miniport driver should not attempt to access the structure.

If the miniport driver attempts to access the structure after it has been freed, this action is likely to cause a bug check or to corrupt another driver's memory.

For more information about serialization and raw serialization of a property set, see [KS Properties](https://learn.microsoft.com/windows-hardware/drivers/stream/ks-properties).

## See also

[PCPROPERTY_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ns-portcls-_pcproperty_request)

[PcCompletePendingPropertyRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pccompletependingpropertyrequest)