# JET_RETRIEVECOLUMN Structure

_**Applies to:** Windows | Windows Server_

## JET_RETRIEVECOLUMN Structure

The **JET_RETRIEVECOLUMN** structure contains input and output parameters for [JetRetrieveColumns](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetretrievecolumns-function). Fields in the structure describe what column value to retrieve, how to retrieve it, and where to save results.

```cpp
    typedef struct {
      JET_COLUMNID columnid;
      void* pvData;
      unsigned long cbData;
      unsigned long cbActual;
      JET_GRBIT grbit;
      unsigned long ibLongValue;
      unsigned long itagSequence;
      JET_COLUMNID columnidNextTagged;
      JET_ERR err;
    } JET_RETRIEVECOLUMN;
```

### Members

**columnid**

The column identifier for the column to retrieve.

**pvData**

A pointer to begin storing data that is retrieved from the column value.

**cbData**

The size of allocation beginning at **pvData**, in bytes. The retrieve column operation will not store more data at **pvData** than **cbData**.

**cbActual**

The size, in bytes, of data that is retrieved by a retrieve column operation.

**grbit**

A group of bits that contain the options for column retrieval, which include zero or more of the following values.

|

Value

|

Meaning

|
|--------------|----------------|
|

JET_bitRetrieveCopy

|

Retrieves the modified value instead of the original value. If the value has not been modified, then the original value is retrieved. In this way, a value that has not yet been inserted or updated can be retrieved when a record is inserted or updated.

|
|

JET_bitRetrieveFromIndex

|

Retrieves column values from the index without accessing the record, if possible. In this way, unnecessary loading of records can be avoided when needed data is available from index entries themselves. In cases where the original column value cannot be retrieved from the index, because of irreversible transformations or data truncation, the record will be accessed and the data retrieved as normal. This is a performance option and should only be specified when it is likely that the column value can be retrieved from the index. This option should not be specified if the current index is the clustered index, since the index entries for the clustered, or primary, index are the records themselves. This bit cannot be set if JET_bitRetrieveFromPrimaryBookmark is also set.

|
|

JET_bitRetrieveFromPrimaryBookmark

|

Retrieves column values from the index bookmark, and can differ from the index value when a column appears both in the primary index and the current index. This option should not be specified if the current index is the clustered, or primary, index. This bit cannot be set if JET_bitRetrieveFromIndex is also set.

|
|

JET_bitRetrieveTag

|

Retrieves the sequence number of a multi-valued column value in pretinfo->itagSequence. The itagSequence field is often used an input for retrieving multi-valued column values from a record. However, when retrieving values from an index, it is also possible to associate the index entry with a particular sequence number and retrieve this sequence number as well. Retrieving the sequence number can be a costly operation and should only be done if necessary.

|
|

JET_ bitRetrieveNull

|

Retrieves multi-valued column NULL values. If this option is not specified, multi-valued column NULL values will automatically be skipped.

|
|

JET_bitRetrieveIgnoreDefault

|

Causes a NULL value to be returned when the requested sequence number is 1 and there are no set values for the column in the record. This option affects only multi-valued columns.

|
|

JET_bitRetrieveLongId

|

This flag is for internal use only and is not intended to be used in your application.

|
|

JET_bitRetrieveLongValueRefCount

|

This flag is for internal use only and is not intended to be used in your application.

|

**ibLongValue**

The offset to the first byte to be retrieved from a column of type [JET_coltypLongBinary](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-coltyp) or [JET_coltypLongText](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-coltyp).

**itagSequence**

The sequence number of the values that are contained in a multi-valued column. **itagSequence** here in the **JET_RETRIEVECOLUMN** can be 0. If the **itagSequence** is 0 then the number of instances of a multi-valued column are returned instead of any column data. An **itagSequence** value of 0 cannot be used in calls to [JetRetrieveColumn](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetretrievecolumn-function).

**columnidNextTagged**

The **columnid** of the tagged, multi-valued, or sparse column when all tagged columns are retrieved by passing 0 as the **columnid** to [JetRetrieveColumn](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetretrievecolumn-function).

**err**

Error codes and warnings returned from the retrieval of the column.

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
[JET_RETRIEVECOLUMN]()
[JetRetrieveColumn](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetretrievecolumn-function)
[JetRetrieveColumns](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetretrievecolumns-function)