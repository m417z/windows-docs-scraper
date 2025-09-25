# DIAGNOSIS_STATUS enumeration

## Description

The **DIAGNOSIS_STATUS** enumeration describes the result of a hypothesis submitted to a helper class in which the health of a component has been determined.

## Constants

### `DS_NOT_IMPLEMENTED:0`

A helper class is not implemented

### `DS_CONFIRMED`

The helper class has confirmed a problem existing in its component.

### `DS_REJECTED`

The helper class has determined that no problem exists.

### `DS_INDETERMINATE`

The helper class is unable to determine whether there is a problem.

### `DS_DEFERRED`

The helper class is unable to perform the diagnosis at this time.

### `DS_PASSTHROUGH`

The helper class has identified hypotheses to investigate further, but did not identify any problems in its own component.

Equivalent to **DS_INDETERMINATE**, but is later updated to **DS_REJECTED** if no hypothesis is confirmed.

**Note** Available only in Windows 7, Windows Server 2008 R2, and later.