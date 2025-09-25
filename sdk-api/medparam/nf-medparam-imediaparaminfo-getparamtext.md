# IMediaParamInfo::GetParamText

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetParamText` method retrieves a series of text strings that describe the parameter.

## Parameters

### `dwParamIndex` [in]

Zero-based index of the parameter.

### `ppwchText` [out]

Address of a variable that receives a pointer to a series of Unicode™ strings.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Index out of range. |
| **E_POINTER** | **NULL** pointer argument. |
| **S_OK** | Success. |

## Remarks

If the method succeeds, **ppwchText* points to a string with the following format:

`Name\0Unit\0Enum1\0Enum2\0...EnumN\0\0`

where

* *Name* is the name of the parameter.
* *Unit* is the name of the units; for example, milliseconds.
* *Enum1* through
* *EnumN* are descriptive names for the parameter's enumerated values. (Applies only to parameters of type MPT_ENUM.)

The application can display these values within its user interface. They are not guaranteed to follow a consistent naming scheme. If the user's computer is using an international code page, the method might return a localized string corresponding to that code page.

The object uses the **CoTaskMemAlloc** function to allocate memory for the string. After you call this method, call **CoTaskMemFree** to free the buffer.

## See also

[IMediaParamInfo Interface](https://learn.microsoft.com/windows/desktop/api/medparam/nn-medparam-imediaparaminfo)