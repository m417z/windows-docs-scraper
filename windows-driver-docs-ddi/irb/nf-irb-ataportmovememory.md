# AtaPortMoveMemory function

## Description

The **AtaPortMoveMemory** routine copies data from one location to another.

**Note** The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `WriteBuffer` [out]

A pointer to the destination buffer.

### `ReadBuffer` [in]

A pointer to the source buffer.

### `Length` [in]

Specifies the number of bytes to transfer from *ReadBuffer* to *WriteBuffer*.

## Remarks

The miniport driver calls the **AtaPortMoveMemory** routine to copy data from one system-allocated area to another.

The location pointed to by *ReadBuffer* and *Length* can overlap the range of addresses between *WriteBuffer* and *Length*.