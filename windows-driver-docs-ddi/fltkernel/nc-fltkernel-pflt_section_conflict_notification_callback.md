# PFLT_SECTION_CONFLICT_NOTIFICATION_CALLBACK callback function

## Description

A minifilter driver can optionally register a routine of type PFLT_SECTION_CONFLICT_NOTIFICATION_CALLBACK as the minifilter driver's *SectionNotificationCallback* routine. Certain file operations are incompatible with file sections. If a minifilter provides a *SectionNotificationCallback* routine, the callback is called when section conflicts occur.

## Parameters

### `Instance` [in]

An opaque instance pointer to the minifilter driver instance that is initiating the I/O operation.

### `SectionContext` [in]

A pointer to the section context that incurred a data scan section conflict.

### `Data` [in]

A pointer to a caller-allocated structure that contains the callback data.

## Return value

This callback routine returns STATUS_SUCCESS.

## Remarks

A minifilter registers for section conflict notifications by setting a *PFLT_SECTION_CONFLICT_NOTIFICATION_CALLBACK* routine to the **SectionNotificationCallback** member of the [FLT_REGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_registration) structure when registering a minifilter driver.

Certain situations can occur where holding a section open is incompatible with current file I/O. In particular, file I/O that triggers a cache purge can cause cache incoherency if the cache purge is prevented because of an open section. A minifilter can provide this optional callback routine for notifications of these events. When a notification is received, the section can be closed to allow the conflicting I/O operation to continue.

## See also

[FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)

[FLT_REGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_registration)

[FltCreateSectionForDataScan](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatesectionfordatascan)

[FltRegisterFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltregisterfilter)