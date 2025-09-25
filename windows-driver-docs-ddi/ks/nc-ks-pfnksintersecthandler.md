## Description

A streaming minidriver's *KStrIntersectHandler* routine is called to compare a data range to determine if there is an intersection, and if so, the data format of the intersection.

## Parameters

### `Irp` [in]

Specifies the IRP that handles the property request.

### `Pin` [in]

Specifies the specific property being queried and the pin factory identifier that was validated.

### `DataRange` [in]

Specifies the current data range to compare. The data range has been validated as either matching a particular range on the pin or as a wildcard match.

### `Data` [out, optional]

Specifies the data format returned, or the size, in bytes, of the data format.

## Return value

Returns STATUS_SUCCESS if there is a data intersection that fits in the supplied buffer. Otherwise, one of the following values is returned.

| Return code | Description |
|---|---|
| **STATUS_BUFFER_OVERFLOW** | For successful size queries. |
| **STATUS_BUFFER_TOO_SMALL** | If the supplied buffer is too small. |
| **STATUS_NO_MATCH** | If there is no intersection. |

## See also

[KsPinDataIntersection](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspindataintersection)