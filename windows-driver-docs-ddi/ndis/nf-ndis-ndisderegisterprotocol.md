# NdisDeregisterProtocol function

## Description

**Note** NDIS 5. *x* has been deprecated and is superseded by NDIS 6. *x*. For new NDIS driver development, see [Network Drivers Starting with Windows Vista](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/). For information about porting NDIS 5. *x* drivers to NDIS 6. *x*, see [Porting NDIS 5.x Drivers to NDIS 6.0](https://msdn.microsoft.com/library/Ff570059).

**NdisDeregisterProtocol** releases the resources allocated when the driver called **NdisRegisterProtocol**.

## Parameters

### `Status` [out]

Pointer to a caller-supplied variable that is set to NDIS\_STATUS\_SUCCESS on return from this function.

### `NdisProtocolHandle` [in]

Specifies the handle returned by [**NdisRegisterProtocol**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisregisterprotocol) when the driver initialized.

## Remarks

Registered protocol drivers call **NdisDeregisterProtocol** in any of the following circumstances:

- The driver already called **NdisRegisterProtocol** successfully but it cannot bind to any underlying NDIS driver in the machine.

- The driver is being unloaded. That is, the Unload routine set up in its driver object during initialization has been called or the [**ProtocolUnbindAdapter**](https://msdn.microsoft.com/library/ff563260/(v=vs.85/)) function has been called to release the driver's last remaining binding.

 For more information about the Unload routine and other standard kernel-mode driver routines, see [Kernel-Mode Driver Components](https://msdn.microsoft.com/library/Ff553213).

- The system is being shut down. Because the driver, which is a highest-level protocol, called [**IoRegisterShutdownNotification**](https://msdn.microsoft.com/library/Ff549541) when it initialized, its Shutdown routine has been called.

 See [**IoRegisterShutdownNotification**](https://msdn.microsoft.com/library/Ff549541) for more information.

If a protocol has any open bindings, its call to **NdisDeregisterProtocol** causes NDIS to call the protocol's *ProtocolUnbindAdapter* function once for each open binding. *ProtocolUnbindAdapter* calls **NdisCloseAdapter** to close the binding.

When outstanding opens, if any, have been closed, **NdisDeregisterProtocol** releases all filters its caller has set up and frees the memory NDIS allocated to track bindings and filters for the protocol driver.

- Target platform: [Universal](https://go.microsoft.com/fwlink/p/?linkid=531356)
- Version: Not supported for NDIS 6.0 drivers in Windows Vista. Use [**NdisDeregisterProtocolDriver**](https://msdn.microsoft.com/library/Ff561743)instead. Supported for NDIS 5.1 drivers in Windows Vista and Windows XP.

## See also

- [**NdisCloseAdapter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscloseadapter)
- [**NdisIMDeInitializeDeviceInstance**](https://msdn.microsoft.com/library/Ff562721)
- [**NdisOpenAdapter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapter)
- [**NdisRegisterProtocol**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisregisterprotocol)
- [**ProtocolCloseAdapterComplete**](https://msdn.microsoft.com/library/ff562502/(v=vs.85/))
- [**ProtocolStatus**](https://msdn.microsoft.com/library/ff563257/(v=vs.85/))
- [**ProtocolUnbindAdapter**](https://msdn.microsoft.com/library/ff563260/(v=vs.85/))