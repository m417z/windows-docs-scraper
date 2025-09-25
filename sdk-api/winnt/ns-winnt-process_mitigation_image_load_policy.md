# PROCESS_MITIGATION_IMAGE_LOAD_POLICY structure

## Description

Contains process mitigation policy settings for the loading of images from a remote device.

## Members

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.Flags`

Reserved for system use.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.NoRemoteImages`

Set (0x1) to prevent the process from loading images from a remote device, such as a UNC share; otherwise leave unset (0x0).

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.NoLowMandatoryLabelImages`

Set (0x1) to prevent the process from loading images that have a Low mandatory label, as written by low IL; otherwise leave unset (0x0).

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.PreferSystem32Images`

Set (0x1) to search for images to load in the System32 subfolder of the folder in which Windows is installed first, then in the application directory in the standard DLL search order; otherwise leave unset (0x0).

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.AuditNoRemoteImages`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.AuditNoLowMandatoryLabelImages`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.ReservedFlags`

Reserved for system use.

## See also

[GetProcessMitigationPolicy](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getprocessmitigationpolicy)

[SetProcessMitigationPolicy](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setprocessmitigationpolicy)