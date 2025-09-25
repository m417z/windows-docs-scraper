# ScsiPortMoveMemory function

## Description

The **ScsiPortMoveMemory** routine copies data from one location to another.

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `WriteBuffer` [in]

Pointer to the destination buffer.

### `ReadBuffer` [in]

Pointer to the source buffer.

### `Length` [in]

Specifies how many bytes to transfer from *ReadBuffer* to *WriteBuffer*.

## Return value

None

## Remarks

**ScsiPortMoveMemory** can be called if a miniport driver needs to copy data from one system-allocated area to another. For example, a miniport driver might call **ScsiPortMoveMemory** to copy pertinent SRB values into the driver's SRB extension.

The (*ReadBuffer* + *Length*) can overlap the area pointed to by *WriteBuffer*.

Each of the given buffer areas must be at least **sizeof**(*Length*).