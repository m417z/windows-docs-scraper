# IMFSensorStream::GetMediaTypeCount

## Description

Gets the count of media types supported by the sensor stream.

## Parameters

### `pdwCount` [out]

If the call completes successfully, receives the count of media types supported by the stream.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *pdwCount* parameter is null. |

## See also

[IMFSensorStream](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensorstream)