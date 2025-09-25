# IMFAudioPolicy::SetIconPath

## Description

Sets the icon resource for the audio session. The Windows volume control displays this icon.

## Parameters

### `pszPath` [in]

A wide-character string that specifies the icon. See Remarks.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The icon path has the format "path,index" or "path,-id", where *path* is the fully qualified path to a DLL, executable file, or icon file; *index* is the zero-based index of the icon within the file; and *id* is a resource identifier. Note that resource identifiers are preceded by a minus sign (-) to distinguish them from indexes. The path can contain environment variables, such as "%windir%". For more information, see [IAudioSessionControl::SetIconPath](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nf-audiopolicy-iaudiosessioncontrol-seticonpath) in the Windows SDK.

#### Examples

The following example sets the icon using a resource identifier for an icon in the application's executable file.

```cpp
HRESULT SetIcon(IMFMediaSession *pSession, int nID)
{
    IMFAudioPolicy *pPolicy = NULL;

    const DWORD CCH_ICON_PATH = MAX_PATH + 16;
    WCHAR szFileName[MAX_PATH];
    WCHAR szIconPath[CCH_ICON_PATH];

    HRESULT hr = S_OK;

    DWORD result = GetModuleFileNameW(NULL, szFileName, MAX_PATH);

    // Note: GetModuleFileName can return a truncated string without a
    // NULL terminator. If so, the function succeeds but sets the last
    // error to ERROR_INSUFFICIENT_BUFFER.
    if ((result == 0) || (GetLastError() ==  ERROR_INSUFFICIENT_BUFFER))
    {
        hr = E_FAIL;
        goto done;
    }

    hr = StringCchPrintfW(szIconPath, CCH_ICON_PATH,
                 L"%s,-%d", szFileName, nID);

    if (FAILED(hr))
    {
        goto done;
    }

    hr = MFGetService(
        pSession,
        MR_AUDIO_POLICY_SERVICE,
        IID_PPV_ARGS(&pPolicy)
        );

    if (FAILED(hr))
    {
        goto done;
    }

    hr = pPolicy->SetIconPath(szIconPath);
    if (FAILED(hr))
    {
        goto done;
    }

done:
    SafeRelease(&pPolicy);
    return hr;
}

```

## See also

[IMFAudioPolicy](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfaudiopolicy)

[Streaming Audio Renderer](https://learn.microsoft.com/windows/desktop/medfound/streaming-audio-renderer)