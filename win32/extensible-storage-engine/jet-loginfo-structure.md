# JET_LOGINFO Structure

_**Applies to:** Windows | Windows Server_

## JET_LOGINFO Structure

The **JET_LOGINFO** structure returns structured information about the set of transaction log files that should be a part of a backup file set. The **JET_LOGINFO** structure is the minimal set of information needed to represent a range of logs that is retrieved with [JetGetLogInfoInstance2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetloginfoinstance2-function) or specified for a hard recovery with [JetExternalRestore2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetexternalrestore2-function).

```cpp
typedef struct {
  unsigned long cbSize;
  unsigned long ulGenLow;
  unsigned long ulGenHigh;
  tchar szBaseName[JET_BASE_NAME_LENGTH + 1];
} JET_LOGINFO;
```

### Members

**cbSize**

The size of the structure, in bytes.

This member enables future expansion of this structure while enabling backwards compatibility. It should always be set to sizeof( JET_LOGINFO ).

**ulGenLow**

The lowest (or oldest) log file number that is restored. The full fidelity of an unsigned long should be preserved, but in current versions of the engine this number is a hexadecimal number in the range from 0x00000 to 0xFFFFF. This might change in future versions.

**ulGenHigh**

The highest (or most recent) log file number that is restored. The full fidelity of an unsigned long should be preserved, but in current versions of the engine this number is a hexadecimal number in the range from 0x00000 to 0xFFFFF. This might change in future versions.

**szBaseName**

The prefix used to name the transaction log files.

The value that is returned in this member is always equal to the setting for [JET_paramBaseName](https://learn.microsoft.com/windows/win32/extensible-storage-engine/transaction-log-parameters) for the instance that generated this information.

### Remarks

Transaction log files are named according to the instance base name and the generation number of the log file. The name is of the format BBBXXXXX.LOG. BBB corresponds to the base name for the log file and is always three characters in length. XXXXX corresponds to the generation number of the log file in zero padded hexadecimal and is always five characters in length. LOG is the file extension that is always given to transaction log files by the engine.

Use of this structured information is discouraged because it causes the application to have intimate knowledge of this naming scheme for transaction log files. If the naming scheme ever changes in the future then such an application will no longer function properly. It is conceivable that the log format will change to incorporate 8 hex digits in the future. Applications should use the explicit list of file names returned by [JetGetLogInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetloginfo-function) instead.

### Requirements

| Requirement | Value |
|------------|----------|
|

**Client**

|

Requires Windows Vista or Windows XP.

|
|

**Server**

|

Requires Windows Server 2008 or Windows Server 2003.

|
|

**Header**

|

Declared in Esent.h.

|
|

**Unicode**

|

Implemented as **JET_LOGINFO_W** (Unicode) and **JET_LOGINFO_A** (ANSI).

|

### See Also

[JetExternalRestore2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetexternalrestore2-function)
[JetGetLogInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetloginfo-function)
[JetGetLogInfoInstance2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetloginfoinstance2-function)
[System Parameters](https://learn.microsoft.com/windows/win32/extensible-storage-engine/extensible-storage-engine-system-parameters)