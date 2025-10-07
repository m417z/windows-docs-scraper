# MCI\_MAKE\_TMSF macro

The **MCI\_MAKE\_TMSF** macro creates a time value in packed tracks/minutes/seconds/frames (TMSF) format from the given tracks, minutes, seconds, and frames values.

## Parameters

*tracks*

Number of tracks.

*minutes*

Number of minutes.

*seconds*

Number of seconds.

*frames*

Number of frames.

## Return value

Returns the time in packed TMSF format.

## Remarks

Time in TMSF format is expressed as a **DWORD** value with the least significant byte containing tracks, the next least significant byte containing minutes, the next least significant byte containing seconds, and the most significant byte containing frames.

The **MCI\_MAKE\_TMSF** macro is defined as follows:

```C++
#define MCI_MAKE_TMSF(t, m, s, f) ((DWORD)(((BYTE)(t) | \
                                  ((WORD)(m) << 8)) | \
                                  (((DWORD)(BYTE)(s) | \
                                  ((WORD)(f) << 8)) << 16)))
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

