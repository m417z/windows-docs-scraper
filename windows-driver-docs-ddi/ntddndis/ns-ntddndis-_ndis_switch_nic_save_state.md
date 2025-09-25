# _NDIS_SWITCH_NIC_SAVE_STATE structure

## Description

The **NDIS_SWITCH_NIC_SAVE_STATE** structure specifies the run-time state information for a Hyper-V extensible switch port. The extensible switch extension uses this structure to save or restore run-time port information.

## Members

### `Header`

The type, revision, and size of the **NDIS_SWITCH_NIC_SAVE_STATE** structure. This member is formatted as an [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The **Type** member of **Header** must be set to NDIS_OBJECT_TYPE_DEFAULT. To specify the version of the **NDIS_SWITCH_NIC_SAVE_STATE** structure, the **Revision** member of **Header** must be set to the following value:

#### NDIS_SWITCH_NIC_SAVE_STATE_REVISION_1

Original version for NDIS 6.30 and later.

Set the **Size** member to NDIS_SIZEOF_NDIS_SWITCH_NIC_SAVE_STATE_REVISION_1.

### `Flags`

A ULONG value that contains a bitwise **OR** of flags. This member is reserved for NDIS.

### `PortId`

An NDIS_SWITCH_PORT_ID value that contains the unique identifier of the extensible switch port.

### `NicIndex`

An NDIS_SWITCH_NIC_INDEX value that contains the Nic Index for the network adapter. This value will always be 0. For more information, see [Network Adapter Index Values](https://learn.microsoft.com/windows-hardware/drivers/network/network-adapter-index-values).

### `ExtensionId`

A GUID value that identifies the extensible switch extension.

### `ExtensionFriendlyName`

 An NDIS_SWITCH_EXTENSION_FRIENDLYNAME value that specifies the user-friendly description of the extensible switch extension.

### `FeatureClassId`

A GUID value that contains the identifier of the feature class related to the saved data. A feature class identifier is defined by the extension to uniquely identify components of its run-time data.

**Note** This member is optional. The extensible switch extension must set this member to 0 if the saved data has no feature class.

### `SaveDataSize`

A USHORT value that specified the size, in bytes, of the data that is contained in the **SaveData** member.

**Note** This value must be less than or equal to NDIS_SWITCH_NIC_SAVE_STATE_MAX_DATA_SIZE.

### `SaveDataOffset`

A USHORT value that contains the offset from the start of the structure to the run-time state information being saved or restored.

### `SaveDataSizeOverflow`

## Remarks

The **NDIS_SWITCH_NIC_SAVE_STATE** structure is used in the following OID requests:

* [OID_SWITCH_NIC_SAVE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-nic-save)
* [OID_SWITCH_NIC_SAVE_COMPLETE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-nic-save-complete)
* [OID_SWITCH_NIC_RESTORE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-nic-restore)
* [OID_SWITCH_NIC_RESTORE_COMPLETE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-nic-restore-complete)

**Note** The NDIS_SWITCH_EXTENSION_FRIENDLYNAME data type is type-defined by the [IF_COUNTED_STRING](https://learn.microsoft.com/windows/win32/api/ifdef/ns-ifdef-if_counted_string_lh) structure. A string that is defined by this structure does not have to be null-terminated. However, the length of the string must be set in the **Length** member of this structure. If the string is null-terminated, the **Length** member must not include the terminating null character.

For more information on how to save or restore run-time port information, see [Managing Hyper-V Extensible Switch Run-Time Data](https://learn.microsoft.com/windows-hardware/drivers/network/managing-hyper-v-extensible-switch-run-time-data).

## See also

[IF_COUNTED_STRING](https://learn.microsoft.com/windows/win32/api/ifdef/ns-ifdef-if_counted_string_lh)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[OID_SWITCH_NIC_RESTORE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-nic-restore)

[OID_SWITCH_NIC_SAVE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-nic-save)

[OID_SWITCH_NIC_SAVE_COMPLETE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-switch-nic-save-complete)