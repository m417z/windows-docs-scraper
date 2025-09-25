# IMFDeviceTransform::GetStreamCount

## Description

The **GetStreamCount** method gets the current number of input and output streams on this Media Foundation transform (MFT).

## Parameters

### `pcInputStreams` [out]

Receives the number of input streams.

### `pcOutputStreams` [out]

Receives the number of output streams.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to the values given in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | Transitioning the stream state succeeded. |
| **E_POINTER** | Invalid pointer passed. |

## Remarks

This function is used by DTM to get the number of streams supported by the Device MFT. The number of streams include unselected streams., fore example, streams with no media type or a NULL media type.

This method would not be called with NULL parameters.

## See also

[IMFDeviceTransform](https://learn.microsoft.com/windows/desktop/api/mftransform/nn-mftransform-imfdevicetransform)