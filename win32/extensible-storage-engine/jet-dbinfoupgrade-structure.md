# JET_DBINFOUPGRADE Structure

_**Applies to:** Windows | Windows Server_

## JET_DBINFOUPGRADE Structure

The **JET_DBINFOUPGRADE** structure holds information about the upgrade status of the database. This value is retrieved only if **JET_DBINFOUPGRADE** was passed to [JetGetDatabaseInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetdatabaseinfo-function) or [JetGetDatabaseFileInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetdatabasefileinfo-function). This structure is not required for current operating system versions of the database engine.

```cpp
    typedef struct {
      unsigned long cbStruct;
      unsigned long cbFilesizeLow;
      unsigned long cbFilesizeHigh;
      unsigned long cbFreeSpaceRequiredLow;
      unsigned long  cbFreeSpaceRequiredHigh;
      unsigned long csecToUpgrade;
      union {
        unsigned long ulFlags;
        struct {
          unsigned long fUpgradable  :1;
          unsigned long fAlreadyUpgraded  :1;
        };
      };
    } JET_DBINFOUPGRADE;
```

### Members

**cbStruct**

Set to the size of the **JET_DBINFOUPGRADE** structure, in bytes.

**cbFilesizeLow**

The low **DWORD** that reflects the current file size for the database.

**cbFilesizeHigh**

The high **DWORD** that reflects the current file size for the database.

**cbFreeSpaceRequiredLow**

The low **DWORD** of estimated free disk space required for an in-place upgrade.

**cbFreeSpaceRequiredHigh**

The high **DWORD** of estimated free disk space required for an in-place upgrade.

**csecToUpgrade**

The estimated time required to upgrade, in seconds.

**ulFlags**

A bit field made of zero or more of the following flags: **fUpgradable**, **fAlreadyUpgraded**.

**fUpgradable**

The database is upgradeable.

**fAlreadyUpgraded**

The database is upgraded to the current database format.

### Remarks

A **JET_DBINFOUPGRADE** structure is populated by a call to [JetGetDatabaseInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetdatabaseinfo-function) or [JetGetDatabaseFileInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetdatabasefileinfo-function). If the function does not succeed, the contents of the structure are undefined.

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

[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_GRBIT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-grbit)
[JET_SESID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-sesid)
[JET_TABLEID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tableid)
[JetGetIndexInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetindexinfo-function)
[JetGetObjectInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetobjectinfo-function)
[JetGetTableIndexInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgettableindexinfo-function)
[JetGetTableInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgettableinfo-function)