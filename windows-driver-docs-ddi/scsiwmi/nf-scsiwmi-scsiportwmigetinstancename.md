# ScsiPortWmiGetInstanceName function

## Description

The **ScsiPortWmiGetInstanceName** routine returns a pointer to the instance name associated with the indicated the [Windows Management Instrumentation](https://learn.microsoft.com/windows-hardware/drivers/kernel/implementing-wmi) (WMI) SCSI Request Block (SRB).

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `RequestContext` [in]

Pointer to a structure of type [SCSIWMI_REQUEST_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/ns-scsiwmi-scsiwmi_request_context) that contains the request context for a WMI SRB.

## Return value

Pointer to a counted string containing the instance name associated with the indicated SRB. If the SRB type is one that does not use an instance name, **ScsiPortWmiGetInstanceName** returns **NULL**.

## Remarks

The parameter **RequestContext** points to a request context structure, [SCSIWMI_REQUEST_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/ns-scsiwmi-scsiwmi_request_context), that contains information associated with a [Windows Management Instrumentation](https://learn.microsoft.com/windows-hardware/drivers/kernel/implementing-wmi) (WMI) SCSI request block (SRB). The request context structure, in turn, contains one of the [WMI WNODE_XXX Structures](https://learn.microsoft.com/windows-hardware/drivers/kernel/wmi-wnode-xxx-structures) that is used by the WMI system to pass data between user-mode data consumers and kernel-mode data providers such as drivers.

The WNODE_XXX structure contained in the request context holds an instance name associated with the WMI SRB. The miniport driver calls **ScsiPortWmiGetInstanceName** to extract this instance name from the request context.

The memory allocated for the request context must remain valid until after the miniport driver calls **ScsiPortWmiPostProcess**, and **ScsiPortWmiPostProcess** returns the final SRB status and buffer size. If the SRB can pend, the memory for the request context should be allocated from the SRB extension. If the SRB cannot pend, the memory can be allocated from a stack frame that does not go out of scope.

## See also

[SCSIWMI_REQUEST_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/ns-scsiwmi-scsiwmi_request_context)

[WNODE_ALL_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmistr/ns-wmistr-tagwnode_all_data)

[WNODE_SINGLE_INSTANCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmistr/ns-wmistr-tagwnode_single_instance)