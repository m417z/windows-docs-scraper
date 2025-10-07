# JET_RSTINFO Structure

_**Applies to:** Windows | Windows Server_

## JET_RSTINFO Structure

The **JET_RSTINFO** structure contains control information for the recovery process like database relocation information and ability to control stopping recovery.

**Windows Vista:** The **JET_RSTINFO** structure is introduced in Windows Vista.

```cpp
    typedef struct {
      unsigned long cbStruct;
      JET_RSTMAP* rgrstmap;
      long crstmap;
      JET_LGPOS lgposStop;
      JET_LOGTIME logtimeStop;
      JET_PFNSTATUS pfnStatus;
    } JET_RSTINFO;
```

### Members

**cbStruct**

The size of the structure.

**rgrstmap**

The structure that describes the old and new path of a restored database.

**crstmap**

Count of array entries in the rgrstmap.

**lgposStop**

The log position to stop recovery at. No undo will be done.

**logtimeStop**

Reserved for future use.

**pfnStatus**

A status function for reporting status of recovery.

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
|

**Unicode**

|

Implemented as **JET_RSTINFO_W** (Unicode) and **JET_RSTINFO_A** (ANSI).

|

### See Also

[JetInit3](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetinit3-function)