# WMCreateDRMTranscryptionManager function

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WMCreateDRMTranscryptionManager** function creates a manager for DRM transcryptor objects.

## Parameters

### `ppTranscryptionManager`

Address of a pointer to the [IWMDRMTranscryptionManager](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd798365(v=vs.85)) interface of the newly created DRM transcryptor object manager.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.