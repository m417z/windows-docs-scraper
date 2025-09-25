# IWSDServiceProxy::EndGetMetadata

## Description

Completes the asynchronous metadata exchange request and retrieves the service metadata from the response.

## Parameters

### `pResult` [in]

An [IWSDAsyncResult](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsdasyncresult) interface that represents the result of the request. Release this object when done.

### `ppMetadata` [out]

Requested metadata. For details, see [WSD_METADATA_SECTION_LIST](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_metadata_section_list). Do not release this object.

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |

## Remarks

**EndGetMetadata** may block until the metadata retrieval operation has completed.

## See also

[IWSDServiceProxy](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsdserviceproxy)