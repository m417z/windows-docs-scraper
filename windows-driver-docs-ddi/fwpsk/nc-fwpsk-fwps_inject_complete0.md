# FWPS_INJECT_COMPLETE0 callback function

## Description

The filter engine calls a callout's
*completionFn* callout function whenever packet data, described by the
*netBufferList* parameter in one of the
[packet injection functions](https://learn.microsoft.com/windows-hardware/drivers/network/packet-injection-functions), has been
injected into the network stack.

## Parameters

### `context` [in]

A pointer to the
*completionContext* parameter of one of the
[packet injection functions](https://learn.microsoft.com/windows-hardware/drivers/network/packet-injection-functions) called
by the callout driver.

### `netBufferList` [in, out]

The pointer passed in the
*netBufferList* parameter of one of the
[packet injection functions](https://learn.microsoft.com/windows-hardware/drivers/network/packet-injection-functions) called
by the callout driver.

### `dispatchLevel` [in]

A value that indicates the IRQL at which the
*completionFn* callout function is being called. If this parameter is **TRUE**, the
*completionFn* callout function is being called at IRQL = DISPATCH_LEVEL. If this parameter is
**FALSE**, the
*completionFn* callout function is being called at an IRQL < DISPATCH_LEVEL.

## Remarks

The FWPS_INJECT_COMPLETE0 type is defined as a pointer to the
*completionFn* function as follows:

```
typedef void (NTAPI *FWPS_INJECT_COMPLETE0) completionFn
```

The
**Status** member of the
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure pointed to by
*NetBufferList* indicates the result of the injection operation.

After packet data in a cloned or created [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure chain has successfully been
injected into the network stack by one of the
[packet injection functions](https://learn.microsoft.com/windows-hardware/drivers/network/packet-injection-functions),
*completionFn* is called.

If the
[FwpsStreamInjectAsync0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsstreaminjectasync0) function is
called to inject a chain of [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures,
*completionFn* will be called once for each **NET_BUFFER_LIST** in the chain, each time using the same
*completionContext* parameter specified in
**FwpsStreamInjectAsync0**. In this case, the callout driver's
*completionFn* implementation should call
[FwpsFreeCloneNetBufferList0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsfreeclonenetbufferlist0) to
free the currently indicated **NET_BUFFER_LIST**.

The filter engine calls a callout's
*completionFn* callout function at IRQL <= DISPATCH_LEVEL.

## See also

[Callout Driver Callout Functions](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/)

[FwpsCalloutRegister0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpscalloutregister0)

[FwpsCalloutRegister1](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpscalloutregister1)

[FwpsFreeCloneNetBufferList0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsfreeclonenetbufferlist0)

[FwpsInjectionHandleCreate0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsinjectionhandlecreate0)

[FwpsInjectionHandleDestroy0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsinjectionhandledestroy0)

[FwpsStreamInjectAsync0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsstreaminjectasync0)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[Packet Injection Functions](https://learn.microsoft.com/windows-hardware/drivers/network/packet-injection-functions)