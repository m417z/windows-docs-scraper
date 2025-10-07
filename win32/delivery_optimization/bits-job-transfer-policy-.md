# BITS_JOB_TRANSFER_POLICY enumeration

The **BITS_JOB_TRANSFER_POLICY** enumeration defines ID values corresponding to Delivery Optimization properties.

## Constants

**BITS_JOB_TRANSFER_POLICY_ALWAYS**

Specifies that the job will be transferred when connectivity is available, regardless of the cost.

**BITS_JOB_TRANSFER_POLICY_NOT_ROAMING**

Specifies that the job will be transferred when connectivity is available, unless that connectivity is subject to roaming surcharges.

**BITS_JOB_TRANSFER_POLICY_NO_SURCHARGE**

Specifies that the job will be transferred only when connectivity is available which is not subject to a surcharge.

**BITS_JOB_TRANSFER_POLICY_STANDARD**

Specifies that the job will be transferred only when connectivity is available which is neither subject to a surcharge nor near exhaustion.

**BITS_JOB_TRANSFER_POLICY_UNRESTRICTED**

Specifies that the job will be transferred only when connectivity is available which does not impose costs or traffic limits.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 10, version 1709 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server, version 1709 \[desktop apps only\]<br> |
| Header<br> | Deliveryoptimization.h |

