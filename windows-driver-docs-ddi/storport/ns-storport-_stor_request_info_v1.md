# _STOR_REQUEST_INFO_V1 structure

## Description

 The **_STOR_REQUEST_INFO_V1** structure contains details about the storage driver IO request associated with a SCSI request block (SRB). **_STOR_REQUEST_INFO_V1** is returned by the
[StorPortGetRequestInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportgetrequestinfo) routine.

## Members

### `Version`

The version of this structure. Set this member to **STOR_REQUEST_INFO_VER_1**.

### `Size`

The size of this structure. Set this value to **sizeof**(STOR_REQUEST_INFO).

### `PriorityHint`

The priority hint set for the IO request.

| Value | Meaning |
| --- | --- |
| **StorIoPriorityVeryLow**<br><br>0 | Very low priority. |
| **StorIoPriorityLow**<br><br>1 | Low priority. |
| **StorIoPriorityNormal**<br><br>2 | Normal priority. |
| **StorIoPriorityHigh**<br><br>3 | High priority. |
| **StorIoPriorityCritical**<br><br>4 | Critical priority. |

### `Flags`

Flags set for handling the request. May be a combination of these values:

| Value | Meaning |
| --- | --- |
| **REQUEST_INFO_NO_CACHE_FLAG** | Non-cached writes are specified for this request. |
| **REQUEST_INFO_PAGING_IO_FLAG** | Paging IO is specified for this request. |
| **REQUEST_INFO_SEQUENTIAL_IO_FLAG** | Reads or writes are sequential. |
| **REQUEST_INFO_TEMPORARY_FLAG** | The file for this request is temporary. |
| **REQUEST_INFO_WRITE_THROUGH_FLAG** | No system buffering for the request. |

### `Key`

The read or write key for the request.

### `Length`

The length of the data in this request.

### `IsWriteRequest`

True if this is a write request. Otherwise, false, if this is a read request.

### `Reserved`

Reserved.

## Remarks

The caller to [StorPortGetRequestInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportgetrequestinfo) allocates the **STOR_REQUEST_INFO** structure. Prior to calling **StorPortGetRequestInfo**, **Version** must be set to **STOR_REQUEST_INFO_VER_1** and **Size** must be set to **sizeof**(STOR_REQUEST_INFO). Otherwise, **StorPortGetRequestInfo** will return with a status of **STOR_STATUS_INVALID_PARAMETER**.

## See also

[StorPortGetRequestInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportgetrequestinfo)