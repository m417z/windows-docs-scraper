# MCI\_MSF\_SECOND macro

The **MCI\_MSF\_SECOND** macro retrieves the seconds component from a parameter containing packed minutes/seconds/frames (MSF) information.

## Parameters

*dwMSF*

Time in MSF format.

## Return value

Returns the seconds component of the specified MSF information.

## Remarks

Time in MSF format is expressed as a **DWORD** value with the least significant byte containing minutes, the next least significant byte containing seconds, and the next least significant byte containing frames. The most significant byte is unused.

The **MCI\_MSF\_SECOND** macro is defined as follows:

```C++
#define MCI_MSF_SECOND(msf) ((BYTE)(((WORD)(msf)) >> 8))
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

