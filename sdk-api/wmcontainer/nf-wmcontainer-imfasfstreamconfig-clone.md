# IMFASFStreamConfig::Clone

## Description

Creates a copy of the Advanced Systems Format (ASF) stream configuration object.

## Parameters

### `ppIStreamConfig` [out]

Receives a pointer to the [IMFASFStreamConfig](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfstreamconfig) interface of the new object. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The cloned object is completely independent of the original.

## See also

[IMFASFStreamConfig](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfstreamconfig)