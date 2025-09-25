# CRMFLAGS enumeration

## Description

Provides information about when a particular log record to the CRM compensator was written.

## Constants

### `CRMFLAG_FORGETTARGET:0x1`

### `CRMFLAG_WRITTENDURINGPREPARE:0x2`

The record was written during prepare.

### `CRMFLAG_WRITTENDURINGCOMMIT:0x4`

The record was written during commit.

### `CRMFLAG_WRITTENDURINGABORT:0x8`

The record was written during abort.

### `CRMFLAG_WRITTENDURINGRECOVERY:0x10`

The record was written during recovery.

### `CRMFLAG_WRITTENDURINGREPLAY:0x20`

The record was written during replay.

### `CRMFLAG_REPLAYINPROGRESS:0x40`

## See also

[CrmLogRecordRead](https://learn.microsoft.com/windows/desktop/api/comsvcs/ns-comsvcs-crmlogrecordread)