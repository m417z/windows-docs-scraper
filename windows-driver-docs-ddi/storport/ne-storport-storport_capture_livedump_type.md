## Description

**STORPORT_CAPTURE_LIVEDUMP_TYPE** identifies the type of live dump to capture.

## Constants

### `StorportCaptureLiveDumpTypeUndefined`

Reserved for system use; do not use.

### `StorportCaptureLiveDumpTypeMini`

Capture a mini dump with the smallest set of useful information about the issue.

### `StorportCaptureLiveDumpTypeFull`

Capture a full kernel dump.

## Remarks

**STORPORT_CAPTURE_LIVEDUMP_TYPE** is a member of the[**STORPORT_CAPTURE_LIVEDUMP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-storport_capture_livedump) structure, which a miniport passes when it calls [**StorPortCaptureLiveDump**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportcapturelivedump).

## See also

[**STORPORT_CAPTURE_LIVEDUMP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-storport_capture_livedump)

[**StorPortCaptureLiveDump**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportcapturelivedump)