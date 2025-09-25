# IWSDiscoveredService::GetMetadataVersion

## Description

Retrieves the metadata version of this message.

## Parameters

### `pullMetadataVersion` [out]

Metadata version of this message.

## Return value

This method can return one of these values.

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_POINTER** | *pullMetadataVersion* is **NULL**. |

## Remarks

Versioning is used to determine if metadata exchange should be performed again due to a state change on the device.

## See also

[IWSDiscoveredService](https://learn.microsoft.com/windows/desktop/api/wsddisco/nn-wsddisco-iwsdiscoveredservice)