# JetPrereadKeys Function

_**Applies to:** Windows | Windows Server_

## JetPrereadKeys Function

The **JetPrereadKeys** function reads key values to improve the performance of version store cleanup.

**Windows 7: PrereadKeys** function is introduced in Windows 7.

```cpp
    JET_ERR JET_API JetPrereadKeys(
      __in JET_SESID sesid,
      __in JET_TABLEID tableid,
      __in_ecount(ckeys) const void ** rgpvKeys,
      __in_ecount(ckeys) const unsigned long * rgcbKeys,
      __in long ckeys,
      __out_opt long * pckeysPreread,
      __in JET_GRBIT grbit
     );
```

### Parameters

*sesid*

The database session context to use for the API call.

*tableid*

The cursor to use for this call.

*rgpvKeys*

An array of pointers to keys. Keys can be made with [JetMakeKey](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetmakekey-function) or retrieved with [JetGetBookmark](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetbookmark-function). The keys must be sorted in ascending or descending order, depending on the grbit passed. Keys can be sorted with memcmp.

*rgcbKeys*

An array of key lengths. rgpvKeys\[n\] should point to a key of length rgcbKeys\[n\]

*ckeys*

The number of keys. rgpvKeys and rgcbKeys must each point to an array with at least ckeys elements.

*pckeysPreread*

Returns the number of keys that prereads were actually issued for. This parameter can be NULL.

*grbit*

This must be either JET_bitPrereadForward or JET_bitPrereadBackward. If grbit is JET_bitPrereadForward, the keys must be sorted in ascending order. If grbit is JET_bitPrereadBackward, the keys must be sorted in descending order.

### Return Value

This function returns the [JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err) datatype with one of the following return codes. For more information about the possible ESE errors, see [Extensible Storage Engine Errors](https://learn.microsoft.com/windows/win32/extensible-storage-engine/extensible-storage-engine-errors) and [Error Handling Parameters](https://learn.microsoft.com/windows/win32/extensible-storage-engine/error-handling-parameters).

Various I/O errors can be returned along with these API usage errors:

|

Return code

|

Description

|
|--------------------|--------------------|
|

JET_errInvalidGrbit

|

Grbit was neither JET_bitPrereadForward nor JET_bitPrereadBackward.

|
|

JET_errInvalidBufferSize

|

An incorrect key size has been passed in. Keys can neither be 0 nor longer than the maximum key length for the table.

|
|

JET_errInvalidParameter

|

An invalid parameter has been passed in. This can be caused by a null value for a required parameter or can indicate that the key array is not sorted properly.

|

**JetPrereadKeys** traverses the internal pages of the b-tree to determine which leaf pages contain the keys specified by rgpvKeys/rgcbKeys. The list of leaf pages is sorted and then prereads are issued for the ranges of pages. The number of pages that can be preread is limited so it is possible that not all keys may be preread. In that case, the number of keys actually preread is returned in pckeysPreread.

#### Requirements

| Requirement | Value |
|------------|----------|
|

**Client**

|

Requires Windows 7.

|
|

**Server**

|

Requires Windows Server 2008 R2.

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