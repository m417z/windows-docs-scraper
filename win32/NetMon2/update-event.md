# UPDATE\_EVENT structure

The **UPDATE\_EVENT** structure updates events. This structure is passed back to the calling application via the event status callback procedure by the NPP.

## Members

**Event**

Actual event being recorded.

**Action**

The action taken.

**Status**

Network status indication.

**Value**

Auxiliary counter variable.

**TimeStamp**

The marked events, in microseconds.

**lpUserContext**

User context given by the application.

**lpReserved**

Driver or NAL use.

**FramesDropped**

RTF frames dropped in the specified buffer.

**Reserved**

No data comes back with this switch option.

**lpFrameTable**

RTF only.

**lpPacketQueue**

For transmits.

**SecurityResponse**

Remote security monitor response.

**lpFinalStats**

This is only filled in on non-security related stops (for example, triggers).

## Remarks

C++ users should note that the declaration for this callback should be in the public part of the header file:

``` syntax
static WINAPI DWORD NetworkCallback( UPDATE_EVENT events);
```

The implementation should be in the protected section of the .cpp file:

``` syntax
DWORD WINAPI ClassName::NetworkCallback( UPDATE_EVENT events) {};
```

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |

