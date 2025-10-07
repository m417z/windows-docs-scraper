# SHAREDMEMORY\_HEADER structure

Stores information about shared memory sections.

## Members

**cbTotal**

The size, in bytes, of the data referenced by this header structure.

**cbOffsetSns**

The size, in bytes, that the serial numbers are offset from the header structure.

**idxEvent**

The event index. This value is incremented with successive events.

**dwEvent**

The event associated with this header.

**cid**

The cursor identifier referenced by the shared memory header.

**sn**

The serial number for the shared memory header.

**sysEvt**

The system event, prefixed SE\_\*, associated with this header. See the remarks section for more information.

**sysEvtData**

The [**SYSTEM\_EVENT\_DATA**](https://learn.microsoft.com/windows/win32/api/tpcshrd/ns-tpcshrd-system_event_data) structure associated with the system event.

**cPackets**

A count of the packets associated with the current shared memory section.

**cbPackets**

The size, in bytes, of the packets associated with the current shared memory section.

**fSnsPresent**

A flag indicating whether serial numbers are present in the current shared memory section.

## Remarks

The following values are defined for the **sysEvt** member.

```C++
#define SE_NONE                  0x00000000
#define SE_TAP                   0x00000010
#define SE_DBL_TAP               0x00000011
#define SE_RIGHT_TAP             0x00000012
#define SE_DRAG                  0x00000013
#define SE_RIGHT_DRAG            0x00000014
#define SE_HOLD_ENTER            0x00000015
#define SE_HOLD_LEAVE            0x00000016
#define SE_HOVER_ENTER           0x00000017
#define SE_HOVER_LEAVE           0x00000018
#define SE_FLICK                 0x0000001F
```

## See also

[**SYSTEM\_EVENT\_DATA**](https://learn.microsoft.com/windows/win32/api/tpcshrd/ns-tpcshrd-system_event_data)

