## Description

The **FILE_STREAM_RESERVATION_INFORMATION** structure contains information about the reservation of space for a file stream.

## Members

### `TrackedReservation`

Amount of storage space that is currently tracked as reserved for the file stream.

### `EnforcedReservation`

Amount of storage space that is currently enforced as reserved for the file stream.

## Remarks

## See also

[**FILE_INFORMATION_CLASS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_file_information_class)

[**NtQueryInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryinformationfile)