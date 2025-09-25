# EvtGetObjectArraySize function

## Description

Gets the number of elements in the array of objects.

## Parameters

### `ObjectArray` [in]

A handle to an array of objects that the [EvtGetPublisherMetadataProperty](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtgetpublishermetadataproperty) function returns.

### `ObjectArraySize` [out]

The number of elements in the array.

## Return value

| Return code/value | Description |
| --- | --- |
| **TRUE** | The function succeeded. |
| **FALSE** | The function failed. To get the error code, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function. |

## See also

[EvtGetObjectArrayProperty](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtgetobjectarrayproperty)

[EvtGetPublisherMetadataProperty](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtgetpublishermetadataproperty)