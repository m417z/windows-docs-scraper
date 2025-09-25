# midiOutCacheDrumPatches function

## Description

The **midiOutCacheDrumPatches** function requests that an internal MIDI synthesizer device preload and cache a specified set of key-based percussion patches.

## Parameters

### `hmo`

Handle to the opened MIDI output device. This device should be an internal MIDI synthesizer. This parameter can also be the handle of a MIDI stream, cast to **HMIDIOUT**.

### `uPatch`

Drum patch number that should be used. This parameter should be set to zero to cache the default drum patch.

### `pwkya`

Pointer to a [KEYARRAY](https://learn.microsoft.com/windows/desktop/Multimedia/keyarray) array indicating the key numbers of the specified percussion patches to be cached or uncached.

### `fuCache`

Options for the cache operation. It can be one of the following flags.

| Value | Meaning |
| --- | --- |
| MIDI_CACHE_ALL | Caches all of the specified patches. If they cannot all be cached, it caches none, clears the [KEYARRAY](https://learn.microsoft.com/windows/desktop/Multimedia/keyarray) array, and returns MMSYSERR_NOMEM. |
| MIDI_CACHE_BESTFIT | Caches all of the specified patches. If they cannot all be cached, it caches as many patches as possible, changes the KEYARRAY array to reflect which patches were cached, and returns MMSYSERR_NOMEM. |
| MIDI_CACHE_QUERY | Changes the [KEYARRAY](https://learn.microsoft.com/windows/desktop/Multimedia/keyarray) array to indicate which patches are currently cached. |
| MIDI_UNCACHE | Uncaches the specified patches and clears the KEYARRAY array. |

## Return value

Returns MMSYSERR_NOERROR if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **MMSYSERR_INVALFLAG** | The flag specified by *wFlags* is invalid. |
| **MMSYSERR_INVALHANDLE** | The specified device handle is invalid. |
| **MMSYSERR_INVALPARAM** | The array pointed to by the *lpKeyArray* array is invalid. |
| **MMSYSERR_NOMEM** | The device does not have enough memory to cache all of the requested patches. |
| **MMSYSERR_NOTSUPPORTED** | The specified device does not support patch caching. |

## Remarks

Some synthesizers are not capable of keeping all percussion patches loaded simultaneously. Caching patches ensures that the specified patches are available.

Each element of the [KEYARRAY](https://learn.microsoft.com/windows/desktop/Multimedia/keyarray) array represents one of the 128 key-based percussion patches and has bits set for each of the 16 MIDI channels that use the particular patch. The least-significant bit represents physical channel 0, and the most-significant bit represents physical channel 15. For example, if the patch on key number 60 is used by physical channels 9 and 15, element 60 would be set to 0x8200.

This function applies only to internal MIDI synthesizer devices. Not all internal synthesizers support patch caching. To see if a device supports patch caching, use the MIDICAPS_CACHE flag to test the **dwSupport** member of the [MIDIOUTCAPS](https://learn.microsoft.com/previous-versions/dd798467(v=vs.85)) structure filled by the [midiOutGetDevCaps](https://learn.microsoft.com/previous-versions/dd798469(v=vs.85)) function.

## See also

[MIDI Functions](https://learn.microsoft.com/windows/desktop/Multimedia/midi-functions)