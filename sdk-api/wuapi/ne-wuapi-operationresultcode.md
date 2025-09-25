# OperationResultCode enumeration

## Description

Defines the possible results of a download, install, uninstall, or verification operation on an update.

## Constants

### `orcNotStarted:0`

The operation is not started.

### `orcInProgress:1`

The operation is in progress.

### `orcSucceeded:2`

The operation was completed successfully.

### `orcSucceededWithErrors:3`

The operation is complete, but one or more errors occurred during the operation. The results might be incomplete.

### `orcFailed:4`

The operation failed to complete.

### `orcAborted:5`

The operation is canceled.