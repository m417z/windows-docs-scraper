# MCI\_MAKE\_MSF macro

The **MCI\_MAKE\_MSF** macro creates a time value in packed minutes/seconds/frames (MSF) format from the given minutes, seconds, and frame values.

## Parameters

*minutes*

Number of minutes.

*seconds*

Number of seconds.

*frames*

Number of frames.

## Return value

Returns the time in packed MSF format.

## Remarks

Time in MSF format is expressed as a **DWORD** value with the least significant byte containing minutes, the next least significant byte containing seconds, and the next least significant byte containing frames. The most significant byte is unused.

The **MCI\_MAKE\_MSF** macro is defined as follows:

```C++
#define MCI_MAKE_MSF(m, s, f) ((DWORD)(((BYTE)(m) | \
                              ((WORD)(s) << 8)) | \
                              (((DWORD)(BYTE)(f)) << 16)))
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

