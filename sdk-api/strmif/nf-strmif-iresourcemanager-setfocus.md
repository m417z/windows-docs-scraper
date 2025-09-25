# IResourceManager::SetFocus

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetFocus` method notifies the resource manager that a specified object has been given the focus of the user.

## Parameters

### `pFocusObject` [in]

Pointer to the object that has been given the user's focus.

## Return value

Returns an **HRESULT** value that depends on the implementation. **HRESULT** can be one of the following standard constants, or other values not listed.

| Return code | Description |
| --- | --- |
| **E_FAIL** | Failure. |
| **E_POINTER** | **NULL** pointer argument. |
| **E_INVALIDARG** | Invalid argument. |
| **E_NOTIMPL** | Method isn't supported. |
| **S_OK or NOERROR** | Success. |

## Remarks

In DirectShow, the object given the user's focus is typically a video renderer whose window has received the focus. The resource manager gives priority to requests for resources in the following order:

1. Requests made with the focus object specified in the *pFocusObject* parameter.
2. Requests whose focus object shares a common source filter.
3. Requests whose focus object shares a common filter graph.
4. Requests in the same process as the focus.

After a focus has been set, the resource manager must maintain a focus object until [ReleaseFocus](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iresourcemanager-releasefocus) is called. That is, after calling this method, you must use **ReleaseFocus** before the **IUnknown** interface of the focus object becomes invalid, unless you can guarantee that `SetFocus` is called by a different object in the meantime. No reference count is held on the focus object.

The resource manager will hold this pointer until replaced or canceled, and will use it to resolve resource contention. It will use **QueryInterface** for the [IBaseFilter](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ibasefilter) interface at least and, if found, will use methods on that interface. It calls methods on **IBaseFilter** to decide which audio renderer to use if there are two (it will choose the one with a source filter common to the focus object), and also to determine if the two objects are within the same filter graph.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IResourceManager Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iresourcemanager)