# MCI\_HMS\_SECOND macro

The **MCI\_HMS\_SECOND** macro retrieves the seconds component from a parameter containing packed hours/minutes/seconds (HMS) information.

## Parameters

*dwHMS*

Time in HMS format.

## Return value

Returns the seconds component of the specified HMS information.

## Remarks

Time in HMS format is expressed as a **DWORD** value with the least significant byte containing hours, the next least significant byte containing minutes, and the next least significant byte containing seconds. The most significant byte is unused.

The **MCI\_HMS\_SECOND** macro is defined as follows:

```C++
#define MCI_HMS_SECOND(hms) ((BYTE)((hms) >> 16))
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

