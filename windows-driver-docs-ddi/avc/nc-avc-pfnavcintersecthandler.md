# PFNAVCINTERSECTHANDLER callback

## Description

The AV/C intersect handler determines if the data ranges are compatible. This is a user-defined function based on the following prototype:

## Parameters

### `Context` [in]

An optional value expected by the intersect handler. This value is either provided by the subunit driver (if the subunit driver provides the intersect handler), or by the lower driver providing the intersect handler.

### `PinId` [in]

Specifies the offset (or ID) of the pin for which the intersection is being done.

### `DataRange` [in]

### `MatchingDataRange` [in]

### `DataBufferSize` [in]

The size of the buffer passed by the **Data** member. If this is nonzero, then the intersect handler should attempt to return the data format resulting from a matching pair of data ranges. If this is zero, then the intersect handler should provide the required buffer size in **ReportedDataSize**, and return STATUS_BUFFER_OVERFLOW.

### `Data` [out, optional]

An optional buffer to receive the data format resulting from a matching pair of data ranges. This member is ignored if **DataBufferSize** is zero.

### `DataSize` [out]

## Return value

The intersect handler should return STATUS_SUCCESS if the data ranges are compatible, and there was enough buffer space to return the resulting format.

| Return code | Description |
|--|--|
| **STATUS_NO_MATCH** | The data ranges are not compatible. |
| **STATUS_INTERNAL_ERROR** | There was an unexpected format size mismatch. |
| **STATUS_BUFFER_OVERFLOW** | The intersect handler returns the required buffer size through the **ReportedDataSize** member. |
| **STATUS_BUFFER_TOO_SMALL** | The intersect handler was not provided with a buffer large enough to hold the resulting format. The intersect handler must be called again with the **DataBufferSize** set to zero to determine the required buffer size. |
| **STATUS_INSUFFICIENT_RESOURCES** | An internal buffer allocation failed. |

## Syntax

```cpp
typedef NTSTATUS ( *PFNAVCINTERSECTHANDLER)(
  _In_      PVOID        Context,
  _In_      ULONG        PinId,
  _In_      PKSDATARANGE CallerDataRange,
  _In_      PKSDATARANGE DescriptorDataRange,
  _In_      ULONG        DataBufferSize,
  _Out_opt_ PVOID        Data,
  _Out_     PULONG       ReportedDataSize
);
```

## Remarks

The AV/C intersect handler is user-defined, based on the function prototype above.

The handler is used in conjunction with the **AVC_FUNCTION_GET_PIN_DESCRIPTOR** function code. The purpose of the handler is to match identical pin data formats and return them to the caller.

## See also

- [AVC_FUNCTION_GET_PIN_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/stream/avc-function-get-pin-descriptor)
- [AVC_PIN_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/ns-avc-_avc_pin_descriptor)
- [AVStrMiniIntersectHandlerEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnksintersecthandlerex)
- [DataRange Intersections in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/data-range-intersections-in-avstream)