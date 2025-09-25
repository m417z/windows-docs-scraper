# SendScsiInquiry function

## Description

The **SendScsiInquiry** function sends a SCSI INQUIRY command to the specified target.

## Parameters

### `UniqueSessionId` [in]

A pointer to a [ISCSI_UNIQUE_SESSION_ID](https://learn.microsoft.com/windows/desktop/api/iscsidsc/ns-iscsidsc-iscsi_unique_session_id) structure containing the session identifier for the login session specific to the target to which the READ CAPACITY command is sent.

### `Lun` [in]

The logical unit to query for SCSI inquiry data.

### `EvpdCmddt` [in]

The values to assign to the EVP (enable the vital product data) and CmdDt (command support data) bits in the INQUIRY command. Bits 0 (EVP) and 1 (CmdDt) of the *EvpdCmddt* parameter
are inserted into bits 0 and 1, respectively, of the second byte of the Command Descriptor Block (CDB) of the **INQUIRY** command.

### `PageCode` [in]

The page code. This code is inserted into the third byte of the CDB of the **INQUIRY** command.

### `ScsiStatus` [out]

A pointer to a location that reports the execution status of the CDB.

### `ResponseSize` [in, out]

A pointer to the location that, on input, specifies the byte-size of *ResponseBuffer*. On output, this location specifies the number of bytes required to contain the response data for the READ CAPACITY command in the *ResponseBuffer*.

### `ResponseBuffer` [out]

The buffer that holds the inquiry data.

### `SenseSize` [in, out]

A pointer to a location that, on input, contains the byte-size of *SenseBuffer*. On output, the location pointed to receives the byte-size required for *SenseBuffer* to contain the sense data. This value will always be greater than or equal to 18 bytes.

### `SenseBuffer` [out]

The buffer that holds the sense data.

## Return value

Returns ERROR_SUCCESS if the operation succeeds and ERROR_INSUFFICIENT_BUFFER if the buffer specified by *ResponseBuffer* is insufficient to contain the sense data.

If the device returns a SCSI error while processing the REPORT LUNS request, [SendScsiReportLuns](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-sendscsireportluns) returns an error code of ISDSC_SCSI_REQUEST_FAILED, and the locations pointed to by *ScsiStatus* and *SenseBuffer* contain information detailing the SCSI error.

Otherwise, **SendScsiInquiry** returns the appropriate Win32 or iSCSI error code on failure.

## See also

[ISCSI_UNIQUE_SESSION_ID](https://learn.microsoft.com/windows/desktop/api/iscsidsc/ns-iscsidsc-iscsi_unique_session_id)