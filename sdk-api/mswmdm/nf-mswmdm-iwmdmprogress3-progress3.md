# IWMDMProgress3::Progress3

## Description

The **Progress3** method is called by Windows Media Device Manager to indicate the status of an action in progress. This method extends [IWMDMProgress::Progress](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmprogress-progress) by providing additional input parameters for the identification (ID) of the event and for a pointer to the context of the commands.

## Parameters

### `EventId` [in]

**GUID** specifying the event ID for which progress notifications are being sent. Possible values are shown in the following table.

| Event | Description |
| --- | --- |
| SCP_EVENTID_ACQSECURECLOCK | Windows Media Device Manager is acquiring a secure clock from server. |
| SCP_EVENTID_NEEDTOINDIV | The device is being individualized. This is not currently used. |
| SCP_EVENTID_DRMINFO | This event ID is used to notify the application with the version DRM header found in the content for each file.<br><br>The OPAQUECOMMAND structure returned has the *guidCommand* parameter set to SCP_PARAMID_DRMVERSION.<br><br>In addition, the data specifies one of the following flags:<br><br>WMDM_SCP_DRMINFO_NOT_DRMPROTECTED<br><br>WMDM_SCP_DRMINFO_V1HEADER<br><br>WMDM_SCP_DRMINFO_V2HEADER |
| EVENT_WMDM_CONTENT_TRANSFER | Content is being transferred to or from the device. |

### `dwTranspiredTicks` [in]

**DWORD** specifying the number of ticks that have transpired so far.

### `pContext` [in, out]

Pointer to an [OPAQUECOMMAND](https://learn.microsoft.com/windows/desktop/WMDM/opaquecommand) structure containing a command sent directly to the device without being handled by Windows Media Device Manager. This parameter is optional and can be **NULL**. If the event is SCP_EVENTID_DRMINFO, the data in this parameter will have the SCP_PARAMID_DRMVERSION GUID.

## Return value

The application should return one of the following **HRESULT** values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation should continue. |
| **WMDM_E_USER_CANCELLED** | Windows Media Device Manager should cancel the current operation without waiting for it to finish. If the application is using block mode, then Windows Media Device Manager will return this error to the application. |

## Remarks

The interface that owns the method that is implementing an operation calls the **Progress3** method as the operation defined by the method is carried out. The intention is that **Progress3** will be called once per estimated tick. However, the *dwTranspiredTicks* parameter must be checked on each call because the operation being performed may not guarantee one call for each estimated tick.

The application returns S_OK to the calling method to indicate that the operation should continue. The application returns WMDM_E_USER_CANCELLED to indicate that the operation should be canceled. If the application is using block mode and returns WMDM_E_USER_CANCELLED, then Windows Media Device Manager will return this same error to the application.

#### Examples

The following C++ code shows an example implementation of **Progress3**.

```cpp

HRESULT Progress3(GUID  EventId, DWORD  dwTranspiredTicks, OPAQUECOMMAND*  pContext)
{
    WCHAR strGuid[64];
    ZeroMemory(strGuid, 64);
    StringFromGUID2(reinterpret_cast<GUID&>(EventId),(LPOLESTR)strGuid, 64);
    // TODO: Display the message: "Progress3 called. GUID value: "
    // followed by the strGUID value.
    // TODO: Display the message: "Progress3 dwTranspiredTicks: "
    // followed by the dwTranspiredTicks value.

    return S_OK;
}

```

## See also

[Enabling Notifications](https://learn.microsoft.com/windows/desktop/WMDM/enabling-notifications)

[IWMDMProgress3 Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmprogress3)

[IWMDMProgress::Progress](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmprogress-progress)