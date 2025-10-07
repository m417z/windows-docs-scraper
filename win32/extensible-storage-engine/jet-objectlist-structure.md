# JET_OBJECTLIST Structure

_**Applies to:** Windows | Windows Server_

## JET_OBJECTLIST Structure

The **JET_OBJECTLIST** structure traverses a temporary table that was created with [JetGetObjectInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetobjectinfo-function). Each row in the temporary table describes an object in the database.

```cpp
    typedef struct {
      unsigned long cbStruct;
      JET_TABLEID tableid;
      unsigned long cRecord;
      JET_COLUMNID columnidcontainername;
      JET_COLUMNID columnidobjectname;
      JET_COLUMNID columnidobjtyp;
      JET_COLUMNID columniddtCreate;
      JET_COLUMNID columniddtUpdate;
      JET_COLUMNID columnidgrbit;
      JET_COLUMNID columnidflags;
      JET_COLUMNID columnidcRecord;
      JET_COLUMNID columnidcPage;
    } JET_OBJECTLIST;
```

### Members

**cbStruct**

The size of the structure, in bytes. The API call will update this field, so the caller should ensure that this value matches sizeof( JET_INDEXLIST ).

**tableid**

The table identifier of the temporary table that was created. The caller must contain code that will close the table.

**cRecord**

The number of records in the temporary table that was created.

**columnidcontainername**

The column identifier of the name of the type of container.

The only containers that are currently supported are tables. This column is a [JET_coltypText](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-coltyp).

**columnidobjectname**

The column identifier of the name of the object.

This column is a [JET_coltypText](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-coltyp).

**columnidobjtyp**

The column identifier of the type of the object. The only containers that are currently supported are tables, so this field will be JET_objtypTable.

This column is a [JET_coltypLong](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-coltyp).

**columniddtCreate**

Obsolete. Do not use.

**columniddtUpdate**

Obsolete. Do not use.

**columnidgrbit**

The column identifier of the **grbits** that are applicable to the object. For a list of applicable **grbits**, see [JET_TABLECREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tablecreate-structure).

This column is a [JET_coltypLong](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-coltyp).

**columnidflags**

The column identifier of the flags that are applicable to the object. For a list of applicable flags, see [JET_OBJECTINFO](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-objectinfo-structure).

This column is a [JET_coltypLong](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-coltyp).

**columnidcRecord**

The column identifier of the number of records that are present in the table that is named in **columnidobjectname**.

This column is a [JET_coltypLong](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-coltyp).

**columnidcPage**

The column identifier of the number of pages the object uses.

This column is a [JET_coltypLong](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-coltyp).

### Remarks

Each row in the temporary table corresponds to an object in the database.

When the temporary table is created with the *InfoLevel* parameter in the [JetGetObjectInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetobjectinfo-function) function set to JET_ObjInfoListNoStats, the columns identified by **columnidcRecord** and **columnidcPage** will not contain meaningful information.

Currently, only information about tables will be in the temporary table.

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

[JET_COLTYP](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-coltyp)
[JET_COLUMNID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-columnid)
[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_GRBIT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-grbit)
[JET_SESID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-sesid)
[JET_TABLEID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tableid)
[JET_OBJECTINFO](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-objectinfo-structure)
[JET_TABLECREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tablecreate-structure)
[JetGetObjectInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetobjectinfo-function)