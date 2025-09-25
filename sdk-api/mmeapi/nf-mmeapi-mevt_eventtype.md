# MEVT_EVENTTYPE macro

## Syntax

```cpp
BYTE MEVT_EVENTTYPE(
    DWORD x
);
```

## Return value

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

The event type from the value specified in the **dwEvent** member of a [MIDIEVENT](https://learn.microsoft.com/previous-versions/dd798448(v=vs.85)) structure.

## Description

The **MEVT_EVENTTYPE** macro retrieves the event type from the value specified in the **dwEvent** member of a [MIDIEVENT](https://learn.microsoft.com/previous-versions/dd798448(v=vs.85)) structure.

## Parameters

### `x`

Code for the MIDI event and the event parameters or length, as specified in the **dwEvent** member of the MIDIEVENT structure.

## Remarks

The **MEVT_EVENTTYPE** macro is defined as follows:

```cpp

#define MEVT_EVENTTYPE(x) ((BYTE) (((x)>>24)&0xFF))

```

## See also

[MIDI Macros](https://learn.microsoft.com/windows/desktop/Multimedia/midi-macros)