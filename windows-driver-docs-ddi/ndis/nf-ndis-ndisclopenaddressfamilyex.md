# NdisClOpenAddressFamilyEx function

## Description

The
**NdisClOpenAddressFamilyEx** function registers an address family (AF) that is associated with a call
manager for a connection-oriented client.

## Parameters

### `NdisBindingHandle` [in]

The handle that
[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex) returns and that
identifies the target network interface card (NIC) or the virtual adapter of the next-lower driver that
the caller is bound to.

### `AddressFamily` [in]

A pointer to a
[CO_ADDRESS_FAMILY](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff545368(v=vs.85)) structure that describes
the call manager and AF to be opened.

This pointer is an input parameter to the client's
[ProtocolCoAfRegisterNotify](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_af_register_notify) function, which calls
**NdisClOpenAddressFamilyEx**.

### `ClientAfContext` [in]

The handle to a caller-supplied resident context area in which the client maintains state for this
AF after the AF has been opened. NDIS passes this handle back to the client in all subsequent calls
concerning this AF if the call to
**NdisClOpenAddressFamilyEx** succeeds.

### `NdisAfHandle` [out]

A pointer to a caller-supplied variable in which
**NdisClOpenAddressFamilyEx** returns a handle that represents the newly opened address family.

## Return value

When
**NdisClOpenAddressFamilyEx** returns anything other than NDIS_STATUS_PENDING, the client should make
an internal call to its
[ProtocolClOpenAfCompleteEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_open_af_complete_ex) function. Otherwise, NDIS calls the client's
*ProtocolClOpenAfCompleteEx* function when this operation is completed.

## Remarks

A CoNDIS client calls
**NdisClOpenAddressFamilyEx** from its
[ProtocolCoAfRegisterNotify](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_af_register_notify) function, after the client checks the input buffer that is pointed to by
the
*AddressFamily* parameter to determine whether the client recognizes the call manager and registered
addresses. NDIS forwards the client's call of
**NdisClOpenAddressFamilyEx** to the call manager's
[ProtocolCmOpenAf](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_open_af) function, which
ensures that the client has passed in a valid AF structure.

A successful call to
**NdisClOpenAddressFamilyEx** sets up communication from the client to a call manager. The client can
then prepare to receive incoming calls by calling the
[NdisClRegisterSap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclregistersap) function. The client
can also set up a virtual connection (VC) by calling the
[NdisCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscocreatevc) function so it can make an
outgoing call by calling the
[NdisClMakeCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclmakecall) function.

If the client's call to
**NdisClOpenAddressFamilyEx** fails, the client should call the
[NdisUnbindAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisunbindadapter) function to request
NDIS to release its binding to the underlying miniport adapter. Otherwise, the client must save the
handle that is returned at the
*NdisAfHandle* parameter. This handle identifies the call manager to which subsequent requests concerning the given address
family are directed. The client must treat this returned handle as an opaque variable, passing it
unmodified and uninterpreted in subsequent
**Ndis*Xxx*** function calls.

NDIS passes the pointer from the
*ClientAfContext* parameter to the client's registered
*ProtocolClXxx* functions in all subsequent calls that concern the AF until the client calls
**NdisClCloseAddressFamily** with the same
*NdisAfHandle* . After the AF is closed, the client can release or reuse the storage that it
allocated at
*ClientAfContext* .

## See also

[CO_ADDRESS_FAMILY](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff545368(v=vs.85))

[NdisAllocateFromNPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatefromnpagedlookasidelist)

[NdisClCloseAddressFamily](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclcloseaddressfamily)

[NdisClMakeCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclmakecall)

[NdisClRegisterSap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclregistersap)

[NdisCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscocreatevc)

[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex)

[NdisUnbindAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisunbindadapter)

[ProtocolClOpenAfCompleteEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_open_af_complete_ex)

[ProtocolCmOpenAf](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_open_af)

[ProtocolCoAfRegisterNotify](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_af_register_notify)