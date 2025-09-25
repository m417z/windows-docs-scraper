## Description

**STORPORT_LIVEDUMP_ISSUE_TYPE** identifies the issue that triggered the live dump capture.

## Constants

### `StorportLivedumpIssueTypeUndefined`

Reserved for system use; do not use.

### `StorportLivedumpIssueTypeDevicePanic`

The miniport has detected an issue that it needs to further triage.

## Remarks

**STORPORT_LIVEDUMP_ISSUE_TYPE** is a member of the[**STORPORT_CAPTURE_LIVEDUMP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-storport_capture_livedump) structure, which a miniport passes when it calls [**StorPortCaptureLiveDump**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportcapturelivedump).

## See also

[**STORPORT_CAPTURE_LIVEDUMP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-storport_capture_livedump)

[**StorPortCaptureLiveDump**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportcapturelivedump)