# SendScsiReadCapacity function

## Description

The **SendScsiReadCapacity** function sends a SCSI READ CAPACITY command to the indicated target.

## Parameters

### `UniqueSessionId` [in]

A pointer to a [ISCSI_UNIQUE_SESSION_ID](https://learn.microsoft.com/windows/desktop/api/iscsidsc/ns-iscsidsc-iscsi_unique_session_id) structure containing the session identifier for the login session specific to the target to which the READ CAPACITY command is sent.

### `Lun` [in]

The logical unit on the target to query with the READ CAPACITY command.

### `ScsiStatus` [out]

A pointer to a location that contains the execution status of the CDB.

### `ResponseSize` [in, out]

A pointer to the location that, on input, specifies the byte-size of *ResponseBuffer*. On output, this location specifies the number of bytes required to contain the response data for the READ CAPACITY command in the *ResponseBuffer*.

### `ResponseBuffer` [out]

The buffer that receives the response data from the READ CAPACITY command.

### `SenseSize` [in, out]

A pointer to a location that, on input, contains the byte-size of *SenseBuffer*. On output, the location pointed to receives the byte-size required for *SenseBuffer* to contain the sense data. This value will always be greater than or equal to 18 bytes.

### `SenseBuffer` [out]

The buffer that receives the sense data.

## Return value

Returns ERROR_SUCCESS if the operation succeeds and ERROR_INSUFFICIENT_BUFFER if the buffer specified by *ResponseBuffer* is insufficient to contain the sense data.

If the device returns a SCSI error while processing the REPORT LUNS request, [SendScsiReportLuns](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-sendscsireportluns) returns an error code of ISDSC_SCSI_REQUEST_FAILED, and the locations pointed to by *ScsiStatus* and *SenseBuffer* contain information detailing the SCSI error.

Otherwise, this function returns the appropriate Win32 or iSCSI error code on failure.

## See also

[ISCSI_UNIQUE_SESSION_ID](https://learn.microsoft.com/windows/desktop/api/iscsidsc/ns-iscsidsc-iscsi_unique_session_id)

[SendScsiIniquiry](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-sendscsiinquiry)

[SendScsiReportLuns](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-sendscsireportluns)