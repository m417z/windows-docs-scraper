# JET_SETINFO Structure

_**Applies to:** Windows | Windows Server_

## JET_SETINFO Structure

The **JET_SETINFO** structure contains optional input parameters for [JetSetColumn](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetcolumn-function). A **NULL** pointer can be passed where a pointer to this structure would otherwise be passed. The meaning of passing a **NULL** is the same as passing **JET_SETINFO** with **cbStruct** set to sizeof(JET_SETINFO), **ibLongValue** set to 0 (zero) and **itagSequence** set to 1.

```cpp
typedef struct {
  unsigned long cbStruct;
  unsigned long ibLongValue;
  unsigned long itagSequence;
} JET_SETINFO;
```

### Members

**cbStruct**

The size, in bytes, of the **JET_SETINFO**. This value confirms the presence of the following fields.

**ibLongValue**

The offset to the first byte to be set in a column of type [JET_coltypLongBinary](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-coltyp) or [JET_coltypLongText](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-coltyp).

**itagSequence**

Describes the sequence number of value in a multi-valued column to be set. The array of values is one-based. The first value is sequence 1, not 0 (zero). If the record column has only one value then 1 should be passed as the **itagSequence** if that value is being replaced. A value of 0 (zero) means to add a new column value instance to the end of the sequence of column values.

With a column that can contain multiple values, it is only possible to use a sequence number larger than 1 in [JetSetColumn](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetcolumn-function) and [JetRetrieveColumn](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetretrievecolumn-function) or 0 in [JetSetColumn](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetcolumn-function). In the current implementation of the engine, any column that was created with JET_bitColumnTagged can contain multiple values. Columns created with JET_bitColumnMultiValued differ from multi-valued tagged columns only in the way that they are indexed. See [JET_INDEXCREATE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-indexcreate-structure) for more information.

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

[JetSetColumn](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetcolumn-function)