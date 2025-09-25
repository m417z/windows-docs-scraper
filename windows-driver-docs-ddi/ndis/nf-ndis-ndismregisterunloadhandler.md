# NdisMRegisterUnloadHandler function

## Description

**Note** NDIS 5. *x* has been deprecated and is superseded by NDIS 6. *x*. For new NDIS driver development, see [Network Drivers Starting with Windows Vista](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/). For information about porting NDIS 5. *x* drivers to NDIS 6. *x*, see [Porting NDIS 5.x Drivers to NDIS 6.0](https://msdn.microsoft.com/library/Ff570059).

The **NdisMRegisterUnloadHandler** function registers an unload handler for a driver.

## Parameters

### `NdisWrapperHandle` [in]

Specifies the handle returned by [**NdisMInitializeWrapper**](https://msdn.microsoft.com/library/ff553547/(v=vs.85/)).

### `UnloadHandler` [in]

Specifies the entry point for the driver's unload routine. An unload routine is declared as follows:

```cpp
VOID
(*PDRIVER_UNLOAD) (
    IN struct _DRIVER_OBJECT *DriverObject
    );
```

## Remarks

A driver calls **NdisMRegisterUnloadHandler** from its **DriverEntry** function after **DriverEntry** has called [**NdisMRegisterMiniport**](https://msdn.microsoft.com/library/ff553602/(v=vs.85/)) or [**NdisIMRegisterLayeredMiniport**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisimregisterlayeredminiport). **NdisMRegisterUnloadHandler** registers an unload handler for the driver.

The functionality of the unload handler is driver-specific. For example, an intermediate driver should register an unload handler that calls [**NdisDeregisterProtocol**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisderegisterprotocol) to deregister the protocol portion of the intermediate driver. The unload handler should also perform any necessary cleanup operations, such as deallocating resources used by the protocol portion of the driver.

A miniport driver, such as a load-balancing miniport driver, that monitors more than one miniport driver instance should register an unload handler that cleans up state information and deallocates resources after the miniport driver instances that it monitors are halted. Note that an unload handler differs from a [**MiniportHalt**](https://msdn.microsoft.com/library/ff549451/(v=vs.85/)) function: the unload handler has a more global scope, whereas the scope of the MiniportHalt function is restricted to a particular miniport driver instance.

- Target platform: [Universal](https://go.microsoft.com/fwlink/p/?linkid=531356)
- Version: Not supported for NDIS 6.0 drivers in Windows Vista. Use [**NdisMRegisterMiniportDriver**](https://msdn.microsoft.com/library/Ff563654)instead. Supported for NDIS 5.1 drivers in Windows Vista and Windows XP.

## See also

- [**DriverEntry of NDIS Miniport Drivers**](https://msdn.microsoft.com/library/Ff548818)
- [**MiniportHalt**](https://msdn.microsoft.com/library/ff549451/(v=vs.85/))
- [**NdisDeregisterProtocol**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisderegisterprotocol)
- [**NdisIMRegisterLayeredMiniport**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisimregisterlayeredminiport)
- [**NdisMRegisterMiniport**](https://msdn.microsoft.com/library/ff553602/(v=vs.85/))