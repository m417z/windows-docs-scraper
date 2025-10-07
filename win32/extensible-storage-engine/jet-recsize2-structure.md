# JET_RECSIZE2 Structure

_**Applies to:** Windows | Windows Server_

## JET_RECSIZE2 Structure

The **JET_RECSIZE2** structure is used by [JetGetRecordSize2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetrecordsize2-function) to return information about a record's usage requirements in user data space, number of set columns, number of values, and ESE record structure overhead space.

**Windows 7:** The **JET_RECSIZE2** structure is introduced in the Windows 7 operating system.

```cpp
    typedef struct {
      unsigned __int64 cbData;
      unsigned __int64 cbLongValueData;
      unsigned __int64 cbOverhead;
      unsigned __int64 cbLongValueOverhead;
      unsigned __int64 cNonTaggedColumns;
      unsigned __int64 cTaggedColumns;
      unsigned __int64 cLongValues;
      unsigned __int64 cMultiValues;
      unsigned __int64 cCompressedColumns;
      unsigned __int64 cbDataCompressed;
      unsigned __int64 cbLongValueDataCompressed;
    } JET_RECSIZE2;
```

### Members

**cbData**

User data set in the record.

**Note** The key size is not included in this.

**cbLongValueData**

User data associated with the record but stored in the long-value tree.

**Note** This does not count intrinsic long-values.

**cbOverhead**

The overhead of the ESE record structure for this record. This includes the record's key size.

**cbLongValueOverhead**

The overhead of the long-value data.

**Note** This does not count intrinsic long-values.

**cNonTaggedColumns**

Total number of fixed and variable columns set in this record.

**cTaggedColumns**

Total number of tagged columns set in this record.

**cLongValues**

Total number of long values stored in the long-value tree for this record.

**Note** This does not count intrinsic long-values.

**cMultiValues**

The accumulation of the total number of values beyond the first for all columns in the record.

**cCompressedColumns**

The total number of compressed columns.

**cbDataCompressed**

The compressed size of user data in this record. This is the same as cbData if no intrinsic long-values are compressed.

**cbLongValueDataCompressed**

The compressed size of user data in the long-value tree. This is the same as cbLongValue data if no separated long values are compressed.

### Remarks

The total number of values in the record would be **cMultiValues** + **cNonTaggedColumns** + **cTaggedColumns**.

The logical data in the record is (cbData+cbLongValueData) and the physical size of the data is (cbDataCompressed+cbLongValueDataCompressed). This can be used to calculate the compression ratio of stored data.

### Requirements

| Requirement | Value |
|------------|----------|
|

**Client**

|

Requires Windows Vista operating system.

|
|

**Server**

|

Requires Windows Server 2008 operating system.

|
|

**Header**

|

Declared in Esent.h.

|

### See Also

[JetGetRecordSize](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetrecordsize-function)
[JetGetRecordSize2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetrecordsize2-function)