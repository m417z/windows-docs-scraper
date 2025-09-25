# WAVEFILTER structure

## Description

The **WAVEFILTER** structure defines a filter for waveform-audio data. Only filter information common to all waveform-audio data filters is included in this structure. For filters that require additional information, this structure is included as the first member in another structure along with the additional information.

## Members

### `cbStruct`

Size, in bytes, of the **WAVEFILTER** structure. The size specified in this member must be large enough to contain the base **WAVEFILTER** structure.

### `dwFilterTag`

Waveform-audio filter type. Filter tags are registered with Microsoft Corporation for various filter algorithms.

### `fdwFilter`

Flags for the **dwFilterTag** member. The flags defined for this member are universal to all filters. Currently, no flags are defined.

### `dwReserved`

Reserved for system use; should not be examined or modified by an application.

## See also

[Waveform Audio](https://learn.microsoft.com/windows/desktop/Multimedia/waveform-audio)

[Waveform Structures](https://learn.microsoft.com/windows/desktop/Multimedia/waveform-structures)