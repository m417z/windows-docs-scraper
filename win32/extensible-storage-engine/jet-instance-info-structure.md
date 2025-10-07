# JET_INSTANCE_INFO Structure

_**Applies to:** Windows | Windows Server_

## JET_INSTANCE_INFO Structure

The **JET_INSTANCE_INFO** structure receives information about running database instances when used with the [JetGetInstanceInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetinstanceinfo-function) and [JetOSSnapshotFreeze](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetossnapshotfreeze-function) functions.

```cpp
    typedef struct _JET_INSTANCE_INFO {
      JET_INSTANCE hInstanceId;
      tchar* szInstanceName;
      JET_API_PTR cDatabases;
      tchar** szDatabaseFileName;
      tchar** szDatabaseDisplayName;
      tchar** szDatabaseSLVFileName;
    } JET_INSTANCE_INFO;
```

### Members

**hInstanceId**

The [JET_INSTANCE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-instance) of the given instance.

**szInstanceName**

The name of the database instance. This value can be **NULL** if the instance does not have a name.

**cDatabases**

The number of databases that are attached to the database instance. **cDatabases** also holds the size of the arrays of strings that are returned in **szDatabaseFileName**, **szDatabaseDisplayName**, and **szDatabaseSLVFileName**.

**szDatabaseFileName**

An array of strings, each holding the file name of a database that is attached to the database instance. The array has **cDatabases** elements.

**szDatabaseDisplayName**

An array of strings, each holding the display name of a database. Currently the string can be NULL. The array has **cDatabases** elements.

**szDatabaseSLVFileName**

An array of strings, each holding the file name of the SLV file that is attached to the database instance. The array has **cDatabases** elements. SLV files are not supported, so this field should be ignored.

### Remarks

Each database instance can have several databases attached to it.

For a given **JET_INSTANCE_INFO** structure, the array of strings that is returned for the databases are in the same order. For example, "szDatabaseDisplayName\[ i \]" and "szDatabaseFileName\[ i \]" both refer to the same database.

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

Implemented as **JET_INSTANCE_INFO_W** (Unicode) and **JET_INSTANCE_INFO _A** (ANSI).

|

### See Also

[JET_API_PTR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-api-ptr)
[JET_INSTANCE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-instance)
[JetGetInstanceInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetinstanceinfo-function)
[JetOSSnapshotFreeze](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetossnapshotfreeze-function)