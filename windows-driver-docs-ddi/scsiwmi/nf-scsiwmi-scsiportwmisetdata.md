# ScsiPortWmiSetData function

## Description

The **ScsiPortWmiSetData** routine updates the [WNODE_ALL_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmistr/ns-wmistr-tagwnode_all_data) structure within the request context to specify the position and length of the data for an instance.

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `RequestContext` [in]

Pointer to a structure of type [SCSIWMI_REQUEST_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/ns-scsiwmi-scsiwmi_request_context) that contains the request context for a WMI SRB.

### `InstanceIndex` [in]

Contains an index that indicates the instance for which the position and length of the instance data are to be specified.

### `DataLength` [in]

Specifies the number of bytes of data required to describe the instance.

### `BufferAvail` [out]

Must contain, on input, the number of bytes of buffer space in the [WNODE_ALL_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmistr/ns-wmistr-tagwnode_all_data) structure that can be used for describing instance names and data. On return, this member contains the number of bytes of buffer space that remain.

There are three SCSI Port WMI routines that return a value for the available buffer size in their *BufferAvail* parameter:

[ScsiPortWmiSetInstanceCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmisetinstancecount)

**ScsiPortWmiSetData**

[ScsiPortWmiSetInstanceName](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmisetinstancename)

The miniport driver must call **ScsiPortWmiSetInstanceCount** first, but after **ScsiPortWmiSetInstanceCount** has been called, it does not matter in what order the minidriver calls **ScsiPortWmiSetData** and **ScsiPortWmiSetInstanceName**. When calling either **ScsiPortWmiSetData** or **ScsiPortWmiSetInstanceName**, the value passed to the routine in its *BufferAvail* parameter must be the same as the value returned in the *BufferAvail* parameter by the most recently called SCSI Port WMI routine. For instance, suppose the minidriver calls **ScsiPortWmiSetInstanceCount** first, and this routine returns a value of 1,000 in its *BufferAvail* parameter. Next, the minidriver calls **ScsiPortWmiSetData** which returns a value of 500 in its *BufferAvail* parameter. Finally, the minidriver calls **ScsiPortWmiSetInstanceName** which returns a value of 200 in its *BufferAvail* parameter. The initial value of 1,000 must be passed to **ScsiPortWmiSetData** in *BufferAvail*, and the value of 500 must be passed to **ScsiPortWmiSetInstanceName**.

If there is not enough memory available to add new instance data of size *DataLength* bytes*,* a zero will be returned in the *BufferAvail* member.

### `SizeNeeded` [in, out]

Indicates, on input, the number of bytes needed to describe the entire WNODE *before* adding the descriptive data for the instance specified by *InstanceIndex*. On return, this member will contain the size of the WNODE, including the data for the new instance.

## Return value

The **ScsiPortWmiSetData** routine returns a pointer to the buffer where the caller can store descriptive information about the instance identified by *InstanceIndex*. If **ScsiPortWmiSetData** cannot allocate enough memory for the instance data, or if the WNODE contained within the request context is not of type [WNODE_ALL_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmistr/ns-wmistr-tagwnode_all_data), **ScsiPortWmiSetData** returns **NULL**.

## Remarks

The minidriver must call [ScsiPortWmiSetInstanceCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmisetinstancecount) before calling **ScsiPortWmiSetData**.

The parameter **RequestContext** points to a request context structure, [SCSIWMI_REQUEST_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/ns-scsiwmi-scsiwmi_request_context), that contains information associated with a [Windows Management Instrumentation](https://learn.microsoft.com/windows-hardware/drivers/kernel/implementing-wmi) (WMI) SCSI request block (SRB). The request context structure, in turn, contains one of the [WMI WNODE_XXX Structures](https://learn.microsoft.com/windows-hardware/drivers/kernel/wmi-wnode-xxx-structures) that is used by the WMI system to pass data between user-mode data consumers and kernel-mode data providers such as drivers.

The **ScsiPortWmiSetData** routine requires the WNODE structure that is defined within the request context to be of type [WNODE_ALL_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmistr/ns-wmistr-tagwnode_all_data). This is because **ScsiPortWmiSetData** can specify the location and length of the data buffers for any of the instances associated with a WMI data block. Unlike the [WNODE_SINGLE_INSTANCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmistr/ns-wmistr-tagwnode_single_instance) structure which contains information about a single instance, the WNODE_ALL_DATA structure contains an array of pointers to buffer areas for multiple instances, and **ScsiPortWmiSetData** uses the *InstanceIndex* parameter as an index into this array to initialize the appropriate array element for a particular instance. Each array element, once initialized, contains the size and location of a buffer area for an instance.

The memory allocated for the request context must remain valid until after the miniport driver calls **ScsiPortWmiPostProcess**, and **ScsiPortWmiPostProcess** returns the final SRB status and buffer size. If the SRB can pend, the memory for the request context should be allocated from the SRB extension. If the SRB cannot pend, the memory can be allocated from a stack frame that does not go out of scope.

## See also

[SCSIWMI_REQUEST_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/ns-scsiwmi-scsiwmi_request_context)

[WNODE_ALL_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmistr/ns-wmistr-tagwnode_all_data)

[WNODE_SINGLE_INSTANCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmistr/ns-wmistr-tagwnode_single_instance)