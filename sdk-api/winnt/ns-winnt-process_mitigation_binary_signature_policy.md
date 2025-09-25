# PROCESS_MITIGATION_BINARY_SIGNATURE_POLICY structure

## Description

Contains process mitigation policy settings for the loading of images depending on the signatures for the image.

## Members

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.Flags`

Reserved for system use.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.MicrosoftSignedOnly`

Set (0x1) to prevent the process from loading images that are not signed by Microsoft; otherwise leave unset (0x0).

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.StoreSignedOnly`

Set (0x1) to prevent the process from loading images that are not signed by the Windows Store; otherwise leave unset (0x0).

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.MitigationOptIn`

Set (0x1) to prevent the process from loading images that are not signed by Microsoft, the Windows Store and the Windows Hardware Quality Labs (WHQL); otherwise leave unset (0x0).

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.AuditMicrosoftSignedOnly`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.AuditStoreSignedOnly`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.ReservedFlags`

Reserved for system use.

## See also

[GetProcessMitigationPolicy](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getprocessmitigationpolicy)

[SetProcessMitigationPolicy](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setprocessmitigationpolicy)