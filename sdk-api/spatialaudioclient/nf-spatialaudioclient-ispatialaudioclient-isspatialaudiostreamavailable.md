# ISpatialAudioClient::IsSpatialAudioStreamAvailable

## Description

When successful, gets a value indicating whether the currently active spatial rendering engine supports the specified spatial audio render stream.

## Parameters

### `streamUuid` [in]

The interface ID of the interface for which availability is queried.

### `auxiliaryInfo` [in, optional]

A structure containing additional information to be used when support is queried. For more information, see Remarks.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **SPTLAUDCLNT_E_STREAM_IS_NOT_AVAILABLE** | The specified stream interface can't be activated by the currently active rendering engine. |
| **SPTLAUDCLNT_E_METADATA_FORMAT_IS_NOT_SUPPORTED** | The metadata format supplied in the *auxiliaryInfo* parameter is not supported by the current rendering engine. For more information, see Remarks.. |

## Remarks

When querying to see if the [ISpatialAudioObjectRenderStreamForMetadata](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudioobjectrenderstreamformetadata) you can use the auxilaryInfo parameter to query if a particular metadata format is supported. The following code example demonstrates how to initialize the [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure to check for support for an example metadata format.

```cpp
PROPVARIANT auxiliaryInfo;
auxiliaryInfo.vt = VT_CLSID;
auxiliaryInfo.puuid = const_cast<CLSID*>(&CONTOSO_SPATIAL_METADATA_V1_0);
```

If the specified metadata format is unsupported, **IsSpatialAudioStreamAvailable** returns SPTLAUDCLNT_E_METADATA_FORMAT_IS_NOT_SUPPORTED.

## See also

[ISpatialAudioClient](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nn-spatialaudioclient-ispatialaudioclient)