# IWMDRMReader::Individualize

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

[**Individualize** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Microsoft PlayReady](https://www.microsoft.com/PlayReady/).
]

The **Individualize** method individualizes the client by updating their DRM system components.

## Parameters

### `dwFlags` [in]

**DWORD** containing the relevant flags.

| Flag | Description |
| --- | --- |
| 0x0 | Indicates that the client can be individualized again. |
| 0x1 | Indicates that the client will not be individualized again. |

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | A null or invalid argument has been passed in. |

## Remarks

This is an asynchronous call that returns immediately. To abandon the attempt, call **CancelIndividualization**.

**Important** Because this operation will cause the user's system to be modified, you should display a message that explains what this operation will do and let the user choose whether or not to individualize. For more information and suggested message text, see [DRM Individualization](https://learn.microsoft.com/windows/desktop/wmformat/drm-individualization).

Individualization is the process of making the DRM client unique by downloading and installing an individualized component from the Microsoft Individualization Service. The entire process is performed automatically after an application calls the **Individualize** method. The application is informed of the progress of the individualization process through repeated **WMT_INDIVIDUALIZE** events, each of which has an associated [WM_INDIVIDUALIZE_STATUS](https://learn.microsoft.com/windows/desktop/wmformat/wm-individualize-status) structure which is sent to the application's [IWMStatusCallback::OnStatus](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmstatuscallback-onstatus) callback method.

There are two times to initiate the individualization process: the first is when a piece of content requires it, and the second is when a player individualizes the client as part of the setup. In the latter case, there is no reason to individualize the client again.

## See also

[DRM Individualization](https://learn.microsoft.com/windows/desktop/wmformat/drm-individualization)

[IWMDRMReader Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmdrmreader)

[IWMDRMReader::CancelIndividualization](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmdrmreader-cancelindividualization)

[Individualizing DRM Applications](https://learn.microsoft.com/windows/desktop/wmformat/individualizing-drm-applications)

[WM_INDIVIDUALIZE_STATUS](https://learn.microsoft.com/windows/desktop/wmformat/wm-individualize-status)