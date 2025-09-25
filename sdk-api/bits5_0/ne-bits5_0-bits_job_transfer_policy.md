# BITS_JOB_TRANSFER_POLICY enumeration

## Description

Defines constants that specify ID values corresponding to BITS properties.

## Constants

### `BITS_JOB_TRANSFER_POLICY_ALWAYS:0x800000ff`

Specifies that the job will be transferred when connectivity is available, regardless of the cost.

### `BITS_JOB_TRANSFER_POLICY_NOT_ROAMING:0x8000007f`

Specifies that the job will be transferred when connectivity is available, unless that connectivity is subject to roaming surcharges.

### `BITS_JOB_TRANSFER_POLICY_NO_SURCHARGE:0x8000006f`

Specifies that the job will be transferred only when connectivity is available which is not subject to a surcharge.

### `BITS_JOB_TRANSFER_POLICY_STANDARD:0x80000067`

Specifies that the job will be transferred only when connectivity is available which is neither subject to a surcharge nor near exhaustion.

### `BITS_JOB_TRANSFER_POLICY_UNRESTRICTED:0x80000021`

Specifies that the job will be transferred only when connectivity is available which does not impose costs or traffic limits.