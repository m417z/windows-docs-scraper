# MEVT_EVENTPARM macro

## Syntax

```cpp
DWORD MEVT_EVENTPARM(
    DWORD x
);
```

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

The event parameters or length from the value specified in the **dwEvent** member of a [MIDIEVENT](https://learn.microsoft.com/previous-versions/dd798448(v=vs.85)) structure.

## Description

The **MEVT_EVENTPARM** macro retrieves the event parameters or length from the value specified in the **dwEvent** member of a [MIDIEVENT](https://learn.microsoft.com/previous-versions/dd798448(v=vs.85)) structure.

## Parameters

### `x`

Code for the MIDI event and the event parameters or length, as specified in the dwEvent member of the MIDIEVENT structure.

## Remarks

The **MEVT_EVENTPARM** macro is defined as follows:

```cpp

#define MEVT_EVENTPARM(x) ((DWORD) ((x)&0x00FFFFFFL))

```