# JET_LGPOS Structure

_**Applies to:** Windows | Windows Server_

## JET_LGPOS Structure

The **JET_LGPOS** structure holds data that is internal to the logging mechanism of the database engine. This structure is considered internal.

```cpp
    typedef struct {
      unsigned short ib;
      unsigned short isec;
      long lGeneration;
    } JET_LGPOS;
```

### Members

**ib**

Supports the ESE infrastructure and cannot be used from your code.

**isec**

Supports the ESE infrastructure and cannot be used from your code.

**lGeneration**

Supports the ESE infrastructure and cannot be used from your code.

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

[JET_BKINFO](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-bkinfo-structure)
[JET_DBINFOMISC](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-dbinfomisc-structure)