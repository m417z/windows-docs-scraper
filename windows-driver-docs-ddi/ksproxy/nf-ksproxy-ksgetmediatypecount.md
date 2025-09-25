# KsGetMediaTypeCount function

## Description

The **KsGetMediaTypeCount** function returns the number of available media types on a pin factory identifier.

## Parameters

### `FilterHandle` [in]

Handle to the filter that contains the pin factory to query.

### `PinFactoryId` [in]

Identifier of the pin factory against which the number of media types is being returned.

### `MediaTypeCount` [out]

Pointer to a variable to receive the number of media types.

## Return value

Returns NOERROR if successful; otherwise, returns an error code.

## Remarks

The number of available media types that **KsGetMediaTypeCount** returns is equal to the number of available data ranges.

## See also

[IKsPinFactory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nn-ksproxy-ikspinfactory)

[KSDATARANGE](https://learn.microsoft.com/previous-versions/ff561658(v=vs.85))