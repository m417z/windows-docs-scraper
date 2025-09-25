## Description

The **RKF_BYPASS_ECP_CONTEXT** structure contains the extra create parameter (ECP) context for the Resume Key Filter (RKF) for an RKF bypass handle.

## Members

### `Reserved`

Reserved for future use. Must be set to zero.

### `Version`

The version of the ECP context (this structure). Must be initialized to zero.

## Remarks

The value GUID_ECP_RKF_BYPASS is used when calling support routines such as [**FltAllocateExtraCreateParameter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocateextracreateparameter) and [**FsRtlRemoveExtraCreateParameter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlremoveextracreateparameter).

See [Introduction to extra create parameters](https://learn.microsoft.com/windows-hardware/drivers/ifs/introduction-to-extra-create-parameters) for more information.