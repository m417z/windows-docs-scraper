# IBDA_Encoder::QueryCapabilities

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the number of encoding formats supported by the device.

## Parameters

### `NumAudioFmts` [out]

Receives the number of audio formats.

### `NumVideoFmts` [out]

Receives the number of video formats.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IBDA_Encoder](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_encoder)