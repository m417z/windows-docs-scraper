# IWMDMDeviceSession::EndSession

## Description

The **EndSession** method ends a device session.

## Parameters

### `type` [in]

A [WMDM_SESSION_TYPE](https://learn.microsoft.com/windows/desktop/WMDM/wmdm-session-type) describing the type of session to end. This must be the same bitwise **OR** of the values specified in [BeginSession](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmdevicesession-beginsession).

### `pCtx` [in]

Optional pointer to a caller-allocated session context buffer for private communication between the application and the service provider. Applications having knowledge of the underlying service provider can use this buffer to pass context-specific data to it. Windows Media Device Manager does not do anything with this context. The caller is responsible for freeing this buffer.

### `dwSizeCtx` [in]

Size of the context buffer, in bytes. If the size is 0, *pCtx* is ignored. If the size is non-zero, *pCtx* must be a valid pointer

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

A session brackets a group of operations to a device, allowing Windows Media Device Manager components to optimize performance by performing common setup and shutdown functions only once, rather than with each individual transfer. For details see **BeginSession**.

In response to an **EndSession** call, Windows Media Device Manager calls **EndSession** on the secure content provider and the service provider. If either of them fails the call, Windows Media Device Manager returns an error. In that case, it is possible that **EndSession** succeeded for one of the components.

#### Examples

The following C++ code demonstrates using a session to bundle an **Insert3** call on a device. The code loops through a number of files stored in a vector and sends them to the device.

```cpp

// Get the session interface.
CComQIPtr<IWMDMDeviceSession> pSession(pDevice);
if (pDevice == NULL)
{
    // TODO: Display a message that the app wasn't able to retrieve the IWMDMDeviceSession interface.
    return E_NOINTERFACE;
}

// Start the session. We don't use a custom buffer.
hr = pSession->BeginSession(WMDM_SESSION_TRANSFER_TO_DEVICE, NULL, NULL);
if (hr != S_OK)
{
    / /TODO: Display a message indicating that the session failed to start.
    return hr;
}
else
{
    // TODO: Display a message indicating that the session started.
}

// Insert files. These calls happen synchronously.
UINT flags = WMDM_MODE_BLOCK | WMDM_STORAGECONTROL_INSERTINTO | WMDM_FILE_CREATE_OVERWRITE | WMDM_CONTENT_FILE;
CComPtr<IWMDMStorage> pNewStorage;
for(int i = 0; i < sourceFiles.size(); i++)
{
    hr = pStorageControl3->Insert3(
        flags,
        WMDM_FILE_ATTR_FOLDER,
        sourceFiles[i],
        NULL, // Use default name.
        NULL, // Don't specify IWMDMOperation
        NULL, // Don't specify IWMDMProgress
        NULL, // Don't specify metadata
        NULL, // Nothing to send to the SCP.
        &pNewStorage);

    if (pNewStorage != NULL)
        pNewStorage.Release();
    CHECK_HR(hr, "Sent file " << sourceFiles[i] << " to the device.", "Couldn't send file " << sourceFiles[i] << " to the device");
}

// Close the session.
hr = pSession->EndSession(WMDM_SESSION_TRANSFER_TO_DEVICE, NULL, NULL);
CHECK_HR(hr,"Closed the session.","Couldn't close the session.");

```

## See also

[IWMDMDeviceSession Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmdevicesession)

[IWMDMDeviceSession::BeginSession](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmdevicesession-beginsession)

[WMDM_SESSION_TYPE](https://learn.microsoft.com/windows/desktop/WMDM/wmdm-session-type)