# FwpsQueryPacketInjectionState0 function

## Description

The
**FwpsQueryPacketInjectionState0** function is called by a callout to query the injection state of packet
data.

**Note** **FwpsQueryPacketInjectionState0** is a specific version of **FwpsQueryPacketInjectionState**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Parameters

### `injectionHandle` [in]

An injection handle that was previously created by a call to the
[FwpsInjectionHandleCreate0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsinjectionhandlecreate0) function.

### `netBufferList` [in]

A pointer to a
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure that describes
the packet data that is being classified. The packet can originate from the network stack, or it can be
injected into the network stack by a WFP callout driver.

### `injectionContext` [out, optional]

An optional handle to the injection context. If the pointer is specified, and if the packet
injection state
[FWPS_PACKET_INJECTION_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ne-fwpsk-fwps_packet_injection_state_) associated with the injection handle is FWPS_PACKET_INJECTED_BY_SELF
or FWPS_PACKET_PREVIOUSLY_INJECTED_BY_SELF, the injection context supplied when the packet was injected
will be returned.

## Return value

The
**FwpsQueryPacketInjectionState0** function returns one of the constant values of the
[FWPS_PACKET_INJECTION_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ne-fwpsk-fwps_packet_injection_state_) enumeration.

## Remarks

Because injected packet data can be reclassified against the callout that injected it, this function
allows a callout to inspect the injection history of packet data when necessary, thereby avoiding the
need to make repeated inspections of packet data that has already been inspected.

A callout can track other callout-specific information by specifying the optional
*injectionContext* handle in one of the
[packet injection functions](https://learn.microsoft.com/windows-hardware/drivers/network/packet-injection-functions) at the
time of packet data injection. If the
**FwpsQueryPacketInjectionState0** function returns **FWPS_PACKET_INJECTED_BY_SELF** or
**FWPS_PACKET_PREVIOUSLY_INJECTED_BY_SELF**, the supplied
*injectionContext* will be returned as the
*completionContext* parameter of the function that performed the injection.

If the return value is **FWPS_PACKET_INJECTED_BY_SELF** or **FWPS_PACKET_PREVIOUSLY_INJECTED_BY_SELF**, the
network buffer list pointed to by
*netBufferList* should not be further modified or pended as part of a cloning and injection
procedure. In this case, the callout should set the
**actionType** member of the
[FWPS_CLASSIFY_OUT0](https://learn.microsoft.com/windows/win32/api/fwpstypes/ns-fwpstypes-fwps_classify_out0) structure pointed to
by the
*classifyOut* parameter of the
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) function to either **FWP_ACTION_CONTINUE** or **FWP_ACTION_PERMIT**. This allows the packet to proceed to the next callout.

## See also

[FWPS_CLASSIFY_OUT0](https://learn.microsoft.com/windows/win32/api/fwpstypes/ns-fwpstypes-fwps_classify_out0)

[FWPS_PACKET_INJECTION_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ne-fwpsk-fwps_packet_injection_state_)

[FwpsInjectionHandleCreate0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsinjectionhandlecreate0)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/)