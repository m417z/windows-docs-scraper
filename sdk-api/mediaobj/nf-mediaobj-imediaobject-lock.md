# IMediaObject::Lock

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `Lock` method acquires or releases a lock on the DMO. Call this method to keep the DMO serialized when performing multiple operations.

## Parameters

### `bLock`

Value that specifies whether to acquire or release the lock. If the value is non-zero, a lock is acquired. If the value is zero, the lock is released.

## Return value

Returns an **HRESULT** value. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **E_FAIL** | Failure |
| **S_OK** | Success |

## Remarks

This method prevents other threads from calling methods on the DMO. If another thread calls a method on the DMO, the thread blocks until the lock is released.

If you are using the Active Template Library (ATL) to implement a DMO, the name of the Lock method conflicts with the **CComObjectRootEx::Lock** method. To work around this problem, define the preprocessor symbol FIX_LOCK_NAME before including the header file Dmo.h:

```cpp

#define FIX_LOCK_NAME
#include <dmo.h>

```

This directive causes the preprocessor to rename the **IMediaObject** method to *DMOLock*. In your DMO, implement the method as *DMOLock*. In your implementation, call the ATL **Lock** or **Unlock** method, depending on the value of *bLock*. Applications can still invoke the method using the name *Lock* because the vtable order does not change.