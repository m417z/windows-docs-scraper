# JET_LOGTIME Structure

_**Applies to:** Windows | Windows Server_

## JET_LOGTIME Structure

The **JET_LOGTIME** structure holds elements of the date and time of an event.

```cpp
typedef struct {
  char bSeconds;
  char bMinutes;
  char bHours;
  char bDay;
  char bMonth;
  char bYear;
  union {
    char bFiller1;
    struct {
        unsigned char fTimeIsUTC: 1;
        unsigned char fUnused: 7;
    };
  };
  char bFiller2;
} JET_LOGTIME;
```

### Members

**bSeconds**

The time of the event in seconds. This value can be 0 to 59. 0 is used when the structure is null.

**bMinutes**

The time of the event in minutes. This value can be 0 to 59. 0 is used when the structure is null.

**bHours**

The time of the event in hours. This value can be 0 to 23. 0 is used when the structure is null.

**bDay**

The day of the month of the event. This value can be 0 to 31. 0 is used when the structure is null.

**bMonth**

The month of the year of the event. This value can be 0 to 12. 0 is used when the structure is null.

**bYear**

The year of the event (offset by 1900). To achieve the actual year, add 1900 to this value. 0 is used when the structure is null.

**bFiller1**

This field should be ignored.

**fTimeIsUTC**

The time is in UTC format.

**fUnused**

This field should be ignored.

**bFiller2**

This field should be ignored.

### Remarks

This structure is meant primarily for usage in debugging.

### Requirements

| Requirement | Value |
|------------|----------|
|

**Client**

|

Requires Windows Vista, Windows XP, or Windows 2000 Professional.

|
|

**Server**

|

Requires Windows Server 2008, Windows Server 2003, or Windows 2000 Server.

|
|

**Header**

|

Declared in Esent.h.

|

### See Also

[JET_DBINFOMISC](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-dbinfomisc-structure)