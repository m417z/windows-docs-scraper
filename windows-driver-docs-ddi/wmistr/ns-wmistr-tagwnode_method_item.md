# tagWNODE_METHOD_ITEM structure

## Description

The **WNODE_METHOD_ITEM** structure indicates a method associated with an instance of a data block and contains any input data for the method.

## Members

### `WnodeHeader`

Is a [WNODE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmistr/ns-wmistr-_wnode_header) structure that contains information common to all **WNODE_*XXX*** structures, such as the buffer size, the GUID that represents a data block associated with a request, and flags that provide information about the **WNODE_*XXX*** data being passed or returned.

### `OffsetInstanceName`

Indicates the offset in bytes from the beginning of this structure to the dynamic instance name of this instance, aligned on a USHORT boundary. This member is valid only if WNODE_FLAG_STATIC_INSTANCE_NAMES is clear in **WnodeHeader.Flags**. If the data block was registered with static instance names, WMI ignores **OffsetInstanceName**.

### `InstanceIndex`

Indicates the index of this instance into the driver's list of static instance names for this data block. This member is valid only if the data block was registered with static instance names and WNODE_FLAG_STATIC_INSTANCE_NAMES is set in **WnodeHeader.Flags**. If the data block was registered with dynamic instance names, WMI ignores **InstanceIndex**.

### `MethodId`

Specifies the ID of the method to run.

### `DataBlockOffset`

Indicates the offset from the beginning of an input **WNODE_METHOD_ITEM** to input data for the method, or the offset from the beginning of an output **WNODE_METHOD_ITEM** to output data from the method.

### `SizeDataBlock`

Indicates the size of the input data in an input **WNODE_METHOD_ITEM**, or zero if there is no input. In an output **WNODE_METHOD_ITEM**, **SizeDataBlock** indicates the size of the output data, or zero if there is no output.

### `VariableData`

Contains additional data, including the dynamic instance name if any, and the input for or output from the method aligned on an 8-byte boundary.

## Remarks

WMI passes a **WNODE_METHOD_ITEM** with an [IRP_MN_EXECUTE_METHOD](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-execute-method) request to specify a method to run in an instance of a data block, plus any input data required by the method.

If a method generates output, a driver overwrites the input data with the output at **DataBlockOffset** in the buffer at **IrpStack->Parameters.WMI.Buffer**, and sets **SizeDataBlock** in the **WNODE_METHOD_ITEM** to specify the size of the output data.

## See also

[WNODE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmistr/ns-wmistr-_wnode_header)