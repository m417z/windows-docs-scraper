## Description

*This function is intended for internal use only.*

The **KsGetBusEnumIdentifier** function retrieves the software bus enumerator identifier for the bus device associated with the given IRP.

## Parameters

### `Irp` [in, out]

Pointer to the IRP that specifies the address and size of the user output buffer to receive the requested bus enumerator identifier.

## Return value

Returns STATUS_SUCCESS if the bus enumerator identifier was retrieved successfully. Otherwise, it returns one of the following values:

| Return code | Description |
|---|---|
| **STATUS_INVALID_PARAMETER** | The specified device is not valid |
| **STATUS_BUFFER_TOO_SMALL** | The specified buffer was not large enough |
| **STATUS_BUFFER_OVERFLOW** | No buffer was specified (the required buffer size is returned in the Irp). |