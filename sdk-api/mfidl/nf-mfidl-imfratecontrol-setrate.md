# IMFRateControl::SetRate

## Description

Sets the playback rate.

## Parameters

### `fThin` [in]

If **TRUE**, the media streams are thinned. Otherwise, the stream is not thinned. For media sources and demultiplexers, the object must thin the streams when this parameter is **TRUE**. For downstream transforms, such as decoders and multiplexers, this parameter is informative; it notifies the object that the input streams are thinned. For information, see [About Rate Control](https://learn.microsoft.com/windows/desktop/medfound/about-rate-control).

### `flRate` [in]

The requested playback rate. Positive values indicate forward playback, negative values indicate reverse playback, and zero indicates scrubbing (the source delivers a single frame).

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_REVERSE_UNSUPPORTED** | The object does not support reverse playback. |
| **MF_E_THINNING_UNSUPPORTED** | The object does not support thinning. |
| **MF_E_UNSUPPORTED_RATE** | The object does not support the requested playback rate. |
| **MF_E_UNSUPPORTED_RATE_TRANSITION** | The object cannot change to the new rate while in the running state. |

## Remarks

The Media Session prevents some transitions between rate boundaries, depending on the current playback state:

| Playback State | Forward/Reverse | Forward/Zero | Reverse/Zero |
| --- | --- | --- | --- |
| Running | No | No | No |
| Paused | No | Yes | No |
| Stopped | Yes | Yes | Yes |

If the transition is not supported, the method returns **MF_E_UNSUPPORTED_RATE_TRANSITION**.

When a media source completes a call to **SetRate**, it sends the [MESourceRateChanged](https://learn.microsoft.com/windows/desktop/medfound/mesourceratechanged) event. Other pipeline components do not send this event.

If a media source switches between thinned and non-thinned playback, the streams send an [MEStreamThinMode](https://learn.microsoft.com/windows/desktop/medfound/mestreamthinmode) event to indicate the transition. Events from the media source are not synchronized with events from the media streams. After you receive the [MESourceRateChanged](https://learn.microsoft.com/windows/desktop/medfound/mesourceratechanged) event, you can still receive samples that were queued before the stream switched to thinned or non-thinned mode. The MEStreamThinMode event marks the exact point in the stream where the transition occurs.

When the Media Session completes a call to **SetRate**, it sends the [MESessionRateChanged](https://learn.microsoft.com/windows/desktop/medfound/mesessionratechanged) event.

## See also

[How to Set the Playback Rate on the Media Session](https://learn.microsoft.com/windows/desktop/medfound/how-to-set-the-playback-rate-on-the-media-session)

[IMFRateControl](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfratecontrol)