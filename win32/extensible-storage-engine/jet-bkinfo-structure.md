# JET_BKINFO Structure

_**Applies to:** Windows | Windows Server_

## JET_BKINFO Structure

The **JET_BKINFO** structure holds a collection of data about a specific backup event.

```cpp
    typedef struct {
      JET_LGPOS lgposMark;
      union {
        JET_LOGTIME logtimeMark;
        JET_BKLOGTIME bklogtimeMark;
      };
      unsigned long genLow;
      unsigned long genHigh;
    } JET_BKINFO;
```

### Members

**lgposMark**

The ID of this backup.

**logtimeMark**

The time of this backup event.

**bklogtimeMark**

The time of this backup event, with additional bits to indicate a snapshot backup.

**Windows Vista: bklogtimeMark** is introduced in Windows Vista.

**genLow**

The low log generation number associated with this backup event.

**genHigh**

The high log generation number associated with this backup event.

### Remarks

This structure is used inside the [JET_DBINFOMISC](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-dbinfomisc-structure) structure to represent data about the database backup event.

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

[JET_LGPOS](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-lgpos-structure)
[JET_LOGTIME](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-logtime-structure)
[JET_BKLOGTIME](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-bklogtime-structure)
[JET_DBINFOMISC](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-dbinfomisc-structure)