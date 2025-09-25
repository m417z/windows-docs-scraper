# _CIP_NOTIFY_INFO structure

## Description

The CIP_NOTIFY_INFO structure contains information about the frame.

## Members

### `hConnect`

A handle to the connection.

### `Context`

Points to the context provided by the caller at **NotifyContext** in the input CIP_FRAME structure.

### `Frame`

Points to the completed frame.

## Remarks

The IEC-61883 protocol driver allocates and initializes this structure from the input CIP_FRAME structure.

## See also

[CIP_FRAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_cip_frame)