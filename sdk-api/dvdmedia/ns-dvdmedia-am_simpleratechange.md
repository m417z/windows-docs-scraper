# AM_SimpleRateChange structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **AM_SimpleRateChange** structure is used to change the playback rate for an MPEG-2 stream.

## Members

### `StartTime`

Specifies the time stamp on the input sample when the new rate takes effect. The new rate applies to all samples with a time stamp >= **StartTime** and less than the start time on the next queued rate segment.

### `Rate`

Specifies the new rate x 10000. Rate is the inverse of speed. For example, if the playback speed is 2x, the rate is 1/2, so the **Rate** member is set to 5000.

## Remarks

### Version 1.1 Semantics

For version 1.1 of this property set, the **StartTime** member can be -1. This value indicates that the rate change applies to the decoder's *most forward* sample, defined as the sample at the head of the decoder's outgoing queue. To get the actual start time of the rate change, query the [AM_RATE_QueryLastRateSegPTS](https://learn.microsoft.com/windows/desktop/DirectShow/am-rate-querylastratesegpts-property) property.

The decoder should adjust the time stamps on every queued sample to reflect the new rate. Queued samples might be incompatible with the new rate, especially for audio decoders. If so, the decoder may simply drop the queued samples. After dropping samples, it should set the discontinuity flag on the first sample it delivers.

In the case where **StartTime** is -1, but the new rate is incompatible and the decoder does not keep a queue of samples, the decoder should return VFW_E_DVD_WRONG_SPEED from the [IKsPropertySet::Set](https://learn.microsoft.com/windows/desktop/DirectShow/ikspropertyset-set) method. The source filter can then set a rate change with a specified (not -1) start time.

The source filter can schedule a rate change whose start time is earlier than previously queued rate changes. This invalidates any rate changes further down the queue; the decoder should discard them. If **StartTime** is -1, the decoder should discard all pending rate changes before queuing the new rate change.

The source filter can also schedule a rate change for a start time in the past—that is, earlier than any queued sample. In that case, the decoder should adjust the time stamps of all queued samples.

If a sample spans the start time, and the new rate is incompatible, the behavior is undefined. The decoder may keep the sample or discard it, depending on the media.

### Source Filter Requirements

* The source filter's time stamps correspond to a 1x rate. The decoder filter adjusts the time stamps to match the rate.
* During reverse playback, time stamps increase. They do not go backward. The source filter does not set a discontinuity flag when the rate transitions between forward and reverse playback (unless the source filter is also dropping frames).
* For MPEG-2 content, GOPs must be presented in forward order, even during reverse playback. During reverse playback, the GOP-to-GOP order is reversed. Each GOP has one time stamp for the I frame, with no time stamps for non-I frames. Each GOP is contained in one sample.
* During reverse playback, audio is presented in reverse order. If there is more than one audio sample per media sample, the decoder must send the audio samples to the audio renderer in reverse order.
* The source filter must recover if it sets a rate change with **StartTime** = -1 and the decoder fails the call.

### Decoder Requirements

* The decoder queues rate changes, sorted in order of start time. It uses these rate changes to scale the time stamps on decoded samples.
* All rate changes must be queued and used to computer scaled time stamps, regardless of rate compatibility.
* When scaling time stamps, the decoder must take into account any segments where it dropped samples due to rate incompatibility.
* The rate-change equation uses the value of **StartTime**, even if that value does not exactly match any sample's presentation time.

### Calculating Rate Changes

In the following diagram, the output time stamp (y) is given by formula

y = r(x - xi)

where x is the input time stamp, r is the rate, and xi is the x-intercept for the current rate. This formula is obtained by solving for the equation y = mx + b at the point xi, where m is the slope (r) and b is the y-intercept. This gives b = -m(xi), which can then be substituted back into the equation y = mx + b.

![A diagram showing the relation between input time stamps and output time stamps.](https://learn.microsoft.com/windows/win32/api/dvdmedia/images/dvd_ratechange.png)

The decoder can calculate the x-intercept as follows. Given:

 r1 = previous rate

 r2 = current rate

 xi1 = x-intercept for the previous rate change

 xi2 = x-intercept for the current rate change

 x = start time for the current rate change

The unknown xi2 can be found by setting y = r2(x - xi2) = r1(x - xi1) and solving for xi2. (Refer to the diagram that follows.) This gives the following result:

 xi2 = (r1 / r2)(xi1 - x) + x

![A diagram showing the x intercept of the r2.](https://learn.microsoft.com/windows/win32/api/dvdmedia/images/dvd_rate_change2.png)

In the special case where playback is 1x at time 0, r1 = 1 and xi1 = 0.

#### Examples

The following code sets the rate, starting from the most forward sample. It returns the effective start time in the *prtStartTime* parameter.

```cpp

HRESULT SetRateToMostForward(
    IKsPropertySet *pIKsPropertySet,
    double dRate,
    REFERENCE_TIME *prtStartTime
    )
{
    AM_SimpleRateChange rateSet;
    rateSet.Rate        = LONG(dRate * 10000);
    rateSet.StartTime   = -1; //  Use the most forward sample

    HRESULT hr = pIKsPropertySet->Set(
        AM_KSPROPSETID_TSRateChange, //  Property set.
        AM_RATE_SimpleRateChange,    //  Property ID.
        NULL,                        //  Instance data.
        0,                           //  Size of instance data.
        &rateSet,                    //  Property data.
        sizeof(rateSet)              //  Size of property data.
        );
    if (SUCCEEDED(hr))
    {
        // Get the actual time.
        DWORD cbData = sizeof(REFERENCE_TIME);
        hr = pIKsPropertySet->Get (
            AM_KSPROPSETID_TSRateChange, //  Property set.
            AM_RATE_QueryLastRateSegPTS, //  Property ID.
            NULL,                        //  Instance data.
            0,                           //  Size of instance data.
            prtStartTime,                //  Property data.
            cbData,                      //  Size of property data.
            &cbData                      //  Size of data returned.
            );
    }
    return hr;
}

```

The following code sets the rate, starting from a specified time:

```cpp

HRESULT SetRate(
    IKsPropertySet *pIKsPropertySet,
    double dRate,
    REFERENCE_TIME rtStartTime
    )
{
    AM_SimpleRateChange rateSet ;

    rateSet.Rate        = LONG(dRate * 10000);
    rateSet.StartTime   = rtStartTime;

    return IKsPropertySet->Set(
        AM_KSPROPSETID_TSRateChange,    //  Property set.
        AM_RATE_SimpleRateChange,       //  Property ID.
        NULL,                           //  Instance data.
        0,                              //  Size of instance data.
        &rateSet,                       //  Property data.
        sizeof(RateSet)                 //  Size of property data.
        );
}

```

## See also

[AM_RATE_SimpleRateChange Property](https://learn.microsoft.com/windows/desktop/DirectShow/am-rate-simpleratechange-property)

[Rate Change Property Set](https://learn.microsoft.com/windows/desktop/DirectShow/rate-change-property-set)