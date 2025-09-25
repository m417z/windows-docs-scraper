# TARGET_CHANGE_TYPE enumeration

## Description

Specifies the type of change that occurred in a target.

## Constants

### `TARGET_CHANGE_UNSPEC:0x1`

Unspecified change in the target.

### `TARGET_EXTERNALIP_CHANGED:0x2`

The target's external IP address changed.

### `TARGET_INTERNALIP_CHANGED:0x4`

The target's internal IP address changed.

### `TARGET_JOINED:0x8`

The target was reported to RD Connection Broker.

### `TARGET_REMOVED:0x10`

The target was deleted from the store in RD Connection Broker.

### `TARGET_STATE_CHANGED:0x20`

The target's state changed. To determine the current state of the target, check the [TargetState](https://learn.microsoft.com/windows/desktop/api/sbtsv/nf-sbtsv-itssbtarget-get_targetstate) property of [ITsSbTarget](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbtarget).

### `TARGET_IDLE:0x40`

The target is not hosting any sessions currently.

### `TARGET_PENDING:0x80`

### `TARGET_INUSE:0x100`

### `TARGET_PATCH_STATE_CHANGED:0x200`

### `TARGET_FARM_MEMBERSHIP_CHANGED:0x400`

## See also

[NotifyTargetChange](https://learn.microsoft.com/windows/desktop/api/sbtsv/nf-sbtsv-itssbresourcenotification-notifytargetchange)

[Remote Desktop Virtualization API reference](https://learn.microsoft.com/windows/desktop/TermServ/terminal-services-virtualization-api-reference)