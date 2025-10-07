# JET_SIGNATURE Structure

_**Applies to:** Windows | Windows Server_

## JET_SIGNATURE Structure

The **JET_SIGNATURE** structure contains information that uniquely identifies a database.

```cpp
    typedef struct {
      unsigned long ulRandom;
      JET_LOGTIME logtimeCreate;
      char szComputerName[JET_MAX_COMPUTERNAME_LENGTH + 1];
    } JET_SIGNATURE;
```

### Members

**ulRandom**

A randomly assigned number.

**logtimeCreate**

The [JET_LOGTIME](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-logtime-structure) at the time of [JetCreateDatabase](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreatedatabase-function) is executed.

**szComputerName**

The optional string value of the NetBIOS name for the computer. This value may not be set.

### Remarks

This can be found as an element of [JET_DBINFOMISC](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-dbinfomisc-structure).

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
[JET_LOGTIME](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-logtime-structure)
[JetCreateDatabase](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreatedatabase-function)