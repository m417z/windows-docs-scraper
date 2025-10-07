# JET_DBINFOMISC3 Structure

_**Applies to:** Windows | Windows Server_

## JET_DBINFOMISC3 Structure

The **JET_DBINFOMISC3** structure holds miscellaneous information about a database. This is the information that is contained in the database header.

```cpp
    typedef struct {
      unsigned long ulVersion;
      unsigned long ulUpdate;
      JET_SIGNATURE signDb;
      unsigned long dbstate;
      JET_LGPOS lgposConsistent;
      JET_LOGTIME logtimeConsistent;
      JET_LOGTIME logtimeAttach;
      JET_LGPOS lgposAttach;
      JET_LOGTIME logtimeDetach;
      JET_LGPOS lgposDetach;
      JET_SIGNATURE signLog;
      JET_BKINFO bkinfoFullPrev;
      JET_BKINFO bkinfoIncPrev;
      JET_BKINFO bkinfoFullCur;
      unsigned long fShadowingDisabled;
      unsigned long fUpgradeDb;
      unsigned long dwMajorVersion;
      unsigned long dwMinorVersion;
      unsigned long dwBuildNumber;
      long lSPNumber;
      unsigned long cbPageSize;
      unsigned long genMinRequired;
      unsigned long genMaxRequired;
      JET_LOGTIME logtimeGenMaxCreate;
      unsigned long ulRepairCount;
      JET_LOGTIME logtimeRepair;
      unsigned long ulRepairCountOld;
      unsigned long ulECCFixSuccess;
      JET_LOGTIME logtimeECCFixSuccess;
      unsigned long ulECCFixSuccessOld;
      unsigned long ulECCFixFail;
      JET_LOGTIME logtimeECCFixFail;
      unsigned long ulECCFixFailOld;
      unsigned long ulBadChecksum;
      JET_LOGTIME logtimeBadChecksum;
      unsigned long ulBadChecksumOld;
      unsigned long genCommitted;
    } JET_DBINFOMISC3;
```

### Members

**ulVersion**

The native version of the database engine that created the database. See [JetGetVersion](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetversion-function) to retrieve the native version for the current database engine.

**ulUpdate**

Tracks incremental database format updates that are backward compatible.

|

ulVersion, ulUpdate =

|

Meaning

|
|------------------------------|----------------|
|

0x620,0

|

Original operating system Beta format (4/22/97).

|
|

0x620,1

|

Add columns in the catalog for conditional indexing and OLD (5/29/97).

|
|

0x620,2

|

Add the fLocalizedText flag in IDB (6/5/97).

|
|

0x620,3

|

Add SPLIT_BUFFER to space tree root pages (10/30/97).

|
|

0x620,2

|

Revert revision in order for ESE97 to remain forward-compatible (1/28/98).

|
|

0x620,3

|

Add new tagged columns to catalog ("CallbackData" and "CallbackDependencies").

|
|

0x620,4

|

SLV support: signSLV, fSLVExists in db header (5/5/98).

|
|

0x620,5

|

New SLV space tree (5/29/98).

|
|

0x620,6

|

SLV space map (10/12/98).

|
|

0x620,7

|

4-byte IDXSEG (12/10/98).

|
|

0x620,8

|

New template column format (1/25/99).

|
|

0x620,9

|

Sorted template columns (6/24/99).

|
|

0x620,A

|

Merged code base (3/26/2003).

|
|

0x620,B

|

New checksum format (1/08/2004).

|
|

0x620,C

|

Increased max key length to 1000/2000 bytes for 4/8kb pages (1/15/2004).

|
|

0x620,D

|

Catalog space hints, space_header.v2 (7/15/2007).

|
|

0x620,E

|

Add new node/extent format to space manager, use it for reserved pools of space (8/9/2007).

|
|

0x620,F

|

Compression for intrinsic long-values (10/30/2007).

|
|

0x620,10

|

Compression for separated long-values (12/05/2007).

|
|

0x620,11

|

New LV chunk size for large pages (12/29/2007).

|

**signDb**

Signature of the database (including creation time). This structure is 28 bytes.

**dbstate**

This is the database state.

The following options are available for this member.

|

Value

|

Meaning

|
|--------------|----------------|
|

JET_dbstateJustCreated\
1

|

The database was just created.

|
|

JET_dbstateDirtyShutdown\
2

|

The database requires hard or soft recovery to be run in order to become usable or moveable. One should not try to move databases in this state.

|
|

JET_dbstateCleanShutdown\
3

|

The database is in a clean state. The database can be attached without any log files.

|
|

JET_dbstateBeingConverted\
4

|

The database is being upgraded.

|
|

JET_dbstateForceDetach\
5

|

Internal.

|

**lgposConsistent**

Null if the database is in a dirty state. This is the log position that was used when the database was last brought to a clean shutdown state.

**logtimeConsistent**

Null if the database is in a dirty state. This is the time when the database was last brought to a clean shutdown state.

**logtimeAttach**

The time when the database was last attached with [JetAttachDatabase](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetattachdatabase-function).

**lgposAttach**

The log position that was used the last time the database was attached with [JetAttachDatabase](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetattachdatabase-function).

**logtimeDetach**

The time when the database was last detached with [JetDetachDatabase](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetdetachdatabase-function).

**lgposDetach**

The log position that was used the last time the database was detached with [JetDetachDatabase](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetdetachdatabase-function).

**signLog**

Supports the ESE infrastructure and cannot be used in your code.

**bkinfoFullPrev**

Supports the ESE infrastructure and cannot be used in your code.

**bkinfoIncPrev**

Supports the ESE infrastructure and cannot be used in your code.

**bkinfoFullCur**

Supports the ESE infrastructure and cannot be used in your code.

**fShadowingDisabled**

Supports the ESE infrastructure and cannot be used in your code.

**fUpgradeDb**

Supports the ESE infrastructure and cannot be used in your code.

**dwMajorVersion**

Represents the Windows NT version numbers when the databases indexes were updated. Used for updating indexes.

**dwMinorVersion**

Represents the Windows NT version numbers when the databases indexes were updated. Used for updating indexes.

**dwBuildNumber**

Represents the Windows NT version numbers when the databases indexes were updated. Used for updating indexes.

**lSPNumber**

Represents the Windows NT version numbers when the databases indexes were updated. Used for updating indexes.

**cbPageSize**

Database page size. 0 means the page size is 4 KB.

This value is retrieved only if JET_DbInfoMisc was passed to [JetGetDatabaseInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetdatabaseinfo-function) or [JetGetDatabaseFileInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetdatabasefileinfo-function).

**genMinRequired**

Represents the minimum log generation required for replaying the logs. This is typically the same as the checkpoint generation.

**genMaxRequired**

Represents the maximum log generation required for replaying the logs.

**logtimeGenMaxCreate**

Represents the creation date and time of the genMax log file.

**ulRepairCount**

The number of times a repair has been called on this database.

**logtimeRepair**

Represents the date and time the last repair was run.

**ulRepairCountOld**

The number of times the repair had been run on this database before the last defragmentation.

**ulECCFixSuccess**

The number of times a one bit error was fixed and resulted in a good page.

**logtimeECCFixSuccess**

Represents the date and time the last one bit error was fixed and resulted in a good page.

**ulECCFixSuccessOld**

Represents the number of times a one bit error was fixed and resulted in a good page before last repair.

**ulECCFixFail**

The number of times a one bit error was fixed and resulted in a bad page.

**logtimeECCFixFail**

Represents the date and time the last one bit error was fixed and resulted in a bad page.

**ulECCFixFailOld**

The number of times a one bit error was fixed and resulted in a bad page before last repair.

**ulBadChecksum**

The number of times a non-correctable ECC/checksum error was found.

**logtimeBadChecksum**

Represents the date and time the last non-correctable ECC/checksum error was found.

**ulBadChecksumOld**

The number of times a non-correctable ECC/checksum error was found before last repair.

**genCommitted**

The current log generation. This can be less than genMaxRequired if JET_paramWaypointLatency is non-zero.

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

[JET_BKINFO](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-bkinfo-structure)
[JET_LOGTIME](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-logtime-structure)
[JET_LGPOS](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-lgpos-structure)
[JET_SIGNATURE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-signature-structure)
[JetGetDatabaseInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetdatabaseinfo-function)
[JetGetDatabaseFileInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetdatabasefileinfo-function)