# StorPortGetRequestInfo function

## Description

 The **StorPortGetRequestInfo** routine retrieves the IO request information associated with a SCSI request block (SRB) and returns it in a [STOR_REQUEST_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_stor_request_info_v1) structure.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension for the host bus adapter (HBA).

### `Srb` [in]

A pointer to the SRB to be queried.

### `RequestInfo` [out]

A pointer to a caller-supplied [STOR_REQUEST_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_stor_request_info_v1) structure.

## Return value

The **StorPortGetRequestInfo** routine returns one of these status codes:

| Return code | Description |
| --- | --- |
| **STOR_STATUS_UNSUPPORTED_VERSION** | The version specified for [STOR_REQUEST_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_stor_request_info_v1) is invalid. |
| **STOR_STATUS_SUCCESS** | The operation was successful. |
| **STOR_STATUS_INVALID_PARAMETER** | Either *Srb* or *RequestInfo* is set to NULL. |

## Remarks

The caller of **StorPortGetRequestInfo** must set the **Version** member of *RequestInfo* to STOR_REQUEST_INFO_VER_1. Otherwise, function will return STOR_STATUS_UNSUPPORTED_VERSION.

## See also

[STOR_REQUEST_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_stor_request_info_v1)