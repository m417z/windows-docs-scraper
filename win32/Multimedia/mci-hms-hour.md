# MCI\_HMS\_HOUR macro

The **MCI\_HMS\_HOUR** macro retrieves the hours component from a parameter containing packed hours/minutes/seconds (HMS) information.

## Parameters

*dwHMS*

Time in HMS format.

## Return value

Returns the hours component of the specified HMS information.

## Remarks

Time in HMS format is expressed as a **DWORD** value with the least significant byte containing hours, the next least significant byte containing minutes, and the next least significant byte containing seconds. The most significant byte is unused.

The **MCI\_HMS\_HOUR** macro is defined as follows:

```C++
#define MCI_HMS_HOUR(hms) ((BYTE)(hms))
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

