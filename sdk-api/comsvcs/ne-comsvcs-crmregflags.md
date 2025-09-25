# CRMREGFLAGS enumeration

## Description

Controls which phases of transaction completion should be received by the CRM compensator and whether recovery should fail if in-doubt transactions remain after recovery has been attempted.

## Constants

### `CRMREGFLAG_PREPAREPHASE:0x1`

Receive the prepare phase.

### `CRMREGFLAG_COMMITPHASE:0x2`

Receive the commit phase.

### `CRMREGFLAG_ABORTPHASE:0x4`

Receive the abort phase.

### `CRMREGFLAG_ALLPHASES:0x7`

Receive all phases.

### `CRMREGFLAG_FAILIFINDOUBTSREMAIN:0x10`

Fail if in-doubt transactions remain after recovery.

## See also

[ICrmLogControl::RegisterCompensator](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-icrmlogcontrol-registercompensator)