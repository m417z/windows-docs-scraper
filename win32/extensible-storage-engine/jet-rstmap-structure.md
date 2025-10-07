# JET_RSTMAP Structure

_**Applies to:** Windows | Windows Server_

## JET_RSTMAP Structure

The **JET_RSTMAP** structure enables the remapping of database file paths that are stored in the transaction logs during recovery, when used by the [JetInit](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetinit-function) and [JetExternalRestore](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetexternalrestore-function) functions. This enables the databases to be moved when offline or when restored from backup.

```cpp
    typedef struct {
      xRPC_STRING tchar* szDatabaseName;
      xRPC_STRING tchar* szNewDatabaseName;
    } JET_RSTMAP;
```

### Members

**szDatabaseName**

The current absolute path of a database that is associated with the transaction logs that are replayed during recovery.

**szNewDatabaseName**

The new absolute path for the database.

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

Implemented as **JET_RSTMAP_W** (Unicode) and **JET_RSTMAP_A** (ANSI).

|

### See Also

[JetExternalRestore](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetexternalrestore-function)
[JetInit](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetinit-function)