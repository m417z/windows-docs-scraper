# _FILE_DESIRED_STORAGE_CLASS_INFORMATION structure

## Description

Contains the information for the desired storage class attribute. The class information is set by calling [**NtSetInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntsetinformationfile)

## Members

### `Class`

A [**FILE_STORAGE_TIER_CLASS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-_file_storage_tier_class)-value that the storage class. This is the tier type for the file/directory.

### `Flags`

Flags for the class type. Here are the possible values:

- QUERY_STORAGE_CLASSES_FLAGS_MEASURE_WRITE
- QUERY_STORAGE_CLASSES_FLAGS_MEASURE_READ

## Remarks

## See also