# IWMDMProgress3::Begin3

## Description

The **Begin3** method is called by Windows Media Device Manager to indicate that an operation is about to begin. An estimate of the duration of the operation is provided when possible. This method extends [IWMDMProgress::Begin](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmprogress-begin) by providing additional input parameters for the identification (ID) of the event and for a pointer to the optional context of the commands. The operation is identified by an event ID. The method allows the caller to pass an opaque data structure to the application.

## Parameters

### `EventId` [in]

A **GUID** identifying the operation that will begin. Possible values are shown in the following table.

| Event | Description |
| --- | --- |
| SCP_EVENTID_ACQSECURECLOCK | Windows Media Device Manager is acquiring a secure clock from server. |
| SCP_EVENTID_NEEDTOINDIV | The device is being individualized. This is not currently used. |
| SCP_EVENTID_DRMINFO | This event ID is used to notify the application with the version DRM header found in the content for each file.<br><br>The OPAQUECOMMAND structure returned has the **guidCommand** member set to SCP_PARAMID_DRMVERSION.<br><br>In addition, the OPAQUECOMMAND specifies one of the following flags:<br><br>WMDM_SCP_DRMINFO_NOT_DRMPROTECTED<br><br>WMDM_SCP_DRMINFO_V1HEADER<br><br>WMDM_SCP_DRMINFO_V2HEADER |
| EVENT_WMDM_CONTENT_TRANSFER | Content is being transferred to or from the device. |

### `dwEstimatedTicks` [in]

**DWORD** specifying the estimated number of ticks that are needed for the operation to complete. The number of ticks passed in *dwEstimatedTicks* is an estimate of how many ticks are needed for the operation to complete. During the course of the operation, the **Progress3** method is called to indicate how many ticks have transpired. Applications can use the estimate to configure display mechanisms that show progress.

### `pContext` [in, out]

Pointer to an [OPAQUECOMMAND](https://learn.microsoft.com/windows/desktop/WMDM/opaquecommand) structure containing a command sent to the device without being handled by Windows Media Device Manager. This parameter is optional and can be **NULL**.

## Return value

The application should return one of the following **HRESULT** values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation should continue. |
| **WMDM_E_USER_CANCELLED** | Windows Media Device Manager should cancel the current operation without waiting for it to finish. If the application is using block mode, then Windows Media Device Manager will return this error to the application. |

## Remarks

The application returns S_OK to indicate that an operation should be continued and WMDM_E_USER_CANCELLED to indicate that the operation should be cancelled. If the application is using block mode and returns WMDM_E_USER_CANCELLED, then Windows Media Device Manager will return this same error to the application.

#### Examples

The following C++ code shows an example implementation of **Begin3**.

```cpp

HRESULT Begin3(GUID  EventId, DWORD  dwEstimatedTicks, OPAQUECOMMAND*  pContext)
{
    WCHAR strGuid[64];
    StringFromGUID2(reinterpret_cast<GUID&>(EventId),(LPOLESTR)strGuid, 64);
    // TODO: Display the message "IWMDMProgress3::Begin3 called."
    // followed by the strGuid value.
    return S_OK;
}

```

## See also

[Enabling Notifications](https://learn.microsoft.com/windows/desktop/WMDM/enabling-notifications)

[IWMDMProgress3 Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmprogress3)

[IWMDMProgress::Begin](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmprogress-begin)