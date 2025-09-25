# IVPBaseConfig::GetConnectInfo

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetConnectInfo` method retrieves information about the connections supported by the VPE object.

## Parameters

### `pdwNumConnectInfo` [in, out]

Pointer to a variable that specifies the number of **DDVIDEOPORTCONNECT** structures in the *pddVPConnectInfo* array. On input, specifies the size of the array (in number of array elements). On output, contains the actual number of **DDVIDEOPORTCONNECT** structures that were copied into the array. If *pddVPConnectInfo* is **NULL**, the method returns the required array size.

### `pddVPConnectInfo` [in, out]

Pointer to an array of **DDVIDEOPORTCONNECT** structures, allocated by the caller. The device fills in the array with the connection information.

## Return value

Returns S_OK if successful, or an error code otherwise.

## Remarks

The client first calls this method with the value **NULL** for the *pddVPConnectInfo* parameter. The device returns the number of **DDVIDEOPORTCONNECT** structures in the *pdwNumConnectInfo* parameter. The client allocates an array of that size, and calls the method again, passing the address of the array in the *pddVPConnectInfo* parameter. The device copies the connection information into the buffer, and returns the actual number of copied structures in the *pdwNumConnectInfo* parameter.

The **DDVIDEOPORTCONNECT** structure is documented in the Windows DDK. The device can translate this method directly into an *DdVideoPortGetConnectInfo* call.

The client sets the connection information by calling the [IVPBaseConfig::SetConnectInfo](https://learn.microsoft.com/windows/desktop/api/vpconfig/nf-vpconfig-ivpbaseconfig-setconnectinfo) method with an index number, which references one of the connection structures returned by this method.

Include Dvp.h and Vptype.h before Vpconfig.h.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IVPBaseConfig Interface](https://learn.microsoft.com/windows/desktop/api/vpconfig/nn-vpconfig-ivpbaseconfig)