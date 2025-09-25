# FltGetVolumeFromName function

## Description

The **FltGetVolumeFromName** routine returns an opaque pointer for the volume whose name matches the value of the **VolumeName** parameter.

## Parameters

### `Filter` [in]

Opaque filter pointer for the caller. This parameter is required and cannot be **NULL**.

### `VolumeName` [in]

Pointer to a [**UNICODE_STRING**](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that contains the volume name (for example, "\Device\HarddiskVolume1", "\DosDevices\D:", "\\??\D:", or "D:"). This parameter is required and cannot be **NULL**.

### `RetVolume` [out]

Pointer to a caller-allocated variable that receives an opaque pointer for the volume. This parameter is required and cannot be **NULL**.

## Return value

**FltGetVolumeFromName** returns STATUS_SUCCESS or an appropriate NTSTATUS value, such as one of the following:

| Return code | Description |
| ----------- | ----------- |
| STATUS_ACCESS_DENIED | The caller did not have FILE_READ_DATA access to the volume. This is an error code. |
| STATUS_FLT_DELETING_OBJECT | The volume is being torn down. This is an error code. |
| STATUS_INVALID_PARAMETER | An invalid value was specified for the **VolumeName** parameter. This is an error code. |
| STATUS_FLT_VOLUME_NOT_FOUND | No matching volume was found. This is an error code. |

## Remarks

**FltGetVolumeFromName** searches the Filter Manager's global list of volumes for a volume whose name matches **VolumeName**. The caller must have FILE_READ_DATA access to the volume. To locate the volume structure, **FltGetVolumeFromName** must first open the volume.

**FltGetVolumeFromName** adds a rundown reference to the opaque volume pointer returned in the **RetVolume** parameter. When this pointer is no longer needed, the caller must release it by calling [**FltObjectDereference**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltobjectdereference). Thus every successful call to **FltGetVolumeFromName** must be matched by a subsequent call to **FltObjectDereference**.

To get the volume name for a given volume, call [**FltGetVolumeName**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetvolumename).

To get the volume GUID name for a given volume, call [**FltGetVolumeGuidName**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetvolumeguidname).

## See also

[**FltGetFilterFromName**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetfilterfromname)

[**FltGetVolumeGuidName**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetvolumeguidname)

[**FltGetVolumeInstanceFromName**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetvolumeinstancefromname)

[**FltGetVolumeName**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetvolumename)

[**FltObjectDereference**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltobjectdereference)

[**UNICODE_STRING**](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)