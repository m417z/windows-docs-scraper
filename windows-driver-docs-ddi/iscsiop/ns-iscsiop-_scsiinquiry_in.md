# _ScsiInquiry_IN structure (iscsiop.h)

## Description

The ScsiInquiry_IN structure holds the input data for the [ScsiInquiry](https://learn.microsoft.com/windows-hardware/drivers/storage/scsiinquiry) method, which is used to send a SCSI inquiry command.

## Members

### `UniqueSessionId`

A 64-bit integer that uniquely identifies the session. The [LoginToTarget](https://learn.microsoft.com/windows-hardware/drivers/storage/logintotarget) and [AddConnectionToSession](https://learn.microsoft.com/windows-hardware/drivers/storage/addconnectiontosession) methods both return this value in the *UniqueSessionId* parameter. Do not confuse this value with the values in the ISID and TSID members.

### `Lun`

A 64-bit number that, together with the name of the target, uniquely identifies the logical unit.

### `InquiryFlags`

The inquiry flags to set in the SCSI inquiry command. A value of 1 in the lowest order bit (0x01) indicates that the enable vital product data (EVPD) bit will be set in the inquiry command and the device server will return the optional vital product data that the page code field specifies in the inquiry command. A value of 1 in the second bit (0x02) indicates that the command support data bit will be set in the inquiry command and the device server will return the optional command support data that the operation code field specifies in the inquiry command.

### `PageCode`

The page code field in the SCSI inquiry command.

## Remarks

You must implement this method.

## See also

[AddConnectionToSession](https://learn.microsoft.com/windows-hardware/drivers/storage/addconnectiontosession)

[LoginToTarget](https://learn.microsoft.com/windows-hardware/drivers/storage/logintotarget)

[ScsiInquiry](https://learn.microsoft.com/windows-hardware/drivers/storage/scsiinquiry)

[ScsiInquiry_OUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsiop/ns-iscsiop-_scsiinquiry_out)