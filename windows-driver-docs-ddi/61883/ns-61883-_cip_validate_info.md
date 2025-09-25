# _CIP_VALIDATE_INFO structure

## Description

The CIP_VALIDATE_INFO structure contains information about the frame.

## Members

### `hConnect`

A handle to the connection.

### `Context`

Points to the context provided by the caller at **ValidateContext** in the input CIP_FRAME structure.

### `TimeStamp`

The timestamp of the current source packet.

### `Packet`

The packet offset for the current source packet.

## Remarks

The IEC-61883 protocol driver allocates and initializes this structure from the input CIP_FRAME structure.

## See also

[CIP_FRAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_cip_frame)