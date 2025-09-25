# REPAIR_RISK enumeration

## Description

The **REPAIR_RISK** enumeration specifies whether repair changes are persistent and whether they can be undone.

## Constants

### `RR_NOROLLBACK:0`

The repair performs persistent changes that cannot be undone.

### `RR_ROLLBACK`

The repair performs persistent changes that can be undone.

### `RR_NORISK`

The repair does not perform persistent changes.