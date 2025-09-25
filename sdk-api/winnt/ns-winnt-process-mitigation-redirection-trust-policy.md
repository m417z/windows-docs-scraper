# PROCESS_MITIGATION_REDIRECTION_TRUST_POLICY structure

## Description

Contains process mitigation policy settings for RedirectionGuard.

## Members

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.Flags`

Reserved for system use.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.EnforceRedirectionTrust`

Set (0x1) to prevent the process from following filesystem junctions created by non-admin users and log the attempt; otherwise leave unset (0x0).

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.AuditRedirectionTrust`

Set (0x1) to log when the process follows filesystem junctions created by non-admin users, but still allow the operation; otherwise leave unset (0x0).

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.ReservedFlags`

Reserved for system use.

## Remarks

The [GetProcessMitigationPolicy](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-getprocessmitigationpolicy) and [SetProcessMitigationPolicy](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-setprocessmitigationpolicy) functions use this structure.

## See also