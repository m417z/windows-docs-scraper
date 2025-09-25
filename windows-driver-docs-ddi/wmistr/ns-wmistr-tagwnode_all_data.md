# tagWNODE_ALL_DATA structure

## Description

The **WNODE_ALL_DATA** structure contains data for all instances of a data block or event block.

## Members

### `WnodeHeader`

Specifies a [WNODE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmistr/ns-wmistr-_wnode_header) structure that contains information common to all **WNODE_*XXX*** structures, such as the buffer size, the GUID that represents a data block associated with a request, and flags that provide information about the **WNODE_*XXX*** data being passed or returned.

### `DataBlockOffset`

Indicates the offset in bytes from the beginning of the **WNODE_ALL_DATA** structure to the beginning of data for the first instance.

### `InstanceCount`

Indicates the number of instances whose data follows the fixed members of the **WNODE_ALL_DATA** in the buffer at **IrpStack->Parameters.WMI.Buffer**.

### `OffsetInstanceNameOffsets`

Indicates the offset in bytes from the beginning of the **WNODE_ALL_DATA** to an array of offsets to dynamic instance names. Each instance name must be aligned on a USHORT boundary. If all instances to be returned have static instance names, WMI ignores **OffsetInstanceNameOffsets**.

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.FixedInstanceSize`

Indicates the size of each instance to be returned if all such instances are the same size. This member is valid only if the driver sets WNODE_FLAG_FIXED_INSTANCE_SIZE in **WnodeHeader.Flags**.

### `DUMMYUNIONNAME.OffsetInstanceDataAndLength`

If instances to be returned vary in size, **OffsetInstanceDataAndLength** is an array of **InstanceCount** **OFFSETINSTANCEDATAANDLENGTH** structures that specify the offset in bytes from the beginning of the **WNODE_ALL_DATA** to the beginning of each instance and its length. **OFFSETINSTANCEDATAANDLENGTH** is defined as follows:

```
typedef struct {
  ULONG  OffsetInstanceData;
  ULONG  LengthInstanceData;
} OFFSETINSTANCEDATAANDLENGTH, *POFFSETINSTANCEDATAANDLENGTH;
```

Each instance must be aligned on a USHORT boundary. The **OffsetInstanceDataAndLength** member is valid only if the driver clears WNODE_FLAG_FIXED_INSTANCE_SIZE in **WnodeHeader.Flags**.

##### - OffsetInstanceDataAndLength.LengthInstanceData

Indicates the length in bytes of the instance data.

##### - OffsetInstanceDataAndLength.OffsetInstanceData

Indicates the offset in bytes from the beginning of the **WNODE_ALL_DATA** to the instance data.

## Remarks

A driver fills in a **WNODE_ALL_DATA** structure in response to an [IRP_MN_QUERY_ALL_DATA](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-all-data) request. A driver might also generate a **WNODE_ALL_DATA** as an event.

After filling in the fixed members of the structure, a driver writes instance data and dynamic instance names (if any) at **DataBlockOffset** and **OffsetInstanceNameOffsets**, respectively, in the buffer at **IrpStack->Parameters.WMI.Buffer**. If WNODE_FLAG_FIXED_INSTANCE_SIZE is clear, the first offset follows the last element of the **OffsetInstanceDataAndLength** array, plus padding so the data begins on an 8-byte boundary.

Instance names must be USHORT aligned. Instance data must be QUADWORD aligned.

## See also

[IRP_MN_QUERY_ALL_DATA](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-all-data)

[WNODE_EVENT_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmistr/ns-wmistr-tagwnode_event_item)

[WNODE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmistr/ns-wmistr-_wnode_header)