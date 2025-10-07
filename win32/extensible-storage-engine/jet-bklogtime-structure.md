# JET_BKLOGTIME Structure

_**Applies to:** Windows | Windows Server_

## JET_BKLOGTIME Structure

The **JET_BKLOGTIME** structure holds the date and time elements of an event. It is an extension of [JET_LOGTIME](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-logtime-structure).

**Windows Vista: JET_BKLOGTIME** is introduced in Windows Vista.

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
      union {
        char bFiller2;
        struct {
          unsigned char fOSSnapshot  :1;
          unsigned char fReserved  :7;
        };
      };
    } JET_BKLOGTIME;
```

### Members

**bSeconds**

The time of the event in seconds. This can be 0 (zero) to 60. 0 (zero) is used when the **JET_BKLOGTIME** structure is "null".

**bMinutes**

The time of the event in minutes. This can be 0 (zero) to 60. 0 (zero) is used when the **JET_BKLOGTIME** structure is "null".

**bHours**

The time of the event in hours. This can be 0 (zero) to 24. 0 (zero) is used when the **JET_BKLOGTIME** structure is "null".

**bDay**

The day of the month of the event. This can be 0 (zero) to 31. 0 (zero) is used when the **JET_BKLOGTIME** structure is "null".

**bMonth**

The month of the year of the event. This can be 0 (zero) to 12. 0 (zero) is used when the **JET_BKLOGTIME** structure is "null".

**bYear**

The year (offset by 1900) of the event. To achieve the actual year, add 1900 to this value. 0 (zero) is used when the **JET_BKLOGTIME** structure is "null".

**bFiller1**

This field should be ignored.

**fTimeIsUTC**

The time is in UTC format.

**fUnused**

This field should be ignored.

**bFiller2**

This field should be ignored.

**fOSSnapshot**

If this event is a backup, this flag contains one of the following possible values:

|

Name

|

Value

|
|-------------|--------------|
|

streaming backup

|

0 (zero)

|
|

snapshot backup

|

1

|

**fReserved**

This field should be ignored.

### Remarks

This structure is used when debugging.

### Requirements

| Requirement | Value |
|------------|----------|
|

**Client**

|

Requires Windows Vista.

|
|

**Server**

|

Requires Windows Server 2008.

|
|

**Header**

|

Declared in Esent.h.

|

### See Also

[JET_LOGTIME](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-logtime-structure)
[JET_DBINFOMISC](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-dbinfomisc-structure)