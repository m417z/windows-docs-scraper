# IWMSyncReader::SetOutputProps

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetOutputProps** method specifies the media properties of an uncompressed output stream.

## Parameters

### `dwOutputNum` [in]

**DWORD** containing the output number.

### `pOutput` [in]

Pointer to an [IWMOutputMediaProps](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmoutputmediaprops) interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The *dwOutputNum* parameter is greater than or equal to the number of outputs. Output numbers begin with zero. |
| **E_UNEXPECTED** | The method failed for an unspecified reason. |

## Remarks

Manipulating an object retrieved by a call to **GetOutputProps** has no effect on the output media stream unless the application also calls **SetOutputProps**.

DirectX VA formats can be returned from [GetOutputFormat](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmsyncreader-getoutputformat), but if they are passed in to **SetOutputProps**, that method will fail because DirectX VA formats cannot be specified in this way. Therefore, your code should either examine the format before passing it to **SetOutputProps**, or else handle the case of that method failing by attempting the next format enumerated from **GetOutputFormat**.. For example code showing how to identify a DirectX VA format, see [Enabling DirectX Video Acceleration](https://learn.microsoft.com/windows/desktop/wmformat/enabling-directx-video-acceleration).

You can call **SetOutputProps** at any time after a file has been loaded into the synchronous reader. You can continue making calls as needed during playback.

New output properties set with this method will take effect with the next call to **GetNextSample**.

## See also

[IWMOutputMediaProps Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmoutputmediaprops)

[IWMSyncReader Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmsyncreader)

[IWMSyncReader::GetOutputProps](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmsyncreader-getoutputprops)