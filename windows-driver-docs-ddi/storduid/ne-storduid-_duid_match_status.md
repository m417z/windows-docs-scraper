# _DUID_MATCH_STATUS enumeration

## Description

The DUID_MATCH_STATUS enumeration lists the status values that the [CompareStorageDuids](https://learn.microsoft.com/windows-hardware/drivers/ddi/storduid/nf-storduid-comparestorageduids) routine returns.

## Constants

### `DuidExactMatch`

All fields in the two Device Unique Identifiers (DUIDs) match exactly.

### `DuidSubIdMatch`

Either the serial number or one of the unique sub-IDs matches. The two DUIDs probably represent the same device.

### `DuidNoMatch`

None of the sub-IDs match in page 83h of the vital product data (VPD). None of the non-VPD data matches.

### `DuidErrorGeneral`

An error occurred for an unspecified cause.

### `DuidErrorMissingDuid`

One of the two DUIDs to compare is missing.

### `DuidErrorVersionMismatch`

The two DUIDs to compare do not have the same version.

### `DuidErrorInvalidDuid`

At least one of the two DUIDs to compare is invalid.

### `DuidErrorInvalidDeviceIdDescSize`

At least one of the two DUIDs to compare contains an invalid device ID descriptor ([STORAGE_DEVICE_ID_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_device_id_descriptor)). This descriptor reports VPD data.

### `DuidErrorInvalidDeviceDescSize`

At least one of the two DUIDs to compare contains an invalid device descriptor ([STORAGE_DEVICE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_device_descriptor)). This descriptor reports non-VPD inquiry data..

### `DuidErrorInvalidLayoutSigSize`

At least one of the two DUIDs to compare contains an invalid drive layout signature size.

### `DuidErrorInvalidLayoutSigVersion`

At least one of the two DUIDs to compare contains an invalid drive layout signature.

### `DuidErrorMaximum`

This value delimits the upper limit of the enumeration values in this enumeration. This value allows a DUID consumer to create a loop that tests for all valid error values that the [CompareStorageDuids](https://learn.microsoft.com/windows-hardware/drivers/ddi/storduid/nf-storduid-comparestorageduids) routine returns. As new identifier data is added to future versions of the DUID, new error values will specify which parts of the DUID are not well-formed.

## See also

[CompareStorageDuids](https://learn.microsoft.com/windows-hardware/drivers/ddi/storduid/nf-storduid-comparestorageduids)

[STORAGE_DEVICE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_device_descriptor)

[STORAGE_DEVICE_ID_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_device_id_descriptor)