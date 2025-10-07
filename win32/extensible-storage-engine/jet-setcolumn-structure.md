# JET_SETCOLUMN Structure

_**Applies to:** Windows | Windows Server_

## JET_SETCOLUMN Structure

The **JET_SETCOLUMN** structure contains input and output parameters for [JetSetColumns](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetcolumns-function). Fields in the structure describe what column value to set, how to set it, and where to get the column set data.

```cpp
    typedef struct {
      JET_COLUMNID columnid;
      const void* pvData;
      unsigned long cbData;
      JET_GRBIT grbit;
      unsigned long ibLongValue;
      unsigned long itagSequence;
      JET_ERR err;
    } JET_SETCOLUMN;
```

### Members

**columnid**

The column identifier for a column to set.

**pvData**

A pointer to data to set into a column.

**cbData**

The size of allocation, in bytes, starting at **pvData** in bytes.

**grbit**

A group of bits that contain the options to be used for this call, which include zero or more of the following.

|

Value

|

Meaning

|
|--------------|----------------|
|

JET_bitSetAppendLV

|

Appends data to a column of type [JET_coltypLongText](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269213(v=exchg.10).md) or [JET_coltypLongBinary](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269213(v=exchg.10).md). The same behavior can be achieved by determining the size of the existing long value and specifying **ibLongValue** in **psetinfo**. However, it's simpler to use this *grbit*, since knowing the size of the existing column value is not necessary.

|
|

JET_bitSetOverwriteLV

|

Replaces the existing long value with the new data. When this option is used, it is as though the existing long value has been set to 0 (zero) length prior to setting the new data.

|
|

JET_bitSetSizeLV

|

Interprets the input buffer as an integer number of bytes to set as the length of the long value described by the given columnid and if provided, the sequence number in psetinfo->itagSequence. If the size given is larger than the existing column value, the column will be extended with 0s. If the size is smaller than the existing column value then the value will be truncated.

|
|

JET_bitSetZeroLength

|

Sets a value to zero length. Normally, a column value is set to NULL by passing a cbMax of 0. However, for some types, like [JET_coltypText](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269213(v=exchg.10).md), a column value can be 0 length instead of NULL, and this option is used to differentiate between NULL and 0 length.

|
|

JET_bitSetSeparateLV

|

Forces a long value, columns of type [JET_coltypLongText](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269213(v=exchg.10).md) or [JET_coltypLongBinary](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269213(v=exchg.10).md), to be stored separately from the remainder of record data. This occurs normally when the size of the long value prevents it from being stored with remaining record data. However, this option can be used to force the long value to be stored separately. Note that long values four bytes in size or smaller cannot be forced to be separate. In such cases, the option is ignored.

|
|

JET_bitSetUniqueMultiValues

|

Enforces distinct values in a multi-valued column. This option compares the source column data, without any transformations, to other existing column values and an error is returned if a duplicate is found. If this option is given, then JET_bitSetAppendLv, JET_bitSetOverwriteLV, and JET_bitSetSizeLV cannot also be given.

|
|

JET_bitSetUniqueNormalizedMultiValues

|

Enforces distinct values in a multi-valued column. This option compares the key normalized transformation of column data to other similarly transformed existing column values and an error is returned if a duplicate is found. If this option is given, then JET_bitSetAppendLv, JET_bitSetOverwriteLV, and JET_bitSetSizeLV cannot also be given.

|
|

JET_bitSetRevertToDefaultValue

|

Causes the column to return the default column value on subsequent retrieve column operations. All existing column values are removed. This option is only applicable for tagged, sparse, or multi-valued columns.

|
|

JET_bitSetIntrinsicLV

|

Keeps the long value, columns of type [JET_coltypLongText](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269213(v=exchg.10).md) or JET_coltypeLongBinary, stored with the remaining record data if possible. Normally, long columns are stored separately when their length exceeds 1024 bytes or would otherwise cause the record length to exceed its page size related size limitation. However, if this option is set, the set column operation will fail with error JET_errColumnTooBig rather than store this column value separate from the remaining record data.

|

**ibLongValue**

The offset to the first byte to be retrieved from a column of type [JET_coltypLongBinary](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-coltyp), or [JET_coltypLongText](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-coltyp).

**itagSequence**

Describes the sequence number of value in a multi-valued column. An **itagSequence** of 0 indicates that the column value set should be added as a new instance of a multi-valued column.

**err**

Error codes and warnings returned from the set column operation.

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
[JetSetColumns](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetcolumns-function)