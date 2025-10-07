# MCI\_MAKE\_HMS macro

The **MCI\_MAKE\_HMS** macro creates a time value in packed hours/minutes/seconds (HMS) format from the given hours, minutes, and seconds values.

## Parameters

*hours*

Number of hours.

*minutes*

Number of minutes.

*seconds*

Number of seconds.

## Return value

Returns the time in packed HMS format.

## Remarks

Time in HMS format is expressed as a **DWORD** value with the least significant byte containing hours, the next least significant byte containing minutes, and the next least significant byte containing seconds. The most significant byte is unused.

The **MCI\_MAKE\_HMS** macro is defined as follows:

```C++
#define MCI_MAKE_HMS(h, m, s) ((DWORD)(((BYTE)(h) | \
                              ((WORD)(m) << 8)) | \
                              (((DWORD)(BYTE)(s)) << 16)))
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

