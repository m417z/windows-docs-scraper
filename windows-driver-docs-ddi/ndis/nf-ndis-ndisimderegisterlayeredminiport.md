# NdisIMDeregisterLayeredMiniport function

## Description

**Note** NDIS 5. *x* has been deprecated and is superseded by NDIS 6. *x*. For new NDIS driver development, see [Network Drivers Starting with Windows Vista](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/). For information about porting NDIS 5. *x* drivers to NDIS 6. *x*, see [Porting NDIS 5.x Drivers to NDIS 6.0](https://msdn.microsoft.com/library/Ff570059).

**NdisIMDeregisterLayeredMiniport** releases a previously registered intermediate driver.

## Parameters

### `DriverHandle` [in]

Specifies the handle returned by [**NdisIMRegisterLayeredMiniport**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisimregisterlayeredminiport).

## Remarks

An intermediate driver that called **NdisIMRegisterLayeredMiniport** from its **DriverEntry** routine must call **NdisIMDeregisterLayeredMiniport** when it cleans up the resources it allocated before it is unloaded. If the intermediate driver encounters a fatal initialization error within its **DriverEntry** routine, such as an inability to obtain system resources, it must call **NdisIMDeregisterLayeredMiniport**.

The **NdisIMDeregisterLayeredMiniport** function is the reciprocal of **NdisIMRegisterLayeredMiniport**. An intermediate driver typically calls **NdisIMDeregisterLayeredMiniport** from its *ProtocolUnbindAdapter* function after calling [**NdisDeregisterProtocol**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisderegisterprotocol).

- Target platform: [Universal](https://go.microsoft.com/fwlink/p/?linkid=531356)
- Version: Not supported for NDIS 6.0 drivers in Windows Vista. Use [**NdisMDeregisterMiniportDriver**](https://msdn.microsoft.com/library/Ff563578)instead. Supported for NDIS 5.1 drivers in Windows Vista and Windows XP.

## See also

- [**NdisIMRegisterLayeredMiniport**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisimregisterlayeredminiport)