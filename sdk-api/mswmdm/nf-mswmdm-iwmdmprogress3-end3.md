# IWMDMProgress3::End3

## Description

The **End3** method is called by Windows Media Device Manager to indicate that an operation has finished. This method extends [IWMDMProgress2::End2](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmprogress2-end2) by providing additional input parameters for the identification (ID) of the event and for a pointer to the context of the commands.

## Parameters

### `EventId` [in]

A **GUID** specifying the event that is ending. Possible values are shown in the following table.

| Event | Description |
| --- | --- |
| SCP_EVENTID_ACQSECURECLOCK | Windows Media Device Manager is acquiring a secure clock from server. |
| SCP_EVENTID_NEEDTOINDIV | The device is being individualized. This is not currently used. |
| SCP_EVENTID_DRMINFO | This event ID is used to notify the application with the version DRM header found in the content for each file.<br><br>The OPAQUECOMMAND structure returned has the **guidCommand** member set to SCP_PARAMID_DRMVERSION.<br><br>In addition, the data specifies one of the following flags:<br><br>WMDM_SCP_DRMINFO_NOT_DRMPROTECTED<br><br>WMDM_SCP_DRMINFO_V1HEADER<br><br>WMDM_SCP_DRMINFO_V2HEADER |
| EVENT_WMDM_CONTENT_TRANSFER | Content is being transferred to or from the device. |

### `hrCompletionCode` [in]

**HRESULT** specifying the completion code of the operation that was in progress. The *hrCompletionCode* parameter is the return code of the operation that ended. This parameter can be any **HRESULT**, including standard COM error codes, Win32 error codes converted to **HRESULT**, or Windows Media Device Manager error codes.

### `pContext` [in, out]

Pointer to an [OPAQUECOMMAND](https://learn.microsoft.com/windows/desktop/WMDM/opaquecommand) structure containing a command sent directly to the device without being handled by Windows Media Device Manager. This parameter is optional and can be **NULL**. The context structure is a way for the component to send any relevant data with the event to the application. The component sending this structure should define how the application can interpret this data structure.

## Return value

Windows Media Device Manager ignores any return code returned by the **End3** method because the current operation is finished or cancelled before this method is called.

## Remarks

The interface that owns the method that is implementing an operation calls **End3** when the operation defined by the method is completed.

#### Examples

The following C++ code shows an example implementation of **End3**.

```cpp

HRESULT End3(GUID  EventId, HRESULT  hrCompletionCode, OPAQUECOMMAND*  pContext)
{
    // TODO: Display the message "IWMDMProgress3::End3 called."
    return S_OK;
}

```

## See also

[Enabling Notifications](https://learn.microsoft.com/windows/desktop/WMDM/enabling-notifications)

[IWMDMProgress3 Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmprogress3)

[IWMDMProgress::End](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmprogress-end)