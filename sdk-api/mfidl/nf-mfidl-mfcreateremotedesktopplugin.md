# MFCreateRemoteDesktopPlugin function

## Description

Creates the remote desktop plug-in object. Use this object if the application is running in a Terminal Services client session.

## Parameters

### `ppPlugin`

Receives a pointer to the [IMFRemoteDesktopPlugin](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfremotedesktopplugin) interface of the plug-in object. The caller must release the interface.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. |
| **E_ACCESSDENIED** | Remote desktop connections are not allowed by the current session policy. |

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)