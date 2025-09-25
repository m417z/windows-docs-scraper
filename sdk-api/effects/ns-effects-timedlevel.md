# TimedLevel structure

## Description

The **TimedLevel** structure holds data returned from the spectrum filter.

## Members

### `frequency`

A stereo snapshot of the frequency spectrum of the audio data at a time specified by the Plug-in Manager. It can be used for frequency spectrum effects such as real-time analyzers. The frequency value of the first cell is 20 Hz, and the frequency value of the last cell is 22050 Hz.

### `waveform`

A stereo snapshot of the power value of the audio data at a time specified by the Plug-in Manager as the first element; the next 1024 stereo power values fill out the rest of the array. It can be used for oscilloscope-type effects.

### `state`

One member of the [PlayerState](https://learn.microsoft.com/windows/desktop/api/effects/ne-effects-playerstate) enumeration type.

### `timeStamp`

The time the snapshot took place, in a 64-bit integer. The time value is provided in 100-nanosecond units.

## Remarks

The array dimension **SA_BUFFER_SIZE** is currently 1024.

The first dimension of each array corresponds to the channel: 0 is a monaural signal or the left channel of a stereo signal, and 1 is the right channel of a stereo signal. If the signal is monaural, the values in the array that would correspond to the right channel are undefined.

The second dimension contains the sampled levels. The frequency data ranges from 0 to 255. The waveform data represents -128 to 127 but is stored as 0 to 255, so subtract 128 to get the correct value.

## See also

[PlayerState](https://learn.microsoft.com/windows/desktop/api/effects/ne-effects-playerstate)

[Visualization Structures and Enumeration Types](https://learn.microsoft.com/windows/desktop/WMP/visualization-structures-and-enumeration-types)