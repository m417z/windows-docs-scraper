# JetPrereadIndexRanges Function

_**Applies to:** Windows | Windows Server_

The **JetPrereadIndexRanges** function prereads indexes to improve the performance.

The **JetPrereadIndexRanges** function was introduced in the Windows 8 operating system.

``` c++
JET_ERR JetPrereadIndexRanges(
  __in          const JET_SESID sesid,
  __in          const JET_TABLEID tableid,
  __in_ecount(cIndexRanges)  const JET_INDEX_RANGE* const rgIndexRanges,
  __in          const unsigned long cIndexRanges,
  __out_opt     unsigned long* const pcRangesPreread,
  __in_ecount(ccolumnidPreread)  const JET_COLUMNID* const rgcolumnidPreread,
  __in          const unsigned long ccolumnidPreread,
  __in          const JET_GRBIT grbit
);
```

### Parameters

*sesid*

The database session context to use for the API call.

*tableid*

The table to issue the prereads against.

*rgIndexRanges*

The key ranges to preread.

*cIndexRanges*

The number of key ranges to preread, determined by the number of elements in *rgIndexRanges*.

*pcRangesPreread*

The number of key ranges that were actually preread.

*rgcolumnidPreread*

List of column IDs for long value columns to preread. By default, only the on-page record is preread. If Off-page long value columns need to be preread, their column IDs need to be passed via this parameter.

*ccolumnidPreread*

The number of column IDs for long value columns to preread, determined by the number of elements in *rgcolumnidPreread*.

*grbit*

A group of bits that specifies zero or more of the preread direction values listed in the following table.

|

Value

|

Meaning

|
|--------------|----------------|
|

Forward

|

Preread forward.

|
|

Backwards

|

Preread backward.

|
|

FirstPageOnly

|

Preread only the first page of any long column.

|
|

NormalizedKey

|

Normalized key/bookmark provided instead of column value.

|

### Return value

This function returns the [JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err) data type with one of the return codes listed in the following table. For more information about the possible Extensible Storage Engine (ESE) errors, see [Extensible Storage Engine Errors](https://learn.microsoft.com/windows/win32/extensible-storage-engine/extensible-storage-engine-errors) and [Error Handling Parameters](https://learn.microsoft.com/windows/win32/extensible-storage-engine/error-handling-parameters).

|

Return code

|

Description

|
|--------------------|--------------------|
|

JET_errSuccess

|

The operation completed successfully.

|

#### Remarks

If the records with the specified key ranges are not in the buffer cache, you should start asynchronous reads to bring the records into the database buffer cache.

#### Requirements

| Requirement | Value |
|------------|----------|
|

**Client**

|

Requires Windows 8.

|
|

**Server**

|

Requires Windows Server 2012.

|
|

**Header**

|

Declared in Esent.h.

|
|

**Library**

|

Use ESENT.lib.

|
|

**DLL**

|

Requires ESENT.dll.

|

#### See also

[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)