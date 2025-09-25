# MFCreatePMPMediaSession function

## Description

Creates an instance of the [Media Session](https://learn.microsoft.com/windows/desktop/medfound/media-session) inside a Protected Media Path (PMP) process.

## Parameters

### `dwCreationFlags`

A member of the [MFPMPSESSION_CREATION_FLAGS](https://learn.microsoft.com/windows/desktop/api/mfidl/ne-mfidl-mfpmpsession_creation_flags) enumeration that specifies how to create the session object.

### `pConfiguration`

A pointer to the [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) interface. This parameter can be **NULL**. See Remarks.

### `ppMediaSession`

Receives a pointer to the PMP Media Session's [IMFMediaSession](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediasession) interface. The caller must release the interface. Before releasing the last reference to the **IMFMediaSession** pointer, the application must call the [IMFMediaSession::Shutdown](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasession-shutdown) method.

### `ppEnablerActivate`

Receives a pointer to the [IMFActivate](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfactivate) interface or the value **NULL**. If non-**NULL**, the caller must release the interface. See Remarks.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. |

## Remarks

You can use the *pConfiguration* parameter to set any of the following attributes:

* [MF_SESSION_CONTENT_PROTECTION_MANAGER](https://learn.microsoft.com/windows/desktop/medfound/mf-session-content-protection-manager-attribute)
* [MF_SESSION_GLOBAL_TIME](https://learn.microsoft.com/windows/desktop/medfound/mf-session-global-time-attribute)
* [MF_SESSION_QUALITY_MANAGER](https://learn.microsoft.com/windows/desktop/medfound/mf-session-quality-manager-attribute)
* [MF_SESSION_REMOTE_SOURCE_MODE](https://learn.microsoft.com/windows/desktop/medfound/mf-session-remote-source-mode-attribute)
* [MF_SESSION_SERVER_CONTEXT](https://learn.microsoft.com/windows/desktop/medfound/mf-session-server-context-attribute)
* [MF_SESSION_TOPOLOADER](https://learn.microsoft.com/windows/desktop/medfound/mf-session-topoloader-attribute)

If this function cannot create the PMP Media Session because a trusted binary was revoked, the *ppEnablerActivate* parameter receives an [IMFActivate](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfactivate) interface pointer. The application can use this pointer to create a content enabler object, which can then be used to download an updated binary:

1. Call [IMFActivate::ActivateObject](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfactivate-activateobject) with the interface identifier IID_IMFContentEnabler to get an [IMFContentEnabler](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfcontentenabler) interface pointer.
2. Use that interface to download the updated binary.
3. Call **MFCreatePMPMediaSession** again.

If the function successfully creates the PMP Media Session, the *ppEnablerActivate* parameter receives the value **NULL**.

Do not make calls to the PMP Media Session from a thread that is processing a window message sent from another thread. To test whether the current thread falls into this category, call [InSendMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-insendmessage).

## See also

[MFCreateMediaSession](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-mfcreatemediasession)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[PMP Media Session](https://learn.microsoft.com/windows/desktop/medfound/pmp-media-session)

[Protected Media Path](https://learn.microsoft.com/windows/desktop/medfound/protected-media-path)