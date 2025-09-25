# PBUS_RESET_ROUTINE callback function

## Description

This is a caller-supplied function to be called by the protocol driver when the 1394 bus is reset.

## Parameters

### `Context` [in]

Pointer to the context supplied by the caller at the **Context** member of the input BUS_RESET_NOTIFY structure.

### `BusResetInfo` [in]

The bus reset information.

## See also

[AV_61883_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_av_61883_request)