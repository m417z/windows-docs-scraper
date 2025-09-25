# _IRB_REQ_ISOCH_SET_CHANNEL_BANDWIDTH structure

## Description

This structure contains the fields necessary for the Bus driver to carry out an **IsochSetChannelBandwidth** request.

## Members

### `hBandwidth`

Bandwidth handle to reset.

### `nMaxBytesPerFrame`

Specifies the new bandwidth for **hBandwidth**.

### `nBandwidthUnitsRequired`

Specifies a pre-calculated value.

## Remarks

This request does not require the caller to know the bandwidth that was allocated when a handle was generated. REQUEST_ISOCH_SET_CHANNEL_BANDWIDTH can be used to readjust the bandwidth on a bandwidth handle whose bytes per frame setting is unknown. Despite its name, this request does not involve isochronous channels in any way.