# IoCheckQuotaBufferValidity function

## Description

The **IoCheckQuotaBufferValidity** routine checks whether the specified quota buffer is valid.

## Parameters

### `QuotaBuffer` [in]

Pointer to the buffer containing the quota entries to be checked.

### `QuotaLength` [in]

Length, in bytes, of **QuotaBuffer**.

### `ErrorOffset` [out]

A variable to receive the offset of the offending entry in the quota buffer if an error is found. This variable is only valid if an error occurs.

## Return value

**IoCheckQuotaBufferValidity** returns STATUS_SUCCESS if the quota buffer is valid. Otherwise, it returns STATUS_DATATYPE_MISALIGNMENT if the quota buffer is not ULONG-aligned. For all other errors, including misalignment of entries in the buffer, **IoCheckQuotaBufferValidity** returns STATUS_QUOTA_LIST_INCONSISTENT.

## Remarks

**IoCheckQuotaBufferValidity** checks each FILE_QUOTA_INFORMATION entry in the specified quota buffer to ensure that the following conditions are met:

* The entire entry must fall within the buffer.

* The value of **Sid** must be a security identifier (SID).

* The value of **SidLength** must match the length in bytes of the value of **Sid**.

* For all entries except the last, the value of **NextEntryOffset** must be greater than zero and must fall on a ULONG boundary.

In addition, **IoCheckQuotaBufferValidity** checks the quota buffer to ensure that the following conditions are met:

* The buffer must be ULONG-aligned.

* The length passed in **QuotaLength** matches the actual length of the buffer.

* The actual buffer length is nonnegative.

To be valid, the quota buffer must meet all of these conditions.

## See also

[**FILE_QUOTA_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_quota_information)

[**IRP_MJ_QUERY_QUOTA**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-query-quota)

[**IRP_MJ_SET_QUOTA**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-set-quota)