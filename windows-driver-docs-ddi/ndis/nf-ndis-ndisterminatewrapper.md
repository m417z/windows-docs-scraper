# NdisTerminateWrapper function

## Description

**Note** NDIS 5. *x* has been deprecated and is superseded by NDIS 6. *x*. For new NDIS driver development, see [Network Drivers Starting with Windows Vista](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/). For information about porting NDIS 5. *x* drivers to NDIS 6. *x*, see [Porting NDIS 5.x Drivers to NDIS 6.0](https://msdn.microsoft.com/library/Ff570059).

**NdisTerminateWrapper** releases system resources allocated when the NIC driver called [**NdisMInitializeWrapper**](https://msdn.microsoft.com/library/ff553547/(v=vs.85/)).

## Parameters

### `NdisWrapperHandle` [in]

Specifies the handle returned by **NdisMInitializeWrapper**.

### `SystemSpecific` [in]

Pointer to an OS-specific type. For Windows 2000 and later drivers, this parameter should be **NULL**.

## Remarks

From its **DriverEntry** function, a miniport driver calls [**NdisMInitializeWrapper**](https://msdn.microsoft.com/library/ff553547/(v=vs.85/)) to notify NDIS that the driver is about to register itself as a miniport driver. After **NdisMInitializeWrapper** successfully returns, the miniport driver calls either [**NdisMRegisterMiniport**](https://msdn.microsoft.com/library/ff553602/(v=vs.85/).md) or [**NdisIMRegisterLayeredMiniport**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisimregisterlayeredminiport) to register its entry points with NDIS.

If a miniport driver's call to **NdisMRegisterMiniport** or **NdisIMRegisterLayeredMiniport** does not return NDIS\_STATUS\_SUCCESS, the miniport driver must call **NdisTerminateWrapper**. Calling **NdisTerminateWrapper** causesNDIS to clean up the resources that it allocated when the miniport driver called **NdisMInitializeWrapper**.

- Target platform: [Universal](https://go.microsoft.com/fwlink/p/?linkid=531356)
- Version: Not supported for NDIS 6.0 drivers in Windows Vista. Supported for NDIS 5.1 drivers in Windows Vista and Windows XP.

## See also

- [**DriverEntry of NDIS Miniport Drivers**](https://msdn.microsoft.com/library/Ff548818)
- [**MiniportHalt**](https://msdn.microsoft.com/library/ff549451/(v=vs.85/))
- [**MiniportInitialize**](https://msdn.microsoft.com/library/ff550472/(v=vs.85/))
- [**NdisMInitializeWrapper**](https://msdn.microsoft.com/library/ff553547/(v=vs.85/))