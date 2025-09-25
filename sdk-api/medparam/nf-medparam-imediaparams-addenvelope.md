# IMediaParams::AddEnvelope

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `AddEnvelope` method adds an envelope to a parameter.

## Parameters

### `dwParamIndex` [in]

Zero-based index of the parameter, or DWORD_ALLPARAMS to add the envelope to every parameter.

### `cSegments` [in]

Number of segments in the envelope.

### `pEnvelopeSegments` [in]

Pointer to an array of [MP_ENVELOPE_SEGMENT](https://learn.microsoft.com/previous-versions/windows/desktop/api/medparam/ns-medparam-mp_envelope_segment) structures that define the envelope segments. The size of the array is given in the *cPoints* parameter.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Index out of range. |
| **E_OUTOFMEMEORY** | Insufficient memory. |
| **E_POINTER** | **NULL** pointer argument. |
| **S_OK** | Success. |

## Remarks

The caller should add envelopes in time-ascending order. Otherwise, the results on playback are indeterminate. If one envelope overlaps another, the later envelope takes precedence.

To enumerate the parameters supported by this object, along with their index values, use the [IMediaParamInfo](https://learn.microsoft.com/windows/desktop/api/medparam/nn-medparam-imediaparaminfo) interface.

#### Examples

The following code sets two envelope segments, both using a linear function.

```cpp

#define MSEC 10000  // One millisecond

// Define an array with two segments. Note the segments appear in
// time-ascending order.
MP_ENVELOPE_SEGMENT Segments[] =
{
    {
        0,                  // rtStart
        3 * MSEC,           // rtStop
        0,                  // valStart
        12,                 // valStop
        MP_CURVE_LINEAR,    // iCurve
        MPF_ENVLP_STANDARD  // flags
    },
    {
        6 * MSEC,
        9 * MSEC,
        12,
        0,
        MP_CURVE_LINEAR,
        MPF_ENVLP_STANDARD
    }
};
// Define the number of segments in the array.
DWORD cSegments = sizeof(Segments) / sizeof(Segments[0]);
DWORD dwParam = 0;  // Which parameter to set.

hr = pMediaParams->AddEnvelope(dwParam, cSegments, Segments);

```

This example assumes that the caller has previous used the **IMediaParamInfo** interface to query whether the DMO supports the MP_CURVE_LINEAR curve for that parameter.

## See also

[IMediaParams Interface](https://learn.microsoft.com/windows/desktop/api/medparam/nn-medparam-imediaparams)