# IWMDMDeviceSession::BeginSession

## Description

The **BeginSession** method begins a device session.

## Parameters

### `type` [in]

A [WMDM_SESSION_TYPE](https://learn.microsoft.com/windows/desktop/WMDM/wmdm-session-type) describing the type of session to begin. This is a bitwise **OR** of any values except WMDM_SESSION_NONE. The same type (or combination of types) must be specified during [EndSession](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmdevicesession-endsession).

### `pCtx` [in]

Optional pointer to a caller-allocated session context buffer for private communication between the application and the service provider. Applications having knowledge of the underlying service provider can use this buffer to pass context-specific data to it. Windows Media Device Manager does not do anything with this context. The caller is responsible for freeing this buffer.

### `dwSizeCtx` [in]

Size of the context buffer, in bytes. If the size is 0, *pCtx* is ignored. If the size is non-zero, *pCtx* must be a valid pointer.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

Bundling several operations into a session does not cause all actions to be postponed and performed in a group; all actions (such as a call to **Insert**) will still be performed synchronously as called. Rather, using a session allows Windows Media Device Manager components (such as the secure content provider and service provider) to perform some of the operations only once per session, which provides performance improvements. For example, during file transfer to a device, the secure content provider can acquire the device certificate once at the beginning of the session instead of once for every file transfer.

Applications can call **BeginSession** on a Windows Media Device Manager device object before doing a set of operations and **EndSession** when they are done.

The application typically calls **BeginSession** during multiple file transfers or deletions. In response to that, Windows Media Device Manager calls **BeginSession** or **EndSession** on the secure content provider and the service provider. In response, the secure content provider and the service provider can perform once-per-session operations. If opening the session fails on any of these components, Windows Media Device Manager returns a failure returned by the component.

Sessions are implemented on a per-device basis. Sessions on different devices do not interfere with each other.

The following restrictions apply to sessions:

1. Only one session can be active at a time for a particular device. Attempting to open more than one session on a device will result in an error.
2. Session types can be combined. The same set of flags must be specified during **BeginSession** and **EndSession**. Therefore, it is not possible to end only part of the session.

   For example, if **BeginSession** is called with

   WMDM_SESSION_TRANSFER_TO_DEVICE | WMDM_SESSION_DELETE

   Then **EndSession** should also be called with

   WMDM_SESSION_TRANSFER_TO_DEVICE | WMDM_SESSION_DELETE

   Otherwise, Windows Media Device Manager will return E_INVALIDARG.
3. Windows Media Device Manager sessions are simply a bracketing mechanism for optimizations and do not have any implications regarding locking or ownership of the device. Service provider or the lower level device driver will still need to synchronize device access that may result from different Windows Media Device Manager applications.

#### Examples

The following C++ code demonstrates using a session to bundle an **Insert3** call on a device. The code loops through a number of files stored in a vector and sends them to the device.

```cpp

// Get the session interface.
CComQIPtr<IWMDMDeviceSession> pSession(pDevice);
if (pDevice == NULL)
{
    // TODO: Display a message that the application couldn't get an
    // IWMDMDeviceSession interface.
    return E_NOINTERFACE;
}

// Start the session. We don't use a custom buffer.
hr = pSession->BeginSession(WMDM_SESSION_TRANSFER_TO_DEVICE, NULL, NULL);
if (hr != S_OK)
{
    // TODO: Display a message indicating that the session failed to start.
    return hr;
}
else
{
    // TODO: Display a message that the session started.
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
        NULL, // Don't specify IWMDMOperation.
        NULL, // Don't specify IWMDMProgress.
        NULL, // Don't specify metadata.
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

[IWMDMDeviceSession::EndSession](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmdevicesession-endsession)

[WMDM_SESSION_TYPE](https://learn.microsoft.com/windows/desktop/WMDM/wmdm-session-type)