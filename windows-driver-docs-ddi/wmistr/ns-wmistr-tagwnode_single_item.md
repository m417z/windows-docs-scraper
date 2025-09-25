# tagWNODE_SINGLE_ITEM structure

## Description

The **WNODE_SINGLE_ITEM** structure contains the value of a single data item in an instance of a data block.

## Members

### `WnodeHeader`

Is a [WNODE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmistr/ns-wmistr-_wnode_header) structure that contains information common to all **WNODE_*XXX*** structures, such as the buffer size, the GUID that represents a data block associated with a request, and flags that provide information about the **WNODE_*XXX*** data being passed or returned.

### `OffsetInstanceName`

Indicates the offset from the beginning of this structure to the dynamic instance name, if any, aligned on a USHORT boundary. This member is valid only if WNODE_FLAG_STATIC_INSTANCE_NAMES is clear in **WnodeHeader.Flags**. If the data block was registered with static instance names, WMI ignores **OffsetInstanceName**.

### `InstanceIndex`

Indicates the index into the driver's list of static instance names of this instance. This member is valid only if the data block was registered with static instance names and WNODE_FLAG_STATIC_INSTANCE_NAMES is set in **WnodeHeader.Flags**. If the data block was registered with dynamic instance names, WMI ignores **InstanceIndex**.

### `ItemId`

Specifies the ID of the data item to set.

### `DataBlockOffset`

Indicates the offset from the beginning of this structure to the new value for the data item.

### `SizeDataItem`

Indicates the size of the data item.

### `VariableData`

Contains additional data, including the dynamic instance name if any, padding so the data value begins on an 8-byte boundary, and the new value for the data item.

## Remarks

WMI passes a **WNODE_SINGLE_ITEM** with an [IRP_MN_CHANGE_SINGLE_ITEM](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-change-single-item) request to set the value of a data item in an instance of a data block.

A driver builds a **WNODE_SINGLE_ITEM** to generate an event that consists of a single data item.

## See also

[WNODE_EVENT_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmistr/ns-wmistr-tagwnode_event_item)

[WNODE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmistr/ns-wmistr-_wnode_header)