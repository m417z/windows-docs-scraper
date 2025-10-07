# JET_OBJECTINFO Structure

_**Applies to:** Windows | Windows Server_

## JET_OBJECTINFO Structure

The **JET_OBJECTINFO** structure holds information about an object. Tables are the only object types that are currently supported.

```cpp
    typedef struct {
      unsigned long cbStruct;
      JET_OBJTYP objtyp;
      JET_DATESERIAL dtCreate;
      JET_DATESERIAL dtUpdate;
      JET_GRBIT grbit;
      unsigned long flags;
      unsigned long cRecord;
      unsigned long cPage;
    } JET_OBJECTINFO;
```

### Members

**cbStruct**

The size, in bytes, of the **JET_OBJECTINFO** structure.

**objtyp**

Holds the [JET_OBJTYP](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-objtyp) of the structure. Currently only tables will be returned (that is, JET_objtypTable).

**dtCreate**

Obsolete. Do not use.

**dtUpdate**

Obsolete. Do not use.

**grbit**

A group of bits that contain the options that are available for this call, which include zero or more of the following.

|

Value

|

Meaning

|
|--------------|----------------|
|

JET_bitTableInfoBookmark

|

The table can have bookmarks.

|
|

JET_bitTableInfoRollback

|

The table can be rolled back.

|
|

JET_bitTableInfoUpdatable

|

The table can be updated.

|

**flags**

A bit field that contains zero or more of the following flags.

|

Value

|

Meaning

|
|--------------|----------------|
|

JET_bitObjectSystem

|

The table is a System Table and is for internal use only.

|
|

JET_bitObjectTableDerived

|

The table inherited DDL from a template table.

|
|

JET_bitObjectTableFixedDDL

|

The DDL for the table cannot be modified.

|
|

JET_bitObjectTableNoFixedVarColumnsInDerivedTables

|

Used in conjunction with JET_bitObjectTableTemplate to disallow fixed or variable columns in derived tables (so that fixed or variable columns can be added to the template in the future).

**Windows XP:** This value is introduced in Windows XP.

|
|

JET_bitObjectTableTemplate

|

The table is a template table.

|

**cRecord**

The number of records in the table.

This value is retrieved only if **JET_OBJECTINFO** was passed to [JetGetObjectInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetobjectinfo-function).

**cPage**

The number of pages that are being used by the table.

This value is retrieved only if **JET_OBJECTINFO** was passed to [JetGetObjectInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetobjectinfo-function).

### Remarks

A **JET_OBJECTINFO** structure gets populated by a call to [JetGetObjectInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetobjectinfo-function) or [JetGetTableInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgettableinfo-function). If the API call does not succeed, the contents of the structure are undefined.

If applicable, the table statistics include the number of records and the number of pages that are in the clustered index (that is, the index containing the record data). The index statistics are accessed separately by name, using [JetGetIndexInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetindexinfo-function) or [JetGetTableIndexInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgettableindexinfo-function).

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
[JET_OBJTYP](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-objtyp)
[JET_SESID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-sesid)
[JET_TABLEID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tableid)
[JetGetIndexInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetindexinfo-function)
[JetGetObjectInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetobjectinfo-function)
[JetGetTableIndexInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgettableindexinfo-function)
[JetGetTableInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgettableinfo-function)