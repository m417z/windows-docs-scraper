# PDOPSTATUS enumeration

## Description

Provides operation status flags.

## Constants

### `PDOPS_RUNNING:1`

Operation is running, no user intervention.

### `PDOPS_PAUSED:2`

Operation has been paused by the user.

### `PDOPS_CANCELLED:3`

Operation has been canceled by the user - now go undo.

### `PDOPS_STOPPED:4`

Operation has been stopped by the user - terminate completely.

### `PDOPS_ERRORS:5`

Operation has gone as far as it can go without throwing error dialogs.