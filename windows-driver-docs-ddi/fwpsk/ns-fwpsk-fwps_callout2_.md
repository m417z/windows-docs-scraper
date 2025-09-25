# FWPS_CALLOUT2_ structure

## Description

The **FWPS_CALLOUT2** structure defines the data that is required for a callout driver to register a
callout with the filter engine.

**Note** **FWPS_CALLOUT2** is the specific version of **FWPS_CALLOUT** used in Windows 8 and later. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information. For Windows 7, [FWPS_CALLOUT1](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_callout1_) is available. For Windows Vista, [FWPS_CALLOUT0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_callout0_) is available.

## Members

### `calloutKey`

A callout driver-defined **GUID** that uniquely identifies the callout.

### `flags`

Flags that specify callout-specific parameters. Possible flags are:

| Value | Meaning |
| --- | --- |
| **FWP_CALLOUT_FLAG_CONDITIONAL_ON_FLOW**<br><br>0x00000001 | A callout driver can specify this flag when registering a callout that will be added at a layer that supports data flows. If this flag is specified, the filter engine calls the callout driver's [classifyFn2](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_callout_classify_fn2) callout function only if there is a context associated with the data flow. A callout driver associates a context with a data flow by calling the [FwpsFlowAssociateContext0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsflowassociatecontext0) function. |
| **FWP_CALLOUT_FLAG_ALLOW_OFFLOAD**<br><br>0x00000002 | A callout driver specifies this flag to indicate that the callout driver's [classifyFn2](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_callout_classify_fn2) callout function is unaffected by offloading network data processing to offload-capable network interface cards (NICs). If this flag is not specified, then offloading of network data processing is disabled for all traffic that is processed by any filters that specify the callout for the filter's action. |
| **FWP_CALLOUT_FLAG_ENABLE_COMMIT_ADD_NOTIFY**<br><br>0x00000004 | A callout driver specifies this flag to indicate that it can receive notifications about objects and filters that are added inside a transaction. The filter engine sends the notification after the transaction is committed. |
| **FWP_CALLOUT_FLAG_ALLOW_MID_STREAM_INSPECTION**<br><br>0x00000008 | A callout driver specifies this flag to indicate that it can perform dynamic stream inspection of data flows at stream level. See [Stream Inspection](https://learn.microsoft.com/windows-hardware/drivers/network/stream-inspection). |
| **FWP_CALLOUT_FLAG_ALLOW_RECLASSIFY**<br><br>0x00000010 | A callout driver specifies this flag to register itself to be called when an existing socket operation is reclassified. |
| **FWP_CALLOUT_FLAG_RESERVED1**<br><br>0x00000020 | Reserved for system use. Callout drivers should ignore this flag. |
| **FWP_CALLOUT_FLAG_ALLOW_RSC**<br><br>0x00000040 | A callout driver specifies this flag to indicate that the callout supports TCP receive segment coalescing (RSC) with large packets of up to 64K. If this flag is not specified, and a callout is registered, then RSC is disabled for all traffic that is processed by any filters that specify the callout for the filter's action. |
| **FWP_CALLOUT_FLAG_ALLOW_L2_BATCH_CLASSIFY**<br><br>0x00000080 | A callout driver specifies this flag when registering a callout that will be added at layer 2, to indicate that its [classifyFn2](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_callout_classify_fn2) callout function can classify multiple chained [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures. For more info, see [Using Layer 2 Filtering](https://learn.microsoft.com/windows-hardware/drivers/network/using-layer-2-filtering).<br><br>**Caution**<br><br>If a callout driver sets this flag, it cannot use the following functions to modify NET_BUFFER_LISTs.<br><br>* [FwpsReferenceNetBufferList0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsreferencenetbufferlist0)<br>* [FwpsDereferenceNetBufferList0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsdereferencenetbufferlist0)<br>* [FwpsAllocateCloneNetBufferList0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsallocateclonenetbufferlist0)<br>* [FwpsFreeCloneNetBufferList0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsfreeclonenetbufferlist0)<br><br>With this flag set, **FwpsAllocateCloneNetBufferList0** will always return an **INVALID_PARAMETER** error. This may unexpectedly cause a 3rd party callout driver to fail to manage the reference count of NET_BUFFER_LISTs, causing send and receive operations to stop. |
| **FWP_CALLOUT_FLAG_ALLOW_USO**<br><br>0x00000100 | A callout driver specifies this flag to indicate that the callout supports UDP segmentation offload (USO) with packets larger than the MTU of the network medium. If this flag is not specified, and a callout is registered, then USO is disabled for all traffic that is processed by any filters that specify the callout for the filter's action. **Note:** The earliest version on which this flag is supported is Windows Insider Preview, version 10.0.25876. |
| **FWP_CALLOUT_FLAG_ALLOW_URO**<br><br>0x00000200 | A callout driver specifies this flag to indicate that the callout supports UDP receive offload (URO) with large packets of up to 64K. If this flag is not specified, and a callout is registered, then URO is disabled for all traffic that is processed by any filters that specify the callout for the filter's action. **Note:** If this flag is specified then callouts must not clone and reinject inbound URO packets. |

### `classifyFn`

A pointer to the callout driver's
[classifyFn2](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_callout_classify_fn2) callout function. The filter
engine calls this function whenever there is network data to be processed by the callout.

### `notifyFn`

A pointer to the callout driver's
[notifyFn2](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_callout_notify_fn2) function. The filter engine calls
this function to notify the callout driver about events that are associated with the callout.

### `flowDeleteFn`

A pointer to the callout driver's
[flowDeleteFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_callout_flow_delete_notify_fn0) callout function. The filter
engine calls this function whenever a data flow that is being processed by the callout is terminated.

If a callout driver does not associate a context with the data flows that the callout processes, then
this member should be set to NULL.

## Remarks

A callout driver passes a pointer to an initialized **FWPS_CALLOUT2** structure to the
[FwpsCalloutRegister2](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpscalloutregister2) function when it
registers a callout with the filter engine.

A callout can set the **FWP_CALLOUT_FLAG_CONDITIONAL_ON_FLOW** flag only for connections on which
the driver is interested in performing stream inspections. This callout will be ignored on all other
connections. Performance will be improved and the driver will not have to maintain unnecessary state
data.

This structure is essentially identical to the previous version,
[FWPS_CALLOUT1](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_callout1_). The only differences are that
the members of this version store the updated versions of the callout function pointers, and additional flags are available for callout drivers to set.

## See also

[FWPS_CALLOUT0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_callout0_)

[FWPS_CALLOUT1](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_callout1_)

[FwpsCalloutRegister2](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpscalloutregister2)

[Using Layer 2 Filtering](https://learn.microsoft.com/windows-hardware/drivers/network/using-layer-2-filtering)

[classifyFn2](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_callout_classify_fn2)

[flowDeleteFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_callout_flow_delete_notify_fn0)

[notifyFn2](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_callout_notify_fn2)