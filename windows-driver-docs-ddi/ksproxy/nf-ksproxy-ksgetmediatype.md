# KsGetMediaType function

## Description

The **KsGetMediaType** function retrieves information about a media type on a pin factory identifier.

## Parameters

### `Position` [in]

Offset into the data range item that **KsGetMediaType** fills. Note that the data type of *Position* is **int** to conform to underlying calls.

### `AmMediaType` [out]

Pointer to a variable that receives information in a AM_MEDIA_TYPE structure.

### `FilterHandle` [in]

Handle to the filter that contains the pin factory to query.

### `PinFactoryId` [in]

Identifier of the pin factory against which the information for a media type is being returned.

## Return value

Returns NOERROR if successful; otherwise, returns an error code.

## Remarks

The **KsGetMediaType** function queries the list of data ranges and performs a data intersection on the specified data range, thus producing a data format. It then converts that data format to a media type.

For more information about AM_MEDIA_TYPE, see the Microsoft Windows SDK documentation.

## See also

[IKsPinFactory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nn-ksproxy-ikspinfactory)