# JetSetCursorFilter Function

_**Applies to:** Windows | Windows Server_

The **JetSetCursorFilter** function sets an array of simple filters for the [JetMove](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetmove-function) function.

The **JetSetCursorFilter** function was introduced in the Windows 8 operating system.

``` c++
JET_ERR JET_API JetSetCursorFilter(
  __in          JET_SESID sesid,
  __in          JET_TABLEID tableid,
  __in_ecount(cFilters)  JET_INDEX_COLUMN* rgFilters,
  __in          DWORD cFilters,
  __in          JET_GRBIT grbit
);
```

### Parameters

*sesid*

The database session context to use for the API call.

*tableid*

The cursor to position.

*rgFilters*

The simple record filters.

*cFilters*

The number of filters.

*grbit*

A group of bits that specifies zero or more of the move options listed in the following table.

|

Value

|

Meaning

|
|--------------|----------------|
|

None

|

Default option.

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

[JetMove](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetmove-function)
[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)