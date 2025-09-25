# FwpsInjectvSwitchEthernetIngressAsync0 function

## Description

The **FwpsInjectvSwitchEthernetIngressAsync0** (was **FwpsInjectvSwitchIngressAsync0**) function reinjects a previously absorbed virtual switch packet (unmodified) back to the virtual switch ingress data path where it was intercepted. This function can also inject a packet created with the [FwpsAllocateNetBufferAndNetBufferList0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsallocatenetbufferandnetbufferlist0) function.

**Note** **FwpsInjectvSwitchEthernetIngressAsync0** is a specific version of **FwpsInjectvSwitchEthernetIngressAsync**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Parameters

### `injectionHandle` [in]

An injection handle that was previously created by a call to the [FwpsInjectionHandleCreate0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsinjectionhandlecreate0) function with the *flags* parameter set to **FWPS_INJECTION_TYPE_L2**.

The *addressFamily* parameter is not used and should be set to **AF_UNSPEC**.

### `injectionContext` [in, optional]

An optional handle to the injection context that can be retrieved with the [FwpsQueryPacketInjectionState0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsquerypacketinjectionstate0) function.

### `flags` [in]

Reserved. Must be set to zero.

### `reserved` [in, optional]

Reserved. Must be set to NULL.

### `vSwitchId` [in]

The virtual switch identifier that the filtering engine passed in the
[FWPS_INCOMING_VALUES0](https://learn.microsoft.com/windows/win32/api/fwpstypes/ns-fwpstypes-fwps_incoming_values0) structure to the callout driver's
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) callout function. This is the **GUID** of the virtual switch that is provided in an xxx_VSWITCH_ID field.

### `vSwitchSourcePortId` [in]

The virtual switch source port identifier.

### `vSwitchSourceNicIndex` [in]

The virtual switch source NIC index.

### `netBufferLists`

A chain of [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures to be injected into the virtual switch egress data path.

### `completionFn` [in]

A pointer to a
[completionFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_inject_complete0) callout function that is provided by
the callout driver. The filter engine calls this function after the packet data, at the
*netBufferLists* parameter, has been injected into the virtual switch egress data path. The
*completionFn* function will be called once for each [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) in the chain. *completionFn* must be specified when injecting cloned or created **NET_BUFFER_LIST** structures. This parameter can be NULL when injecting original unaltered **NET_BUFFER_LIST** structures that were received from the filter engine.

### `completionContext` [in, optional]

A pointer to a callout driver–provided context that is passed to the callout function pointed to
by the
*completionFn* parameter. This parameter is optional and can be **NULL**.

## Return value

The
**FwpsInjectvSwitchEthernetIngressAsync0** function returns one of the following **NTSTATUS** codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The virtual switch [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) chain was successfully injected. |
| **Other status codes** | An error occurred. |

## Remarks

When a callout injects packets with **FwpsInjectvSwitchEthernetIngressAsync0**, the injected packets could be classified again if the packets match the same filter as they were originally classified. Therefore, like callouts at IP layers, virtual switch callouts must call the [FwpsQueryPacketInjectionState0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsquerypacketinjectionstate0) function to protect against infinite packet inspections.

## See also

[FWPS_INCOMING_VALUES0](https://learn.microsoft.com/windows/win32/api/fwpstypes/ns-fwpstypes-fwps_incoming_values0)

[FwpsAllocateNetBufferAndNetBufferList0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsallocatenetbufferandnetbufferlist0)

[FwpsInjectionHandleCreate0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsinjectionhandlecreate0)

[FwpsQueryPacketInjectionState0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsquerypacketinjectionstate0)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[completionFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_inject_complete0)