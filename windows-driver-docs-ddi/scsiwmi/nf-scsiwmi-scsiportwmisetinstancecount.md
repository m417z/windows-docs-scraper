# ScsiPortWmiSetInstanceCount function

## Description

The **ScsiPortWmiSetInstanceCount** specifies the number of instances for which data buffers must be set aside within the [WNODE_ALL_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmistr/ns-wmistr-tagwnode_all_data) structure in the request context.

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `RequestContext` [in]

Pointer to a structure of type [SCSIWMI_REQUEST_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/ns-scsiwmi-scsiwmi_request_context) that contains the request context for a WMI SRB.

### `InstanceCount` [in]

Contains the number of instances for which the minidriver will provide data.

### `BufferAvail` [out]

Contains, on return, the number of bytes of buffer space available for describing instance names and data. The value that is returned in this member can be passed to routines [ScsiPortWmiSetData](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmisetdata) and [ScsiPortWmiSetInstanceName](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmisetinstancename) in the *BufferAvail* parameter of those routines.

The **ScsiPortWmiSetInstanceCount** routine initializes an array of pointers to data buffers, with one array element for each instance. If there is not enough memory available in the WNODE to initialize an array of size *InstanceCount*, a zero will be returned in this member.

### `SizeNeeded` [out]

Indicates, on input, the number of bytes needed to describe the entire WNODE *before* configuring the internal arrays in the WNODE. On return, this member will contain the size of the entire WNODE, including the newly initialized arrays within the WNODE.

## Return value

The **ScsiPortWmiSetInstanceCount** routine returns **TRUE** if the operation succeeds and **FALSE** if the WNODE contained within the request context is not of type [WNODE_ALL_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmistr/ns-wmistr-tagwnode_all_data).

## Remarks

The minidriver must call **ScsiPortWmiSetInstanceCount** before calling either [ScsiPortWmiSetData](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmisetdata) or [ScsiPortWmiSetInstanceName](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmisetinstancename). The minidriver should only call **ScsiPortWmiSetInstanceCount** once.

The parameter **RequestContext** points to a request context structure, [SCSIWMI_REQUEST_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/ns-scsiwmi-scsiwmi_request_context), that contains information associated with a [Windows Management Instrumentation](https://learn.microsoft.com/windows-hardware/drivers/kernel/implementing-wmi) (WMI) SCSI request block (SRB). The request context structure, in turn, contains one of the [WMI WNODE_XXX Structures](https://learn.microsoft.com/windows-hardware/drivers/kernel/wmi-wnode-xxx-structures) used by the WMI system to pass data between user-mode data consumers and kernel-mode data providers such as drivers.

The **ScsiPortWmiSetInstanceCount** routine requires the WNODE structure that is defined within the request context to be of type [WNODE_ALL_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmistr/ns-wmistr-tagwnode_all_data). This is because **ScsiPortWmiSetInstanceCount** sets aside a data area that will hold information for multiple instances associated with a WMI data block. Unlike the [WNODE_SINGLE_INSTANCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmistr/ns-wmistr-tagwnode_single_instance) structure which contains information about a single instance, the WNODE_ALL_DATA structure contains an array of pointers to buffer areas for different instances, and **ScsiPortWmiSetInstanceCount** initializes this array, so that each buffer of instance data can be accessed individually using an instance index.

The memory allocated for the request context must remain valid until after the miniport driver calls **ScsiPortWmiPostProcess**, and **ScsiPortWmiPostProcess** returns the final SRB status and buffer size. If the SRB can pend, the memory for the request context should be allocated from the SRB extension. If the SRB cannot pend, the memory can be allocated from a stack frame that does not go out of scope.

## See also

[SCSIWMI_REQUEST_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/ns-scsiwmi-scsiwmi_request_context)

[WNODE_ALL_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmistr/ns-wmistr-tagwnode_all_data)

[WNODE_SINGLE_INSTANCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmistr/ns-wmistr-tagwnode_single_instance)