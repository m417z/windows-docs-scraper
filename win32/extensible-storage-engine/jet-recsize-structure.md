# JET_RECSIZE Structure

_**Applies to:** Windows | Windows Server_

## JET_RECSIZE Structure

The **JET_RECSIZE** structure is used by [JetGetRecordSize](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetrecordsize-function) to return information about a record's usage requirements in user data space, number of set columns, number of values, and ESE record structure overhead space.

**Windows Vista:** The **JET_RECSIZE** structure is introduced in Windows Vista.

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
    } JET_RECSIZE;
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

### Remarks

The total number of values in the record would be **cMultiValues** + **cNonTaggedColumns** + **cTaggedColumns**.

### Requirements

| Requirement | Value |
|------------|----------|
|

**Client**

|

Requires Windows Vista.

|
|

**Server**

|

Requires Windows Server 2008.

|
|

**Header**

|

Declared in Esent.h.

|

### See Also

[JetGetRecordSize](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetrecordsize-function)