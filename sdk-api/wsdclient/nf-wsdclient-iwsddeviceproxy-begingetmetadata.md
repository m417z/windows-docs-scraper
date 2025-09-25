# IWSDDeviceProxy::BeginGetMetadata

## Description

Sends an asynchronous request for metadata.

## Parameters

### `ppResult` [out]

Returns an [IWSDAsyncResult](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsdasyncresult) object that can be used to determine whether an operation has completed.

## Return value

This method can return one of these values.

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_POINTER** | *ppResult* is **NULL**. |
| **E_ABORT** | The method could not be completed. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |

## Remarks

BeginGetMetadata will force the device proxy to send a metadata request to the host. Once [EndGetMetadata](https://learn.microsoft.com/windows/desktop/api/wsdclient/nf-wsdclient-iwsddeviceproxy-endgetmetadata) has been called, the results of the latest metadata retrieval are accessible through the [GetAllMetadata](https://learn.microsoft.com/windows/desktop/api/wsdclient/nf-wsdclient-iwsddeviceproxy-getallmetadata), [GetHostMetadata](https://learn.microsoft.com/windows/desktop/api/wsdclient/nf-wsdclient-iwsddeviceproxy-gethostmetadata), [GetThisDeviceMetadata](https://learn.microsoft.com/windows/desktop/api/wsdclient/nf-wsdclient-iwsddeviceproxy-getthisdevicemetadata), and [GetThisModelMetadata](https://learn.microsoft.com/windows/desktop/api/wsdclient/nf-wsdclient-iwsddeviceproxy-getthismodelmetadata) methods.

## See also

[IWSDDeviceProxy](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsddeviceproxy)