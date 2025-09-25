# SYNCMGR_CANCEL_REQUEST enumeration

## Description

Describes a request by the user to cancel a synchronization.

## Constants

### `SYNCMGR_CR_NONE:0`

No cancelation request has been made.

### `SYNCMGR_CR_CANCEL_ITEM:1`

Stop the synchronization of the current item, but continue the synchronization of other items.

### `SYNCMGR_CR_CANCEL_ALL:2`

Stop the synchronization entirely.

### `SYNCMGR_CR_MAX`

The maximum valid [SYNCMGR_CANCEL_REQUEST](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_cancel_request) value.