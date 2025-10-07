# JetConfigureProcessForCrashDump Function

_**Applies to:** Windows | Windows Server_

## JetConfigureProcessForCrashDump Function

The **JetConfigureProcessForCrashDump** function configures crash dump options for Watson..

```cpp
    JET_ERR JET_API JetConfigureProcessForCrashDump(
    _In_ const JET_GRBIT grbit )
```

### Parameters

*grbit*

A [JET_GRBIT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-grbit) representing crash dump options.

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

JET_errInternalError

|

An internal error occured

|

#### Remarks

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