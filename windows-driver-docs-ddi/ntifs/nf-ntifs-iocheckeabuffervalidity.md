# IoCheckEaBufferValidity function

## Description

The **IoCheckEaBufferValidity** routine checks whether the specified extended attribute (EA) buffer is valid.

## Parameters

### `EaBuffer` [in]

Pointer to the buffer containing the EAs to be checked.

### `EaLength` [in]

Length, in bytes, of **EaBuffer**.

### `ErrorOffset` [out]

Pointer to a variable that receives the offset of the offending entry in the EA buffer if an error is found. This variable is only valid if an error occurs.

## Return value

**IoCheckEaBufferValidity** returns STATUS_SUCCESS if the EA buffer is valid; otherwise it returns STATUS_EA_LIST_INCONSISTENT.

## Remarks

**IoCheckEaBufferValidity** checks each FILE_FULL_EA_INFORMATION entry in the specified EA buffer to ensure that the following conditions are met:

* The entire entry must fall within the buffer.

* The value of **EaName** must be a null-terminated character array.

* The value of **EaNameLength** must match the length in bytes of the **EaName** array (not including the zero-terminator).

* For all entries except the last, the value of **NextEntryOffset** must be greater than zero and must fall on a ULONG boundary.

In addition, **IoCheckEaBufferValidity** checks the EA buffer to ensure that the following conditions are met:

* The length passed in **EaLength** matches the actual length of the buffer.

* The actual buffer length is nonnegative.

To be valid, the EA buffer must meet all of these conditions.

**IoCheckEaBufferValidity** doesn't perform any synchronization to ensure that the contents of **EaBuffer** do not change asynchronously. If a user-mode application can access the buffer in another thread, the application could change the buffer while **IoCheckEaBufferValidity** is running. This change might cause the routine to return incorrect information. To avoid this scenario, the driver should copy the buffer before calling **IoCheckEaBufferValidity**. After the buffer has been validated, the caller should use only the validated copy, not the original buffer.

## See also

[**FILE_FULL_EA_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_full_ea_information)

[**IRP_MJ_QUERY_EA**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-query-ea)

[**IRP_MJ_SET_EA**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-set-ea)