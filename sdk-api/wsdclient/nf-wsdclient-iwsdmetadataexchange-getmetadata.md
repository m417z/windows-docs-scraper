# IWSDMetadataExchange::GetMetadata

## Description

Retrieves metadata for an object.

## Parameters

### `MetadataOut` [out]

Pointer to a linked list of structures containing the requested metadata.

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_POINTER** | *MetadataOut* is **NULL**. |

## See also

[IWSDMetadataExchange](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsdmetadataexchange)