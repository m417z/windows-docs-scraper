# IMFRateSupport::GetFastestRate

## Description

Gets the fastest playback rate supported by the object.

## Parameters

### `eDirection` [in]

Specifies whether to query to the fastest forward playback rate or reverse playback rate. The value is a member of the [MFRATE_DIRECTION](https://learn.microsoft.com/windows/desktop/api/mfidl/ne-mfidl-mfrate_direction) enumeration.

### `fThin` [in]

If **TRUE**, the method retrieves the fastest thinned playback rate. Otherwise, the method retrieves the fastest non-thinned playback rate. For information about thinning, see [About Rate Control](https://learn.microsoft.com/windows/desktop/medfound/about-rate-control).

### `pflRate` [out]

Receives the fastest playback rate that the object supports.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_REVERSE_UNSUPPORTED** | The object does not support reverse playback. |
| **MF_E_THINNING_UNSUPPORTED** | The object does not support thinning. |

## Remarks

For some formats (such as ASF), thinning means dropping all frames that are not I-frames. If a component produces stream data, such as a media source or a demultiplexer, it should pay attention to the *fThin* parameter and return MF_E_THINNING_UNSUPPORTED if it cannot thin the stream.

If the component processes or receives a stream (most transforms or media sinks), it may ignore this parameter if it does not care whether the stream is thinned. In the Media Session's implementation of rate support, if the transforms do not explicitly support reverse playback, the Media Session will attempt to playback in reverse with thinning but not without thinning. Therefore, most applications will set *fThin* to **TRUE** when using the Media Session for reverse playback.

If *eDirection* is MFRATE_REVERSE, the method retrieves the fastest reverse playback rate. This is a negative value, assuming the object supports reverse playback.

## See also

[How to Determine Supported Rates](https://learn.microsoft.com/windows/desktop/medfound/how-to-determine-supported-rates)

[IMFRateSupport](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfratesupport)