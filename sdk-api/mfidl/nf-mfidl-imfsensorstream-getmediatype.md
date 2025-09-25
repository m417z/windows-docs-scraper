# IMFSensorStream::GetMediaType

## Description

Retrieves an [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) representing a supported media type for the sensor stream.

## Parameters

### `dwIndex` [in]

The 0-based index of the [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) to retrieve. This value must be between 0 and the value returned by [GetMediaTypeCount](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfsensorstream-getmediatypecount) - 1.

### `ppMediaType` [out]

The retrieved media type.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *ppMediaType* parameter is null. |
| **MF_E_INVALIDINDEX** | The *dwIndex* is not in the allowed range. |

## See also

[IMFSensorStream](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensorstream)