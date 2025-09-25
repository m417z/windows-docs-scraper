# midiStreamProperty function

## Description

The **midiStreamProperty** function sets or retrieves properties of a MIDI data stream associated with a MIDI output device.

## Parameters

### `hms`

Handle to the MIDI device that the property is associated with.

### `lppropdata`

Pointer to the property data.

### `dwProperty`

Flags that specify the action to perform and identify the appropriate property of the MIDI data stream. The **midiStreamProperty** function requires setting two flags in each use. One flag (either MIDIPROP_GET or MIDIPROP_SET) specifies an action, and the other identifies a specific property to examine or edit.

| Value | Meaning |
| --- | --- |
| MIDIPROP_GET | Retrieves the current setting of the given property. |
| MIDIPROP_SET | Sets the given property. |
| MIDIPROP_TEMPO | Retrieves the tempo property. The *lppropdata* parameter points to a [MIDIPROPTEMPO](https://learn.microsoft.com/previous-versions/dd798483(v=vs.85)) structure. The current tempo value can be retrieved at any time. Output devices set the tempo by inserting MEVT_TEMPO events into the MIDI data. |
| MIDIPROP_TIMEDIV | Specifies the time division property. You can get or set this property. The *lppropdata* parameter points to a [MIDIPROPTIMEDIV](https://learn.microsoft.com/previous-versions/dd798484(v=vs.85)) structure. This property can be set only when the device is stopped. |

## Return value

Returns MMSYSERR_NOERROR if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **MMSYSERR_INVALHANDLE** | The specified handle is not a stream handle. |
| **MMSYSERR_INVALPARAM** | The given handle or flags parameter is invalid. |

## Remarks

These properties are the default properties defined by the system. Driver writers can implement and document their own properties.

## See also

[MIDI Functions](https://learn.microsoft.com/windows/desktop/Multimedia/midi-functions)