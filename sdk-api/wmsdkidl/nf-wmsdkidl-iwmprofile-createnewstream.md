# IWMProfile::CreateNewStream

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **CreateNewStream** method creates a stream configuration object. You can use a stream configuration object to define the characteristics of a media stream.

## Parameters

### `guidStreamType` [in]

GUID object specifying the major media type for the stream to be created (for example, WMMEDIATYPE_Video). The supported major types are listed in [Media Types](https://learn.microsoft.com/windows/desktop/wmformat/media-types).

### `ppConfig` [out]

Pointer to a pointer to the [IWMStreamConfig](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmstreamconfig) interface of the created stream configuration object.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The *ppConfig* parameter is **NULL**. |
| **E_OUTOFMEMORY** | There is not enough available memory. |

## Remarks

It is not possible to have a stream configuration object other than as an element of a profile. After the stream has been configured, this object must be added to the profile by using the [AddStream](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmprofile-addstream) method.

When **CreateNewStream** is called, a valid stream number is specified for the new stream. Stream numbers are in the range of 1 through 63.

## See also

[IWMProfile Interface](https://learn.microsoft.com/windows/desktop/wmformat/iwmprofile)

[IWMProfile2](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmprofile2)

[IWMProfile3](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmprofile3)

[Stream Configuration Object](https://learn.microsoft.com/windows/desktop/wmformat/stream-configuration-object)