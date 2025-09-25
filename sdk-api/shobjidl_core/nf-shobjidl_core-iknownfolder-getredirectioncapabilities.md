# IKnownFolder::GetRedirectionCapabilities

## Description

Gets a value that states whether the known folder can have its path set to a new value or what specific restrictions or prohibitions are placed on that redirection.

## Parameters

### `pCapabilities` [out]

Type: **[KF_REDIRECTION_CAPABILITIES](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_kf_redirection_capabilities)***

When this method returns, contains a pointer to a [KF_REDIRECTION_CAPABILITIES](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_kf_redirection_capabilities) value that indicates the redirection capabilities for this folder.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IKnownFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iknownfolder)

[Known Folders Sample](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd940364(v=vs.85))