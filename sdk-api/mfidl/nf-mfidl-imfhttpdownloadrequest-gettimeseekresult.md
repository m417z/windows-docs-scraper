# IMFHttpDownloadRequest::GetTimeSeekResult

## Description

Invoked by Microsoft Media Foundation to retrieve the values of the TimeSeekRange.DLNA.ORG HTTP header, if any, that the server specified in its response.

## Parameters

### `pqwStartTime` [out]

The starting time offset, specified in units of one-hundred nanoseconds.

### `pqwStopTime` [out]

The end time offset, specified in units of one-hundred nanoseconds

### `pqwDuration` [out]

The time duration of data contained in the response, specified in units of one-hundred nanoseconds. Set this parameter to 0 if the server did not specify a duration (i.e., specified “*” as the duration.)

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The TimeSeekRange.DLNA.ORG HTTP header was present in the response, and could be successfully parsed. |
| **S_FALSE** | The TimeSeekRange.DLNA.ORG HTTP header was not present in the response, or had a syntax error. |
| **E_POINTER** | The *pfNullSOurceOrigin* parameter is an invalid pointer. |

## Remarks

The values of all the parameters should be set to 0 if **GetTimeSeekResult** is invoked before [EndReceiveResponse](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfhttpdownloadrequest-endreceiveresponse) has been invoked. For information about the syntax for the TimeSeekRange.DLNA.ORG header, please refer to the [DLNA web site](http://www.dlna.org/guidelines/).

## See also

[IMFHttpDownloadRequest](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfhttpdownloadrequest)