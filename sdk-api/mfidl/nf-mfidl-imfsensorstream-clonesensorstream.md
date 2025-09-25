# IMFSensorStream::CloneSensorStream

## Description

Clones the [IMFSensorStream](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensorstream).

## Parameters

### `ppStream` [out]

If the call is successful, *ppStream* receives the cloned [IMFSensorStream](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensorstream).

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *ppStream* parameter is null. |

## See also

[IMFSensorStream](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensorstream)