# JET_RETINFO Structure

_**Applies to:** Windows | Windows Server_

## JET_RETINFO Structure

The **JET_RETINFO** structure contains optional input and output parameters for [JetRetrieveColumn](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetretrievecolumn-function). A null pointer can be passed where a pointer to this structure would otherwise be passed. Passing a null pointer is the same as passing **JET_RETINFO** with **cbStruct** set to sizeof(JET_RETINFO), **ibLongValue** set to 0 (zero) and **itagSequence** set to 1.

```cpp
    typedef struct {
      unsigned long cbStruct;
      unsigned long ibLongValue;
      unsigned long itagSequence;
      JET_COLUMNID columnidNextTagged;
    } JET_RETINFO;
```

### Members

**cbStruct**

Must be set to the size of the **JET_RETINFO** structure, in bytes, and serves to confirm the presence of the following fields.

**ibLongValue**

The offset to the first byte to be retrieved from a column of type [JET_coltypLongBinary](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-coltyp), or [JET_coltypLongText](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-coltyp). Note that the amount of data retrieved from this offset is the lower of the size of the output buffer and the size of data in the actual value after this offset.

**itagSequence**

Describes the sequence number of value in a multi-valued column. Note that the array of values is one-based. The first value is sequence 1, not 0. If the record column has only one value then 1 should be passed as the **itagSequence**

With a column that can contain multiple values, it is only possible to use a sequence number larger than 1 in [JetSetColumn](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetcolumn-function) and [JetRetrieveColumn](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetretrievecolumn-function) or 0 in [JetSetColumn](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetcolumn-function). In the current implementation of the engine, any column that was created with JET_bitColumnTagged can contain multiple values. Columns created with JET_bitColumnMultiValued differ from multi-valued tagged columns only in the way that they are indexed. See [JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-indexcreate-structure) for more information.

**columnidNextTagged**

Returns the columnid of the retrieved tagged, multi-valued or sparse, column when all tagged columns are retrieved by passing 0 as the columnid to [JetRetrieveColumn](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetretrievecolumn-function).

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
[JET_RETINFO]()
[JetRetrieveColumn](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetretrievecolumn-function)