# MCI\_TMSF\_FRAME macro

The **MCI\_TMSF\_FRAME** macro retrieves the frames component from a parameter containing packed tracks/minutes/seconds/frames (TMSF) information.

## Parameters

*dwTMSF*

Time in TMSF format.

## Return value

Returns the frames component of the specified TMSF information.

## Remarks

Time in TMSF format is expressed as a **DWORD** value with the least significant byte containing tracks, the next least significant byte containing minutes, the next least significant byte containing seconds, and the most significant byte containing frames.

The **MCI\_TMSF\_FRAME** macro is defined as follows:

```C++
#define MCI_TMSF_FRAME(tmsf) ((BYTE)((tmsf) >> 24))
```

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Mciapi.h |

## See also

[MCI](https://learn.microsoft.com/windows/win32/multimedia/mci)

[MCI Macros](https://learn.microsoft.com/windows/win32/multimedia/mci-macros)

