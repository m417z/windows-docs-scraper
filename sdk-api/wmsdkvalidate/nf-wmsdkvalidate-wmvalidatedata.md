# WMValidateData function

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WMValidateData** function verifies that data from the beginning of a file is consistent with the header section of a file type that is supported by the Windows Media Format SDK.

If you are writing an application that can handle many different file types, you can use this function to try to quickly determine whether the file can be read using the Windows Media Format SDK.

## Parameters

### `pbData` [in]

Pointer to a **BYTE** array containing the data buffer to validate. This data should be part of a file, starting at the beginning of the file, and continuing for the number of bytes specified in *pdwDataSize*.

You can set this parameter to **NULL** to retrieve the minimum number of bytes to pass.

### `pdwDataSize` [in, out]

Pointer to a **DWORD** containing the data size. If *pbData* is set to **NULL**, this value will be set to the minimum buffer size on return. The minimum buffer size is 512 bytes.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. |
| **NS_E_INVALID_DATA** | The file cannot be handled by the objects of the Windows Media Format SDK. |
| **E_INVALIDARG** | *pdwDataSize* is **NULL**. |
| **ASF_E_BUFFERTOOSMALL** | The *pdwDataSize* parameter points to a value that is smaller than the minimum data buffer required to validate the data. |

## Remarks

This function is typically used after a call to [WMCheckURLExtension](https://learn.microsoft.com/windows/desktop/api/wmsdkvalidate/nf-wmsdkvalidate-wmcheckurlextension). This is for efficiency, because **WMValidateData** requires that you read some of the data from the file, whereas **WMCheckURLExtension** only evaluates the file name extension.

It is possible for this function to identify a file as playable when it is not playable. However, if the function identifies a file as not playable, the file is certainly not playable.

## See also

[Functions](https://learn.microsoft.com/windows/desktop/wmformat/functions)