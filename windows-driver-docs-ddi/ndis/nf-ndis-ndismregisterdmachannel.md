# NdisMRegisterDmaChannel function

## Description

The
**NdisMRegisterDmaChannel** function claims a system DMA controller channel during initialization for DMA
operations on a subordinate NIC or on an ISA bus-master NIC.

## Parameters

### `MiniportDmaHandle` [out]

A pointer to a caller-supplied variable in which this function returns a handle the miniport
driver uses in subsequent calls to the
**NdisM*Xxx*** system DMA functions.

### `MiniportAdapterHandle` [in]

The miniport adapter handle input to the
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function.

### `DmaChannel` [in]

Ignored. Set the DMA channel, if any, at
*DmaDescription* .

### `Dma32BitAddresses` [in]

A boolean value that is **TRUE** if the NIC has 32 address lines. Otherwise, it is **FALSE**.

### `DmaDescription` [in]

A pointer to an NDIS_DMA_DESCRIPTION structure filled in by the caller. This structure is defined
as follows:

```
typedef struct _NDIS_DMA_DESCRIPTION {
    BOOLEAN DemandMode;
    BOOLEAN AutoInitialize;
    BOOLEAN DmaChannelSpecified;
    DMA_WIDTH DmaWidth;
    DMA_SPEED DmaSpeed;
    ULONG DmaPort;
    ULONG DmaChannel;
} NDIS_DMA_DESCRIPTION, *PNDIS_DMA_DESCRIPTION;
```

The driver should initialize this structure with zeros before filling in the following members:

#### DemandMode

A boolean value that is **TRUE** if the subordinate NIC uses the system DMA controller's demand
mode. Otherwise, it is **FALSE**.

#### AutoInitialize

A boolean value that is **TRUE** if the subordinate NIC uses the system DMA controller's
autoinitialize mode. Otherwise, it is **FALSE**.

#### DmaChannelSpecified

A boolean value that is **TRUE** if
**DmaChannel** is set to the bus-relative value of the system DMA controller channel used by the
NIC. Otherwise, it is **FALSE**.

#### DmaWidth

The transfer width for DMA operations, one of
**Width8Bits**,
**Width16Bits**, or
**Width32Bits**.

#### DmaSpeed

The DMA speed as one of
**Compatible**,
**TypeA**,
**TypeB**, or
**TypeC**.

#### DmaPort

This member refers to the MCA bus, which is no longer supported. This member must be
zero.

#### DmaChannel

The bus-relative number of the system DMA controller channel used by the NIC.

### `MaximumLength` [in]

The maximum number of bytes that the NIC can transfer in a single DMA operation. If the NIC has
unlimited transfer capacity, set this parameter to -1.

## Return value

**NdisMRegisterDmaChannel** can return one of the following status values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | NDIS claimed the specified DMA channel in the registry for the caller's NIC and set up necessary resources for subsequent DMA operations by the miniport driver. |
| **NDIS_STATUS_RESOURCE_CONFLICT** | An attempt to claim the DMA channel in the registry has failed, possibly because another driver has already claimed that channel for its device. **NdisMRegisterDmaChannel** logs an error if this occurs. |
| **NDIS_STATUS_RESOURCES** | NDIS could not allocate the system resources it needs to support DMA operations by this miniport driver. |
| **NDIS_STATUS_FAILURE** | Either the bus type or bus number is out of range or the driver declared the NIC to be a bus master on an I/O bus other than ISA. |

## Remarks

A driver of a subordinate-DMA NIC must call
**NdisMRegisterDmaChannel** from its
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function to
reserve system resources for subsequent DMA operations and to claim them in the registry.

The driver of an ISA bus-master NIC also must call
**NdisMRegisterDmaChannel** from
*MiniportInitializeEx* to claim a system DMA controller channel for the NIC in the registry.

*MiniportInitializeEx* must call the
[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes) function before calling
**NdisMRegisterDmaChannel**.

*MiniportInitializeEx* obtained the bus-relative values passed to
**NdisMRegisterDmaChannel** either from the registry or by calling the
[NdisMGetBusData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismgetbusdata) function.

If such a driver cannot allocate the system DMA resources that its device needs,
*MiniportInitializeEx* should release all resources it already allocated for the NIC and, then, fail
initialization for that NIC.

If the driver successfully registers the DMA channel, it must later call the
[NdisMDeregisterDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismderegisterdmachannel) function to deregister the DMA channel.

## See also

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NdisMDeregisterDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismderegisterdmachannel)

[NdisMGetBusData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismgetbusdata)

[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes)