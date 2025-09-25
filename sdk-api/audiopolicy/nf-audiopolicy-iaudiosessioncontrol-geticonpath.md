# IAudioSessionControl::GetIconPath

## Description

The **GetIconPath** method retrieves the path for the display icon for the audio session.

## Parameters

### `pRetVal` [out]

Pointer to a pointer variable into which the method writes the address of a null-terminated, wide-character string that specifies the fully qualified path of an .ico, .dll, or .exe file that contains the icon. The method allocates the storage for the string. The caller is responsible for freeing the storage, when it is no longer needed, by calling the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function. For information about icon paths and **CoTaskMemFree**, see the Windows SDK documentation.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Parameter *pRetVal* is **NULL**. |
| **E_OUTOFMEMORY** | Out of memory. |
| **AUDCLNT_E_DEVICE_INVALIDATED** | The audio endpoint device has been unplugged, or the audio hardware or associated hardware resources have been reconfigured, disabled, removed, or otherwise made unavailable for use. |
| **AUDCLNT_E_SERVICE_NOT_RUNNING** | The Windows audio service is not running. |

## Remarks

If a client has not called [IAudioSessionControl::SetIconPath](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nf-audiopolicy-iaudiosessioncontrol-seticonpath) to set the display icon, the string will be empty. If no client-specified icon is available, the Sndvol program uses the icon from the client's application window to label the volume control for the audio session.

## See also

[IAudioSessionControl Interface](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessioncontrol)

[IAudioSessionControl::SetIconPath](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nf-audiopolicy-iaudiosessioncontrol-seticonpath)