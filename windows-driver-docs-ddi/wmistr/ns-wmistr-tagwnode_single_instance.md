# tagWNODE_SINGLE_INSTANCE structure

## Description

The **WNODE_SINGLE_INSTANCE** structure contains values for all data items in one instance of a data block.

## Members

### `WnodeHeader`

Is a [WNODE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmistr/ns-wmistr-_wnode_header) structure that contains information common to all **WNODE_*XXX*** structures, such as the buffer size, the GUID that represents a data block associated with a request, and flags that provide information about the **WNODE_*XXX*** data being passed or returned.

### `OffsetInstanceName`

Indicates the offset from the beginning of this structure to the dynamic instance name of this instance, aligned on a USHORT boundary. This member is valid only if WNODE_FLAG_STATIC_INSTANCE_NAMES is clear in **WnodeHeader.Flags**. If the data block was registered with static instance names, WMI ignores **OffsetInstanceName**.

### `InstanceIndex`

Indicates the index of an instance registered with static instance names. This member is valid only if WNODE_FLAG_STATIC_INSTANCE_NAMES is set in **WnodeHeader.Flags**. If the data block was registered with dynamic instance names, WMI ignores **InstanceIndex**.

### `DataBlockOffset`

Indicates the offset from the beginning of this structure to the beginning of the instance.

### `SizeDataBlock`

Indicates the size of the data block for this instance.

### `VariableData`

Contains additional data, including the dynamic instance name if any, padding so the instance begins on an 8-byte boundary, and the instance of the data block to be returned.

## Remarks

WMI passes a **WNODE_SINGLE_INSTANCE** with an [IRP_MN_CHANGE_SINGLE_INSTANCE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-change-single-instance) request to set read/write data items in an instance of a data block. A driver can ignore values passed for read-only data items in the instance.

A driver fills in a **WNODE_SINGLE_INSTANCE** in response to an [IRP_MN_QUERY_SINGLE_INSTANCE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-single-instance) request or to generate an event that consists of a single instance.

## See also

[WNODE_EVENT_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmistr/ns-wmistr-tagwnode_event_item)

[WNODE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmistr/ns-wmistr-_wnode_header)