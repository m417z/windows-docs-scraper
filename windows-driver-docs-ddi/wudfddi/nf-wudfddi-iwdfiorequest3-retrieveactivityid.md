# IWDFIoRequest3::RetrieveActivityId

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

 The
**RetrieveActivityId** method retrieves the current activity identifier associated with an I/O request.

## Parameters

### `ActivityId` [out]

A pointer to a location to store the retrieved GUID.

## Return value

**RetrieveActivityId** returns S_OK if the call is successful. Otherwise, this method might return one of the following values.

| Return code | Description |
| --- | --- |
| **HRESULT_FROM_WIN32 (ERROR_NOT_FOUND)** | No activity ID is associated with the request. |

## Remarks

Requests reflected from kernel mode have an activity identifier available only if the Kernel Trace provider is enabled or if the UMDF driver called [IWDFIoRequest3::SetActivityId](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest3-setactivityid) after receiving the request. For more information about Event Tracing for Windows (ETW), see [Event Tracing](https://learn.microsoft.com/windows/desktop/ETW/event-tracing-portal).

Requests initiated by the UMDF driver have an activity identifier available only if the UMDF driver previously called [IWDFIoRequest3::SetActivityId](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest3-setactivityid).

The framework does not clear a request's activity identifier when the driver calls [IWdfIoRequest2::Reuse](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest2-reuse).

For more information about activity identifiers, see [Using Activity Identifiers](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-activity-identifiers).

The UMDF 2 equivalent of this method is [WdfRequestRetrieveActivityId](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveactivityid).

#### Examples

The following code example shows a driver can retrieve an activity identifier from one request and then use it to set the activity identifier for another request.

```
hrQI = pWdfRequest->QueryInterface(IID_PPV_ARGS(&pOriginalRequest3));
ASSERT(SUCCEEDED(hrQI));

hrQI = pNewRequest->QueryInterface(IID_PPV_ARGS(&pNewRequest3));
ASSERT(SUCCEEDED(hrQI));

//
// Obtain activity id from original request and set in the new one
//

pOriginalRequest3->RetrieveActivityId(&activityId);
pNewRequest3->SetActivityId(&activityId);

pOriginalRequest3->Release();
pNewRequest3->Release();

```

## See also

[IWDFIoRequest3](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiorequest3)

[IWDFIoRequest3::SetActivityId](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest3-setactivityid)