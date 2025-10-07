# JetIdle Function

_**Applies to:** Windows | Windows Server_

## JetIdle Function

The **JetIdle** function is defunct, and should only be used for testing purposes. **JetIdle** can be used to perform idle cleanup tasks or check the version store status in ESE.

```cpp
    JET_ERR JET_API JetIdle(
      __in          JET_SESID sesid,
      __in          JET_GRBIT grbit
    );
```

### Parameters

*sesid*

The session that will be used for this call.

*grbit*

A group of bits that contain the options to be used for this call, which include zero or more of the following bits:

|

Value

|

Meaning

|
|--------------|----------------|
|

JET_bitIdleCompact

|

Triggers cleanup of the version store.

|
|

JET_bitIdleFlushBuffers

|

Reserved for future use. If this flag is specified, the API will return JET_errInvalidgrbit.

|
|

JET_bitIdleStatus

|

Returns JET_wrnIdleFull if version store is more than half full.

|

### Return Value

This function returns the [JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err) datatype with one of the following return codes. For more information about the possible ESE errors, see [Extensible Storage Engine Errors](https://learn.microsoft.com/windows/win32/extensible-storage-engine/extensible-storage-engine-errors) and [Error Handling Parameters](https://learn.microsoft.com/windows/win32/extensible-storage-engine/error-handling-parameters).

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
|

JET_errInvalidParameter

|

A *grbit* parameter that was provided to the API was not valid.

|

If this function succeeds, the appropriate operation will be triggered, or an error code indicating how full the version store is depending on the *grbit* provided.

If this function fails, the requested operation will not have completed successfully.

#### Remarks

The version store maintains ESE's snapshot isolation mechanism. If the version store is more than half full, the program might close long-running transactions. If a long-running transaction exhausts the version store, ESE will stop allowing write operations to the database.

#### Requirements

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

#### See Also

[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_GRBIT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-grbit)
[JET_SESID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-sesid)
[JetCommitTransaction](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcommittransaction-function)