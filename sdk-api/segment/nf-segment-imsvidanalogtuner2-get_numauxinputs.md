# IMSVidAnalogTuner2::get_NumAuxInputs

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005 and later.

The **get_NumAuxInputs** method retrieves the number of auxiliary inputs that are available. Auxiliary inputs include S-video and composite inputs.

## Parameters

### `Inputs` [out]

Pointer to a variable that receives the number of auxiliary inputs.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_POINTER** | NULL pointer argument. |
| **S_OK** | Success. |

## Remarks

A crossbar filter exposes two auxiliary inputs for each audio input that it supports. That is, each audio input pin has two corresponding auxiliary input pins: S-video and composite video.

The number of auxiliary inputs returned by this method includes all auxiliary inputs, even if the physical input jacks are combined in some manner (for example, with some sort of proprietary or overloaded jack).

The first S-video input is channel 0 and the first composite input is channel 1. Additional S-video inputs are on even-numbered channels and additional composite inputs are on odd-numbered channels.

## See also

[IMSVidAnalogTuner2 Interface](https://learn.microsoft.com/windows/desktop/api/segment/nn-segment-imsvidanalogtuner2)