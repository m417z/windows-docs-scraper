# IWSDDeviceProxy::EndGetMetadata

## Description

Ends an asynchronous request for metadata and returns the metadata related to a device.

## Parameters

### `pResult` [in]

The [IWSDAsyncResult](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsdasyncresult) object returned by [BeginGetMetadata](https://learn.microsoft.com/windows/desktop/api/wsdclient/nf-wsdclient-iwsddeviceproxy-begingetmetadata).

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_INVALIDARG** | *pResult* is **NULL**. |
| **E_ABORT** | The method could not be completed. |
| **E_FAIL** | The method failed. The metadata was not returned, was invalid, or a fault was generated. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |

## Remarks

EndGetMetadata must only be called after the [IWSDAsyncResult](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsdasyncresult) object returned by [BeginGetMetadata](https://learn.microsoft.com/windows/desktop/api/wsdclient/nf-wsdclient-iwsddeviceproxy-begingetmetadata) has indicated that the operation is complete. Once EndGetMetadata has been called, the results of the latest metadata retrieval are accessible through the [GetAllMetadata](https://learn.microsoft.com/windows/desktop/api/wsdclient/nf-wsdclient-iwsddeviceproxy-getallmetadata), [GetHostMetadata](https://learn.microsoft.com/windows/desktop/api/wsdclient/nf-wsdclient-iwsddeviceproxy-gethostmetadata), [GetThisDeviceMetadata](https://learn.microsoft.com/windows/desktop/api/wsdclient/nf-wsdclient-iwsddeviceproxy-getthisdevicemetadata), and [GetThisModelMetadata](https://learn.microsoft.com/windows/desktop/api/wsdclient/nf-wsdclient-iwsddeviceproxy-getthismodelmetadata) methods.

## See also

[IWSDDeviceProxy](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsddeviceproxy)