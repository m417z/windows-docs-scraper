# NdisCloseAdapter function

## Description

**Note** NDIS 5. *x* has been deprecated and is superseded by NDIS 6. *x*. For new NDIS driver development, see [Network Drivers Starting with Windows Vista](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/). For information about porting NDIS 5. *x* drivers to NDIS 6. *x*, see [Porting NDIS 5.x Drivers to NDIS 6.0](https://msdn.microsoft.com/library/Ff570059).

**NdisCloseAdapter** releases the binding established and the resources allocated when the protocol called [**NdisOpenAdapter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapter).

## Parameters

### `Status` [out]

Pointer to a caller-supplied variable in which this function returns the status of the close operation, which can be one of the following values:

- NDIS\_STATUS\_SUCCESS
The binding was closed and all resources pertaining to that binding have been released.

- NDIS\_STATUS\_PENDING
A close-adapter request is being handled asynchronously, and the caller's [**ProtocolCloseAdapterComplete**](https://msdn.microsoft.com/library/ff562502/(v=vs.85/)) function will be called when the close operation is done.

### `NdisBindingHandle` [in]

Specifies the handle returned by **NdisOpenAdapter** that identifies the virtual adapter or NIC to be closed.

## Remarks

Return value: None

A protocol driver typically calls **NdisCloseAdapter** from its [**ProtocolUnbindAdapter**](https://msdn.microsoft.com/library/ff563260/(v=vs.85/)) function. It can also call **NdisCloseAdapter** from its [**ProtocolBindAdapter**](https://msdn.microsoft.com/library/ff562465/(v=vs.85/)) function, for example, if it failed to set an OID value after calling [**NdisOpenAdapter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapter) to set up a binding.

As soon as a protocol calls **NdisCloseAdapter**, the handle at *NdisBindingHandle* should be considered invalid by the caller. It is a programming error to pass this handle in any subsequent call to an *NdisXxx* function.

- Target platform: [Universal](https://go.microsoft.com/fwlink/p/?linkid=531356)
- Version: Not supported for NDIS 6.0 drivers in Windows Vista. Use NdisCloseAdapterEx instead. Supported for NDIS 5.1 drivers in Windows Vista and Windows XP.

## See also

- [**NdisCompleteUnbindAdapter**](https://msdn.microsoft.com/library/ff551048/(v=vs.85/))
- [**NdisOpenAdapter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapter)
- [**ProtocolCloseAdapterComplete**](https://msdn.microsoft.com/library/ff562502/(v=vs.85/))
- [**ProtocolUnbindAdapter**](https://msdn.microsoft.com/library/ff563260/(v=vs.85/))