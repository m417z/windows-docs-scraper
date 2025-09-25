# FAX_JOB_EXTENDED_STATUS_ENUM enumeration

## Description

The **FAX_JOB_EXTENDED_STATUS_ENUM** enumeration defines the extended status values for a fax job. These are basic values provided for developers of a fax service provider (FSP). However, with the exception of ****fjesPARTIALLY_RECEIVED****, these values or other proprietary values that may be developed for a specific FSP, are not recognized or interpreted by the fax server.

## Constants

### `fjesNONE:0`

No extended status value.

### `fjesDISCONNECTED`

The sender or the caller disconnected the fax call.

### `fjesINITIALIZING`

The device is initializing a call.

### `fjesDIALING`

The device is dialing a fax number.

### `fjesTRANSMITTING`

The device is sending a fax.

### `fjesANSWERED`

The device answered a new call.

### `fjesRECEIVING`

The device is receiving a fax.

### `fjesLINE_UNAVAILABLE`

The device is not available because it is in use by another application.

### `fjesBUSY`

The device encountered a busy signal.

### `fjesNO_ANSWER`

The receiving device did not answer the call.

### `fjesBAD_ADDRESS`

The device dialed an invalid fax number.

### `fjesNO_DIAL_TONE`

The sending device cannot complete the call because it does not detect a dial tone.

### `fjesFATAL_ERROR`

The device has encountered a fatal protocol error.

### `fjesCALL_DELAYED`

The device delayed a fax call because the sending device received a busy signal multiple times. The device cannot retry the call because dialing restrictions exist. (Some countries/regions restrict the number of retry attempts when a number is busy.)

### `fjesCALL_BLACKLISTED`

The device could not complete a call because the telephone number was blocked or reserved; emergency numbers such as 911 are blocked.

### `fjesNOT_FAX_CALL`

The device received a call that was a data call or a voice call.

### `fjesPARTIALLY_RECEIVED`

The incoming fax was partially received. Some (but not all) of the pages are available.

### `fjesHANDLED`

The fax service processed the outbound fax; the fax service provider will transmit the fax.

### `fjesCALL_COMPLETED`

The call was completed.

### `fjesCALL_ABORTED`

The call was aborted.

### `fjesPROPRIETARY:0x1000000`

Obsolete. For information about proprietary extended status codes, see [IFaxOutgoingJob::get_ExtendedStatusCode](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutgoingjob-extendedstatuscode-vb).

## See also

[ExtendedStatusCode](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingjob-extendedstatuscode)

[IFaxIncomingJob::get_ExtendedStatus](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingjob-extendedstatus-vb)

[IFaxJobStatus::get_ExtendedStatus](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxjobstatus-extendedstatus-vb)

[IFaxJobStatus::get_ExtendedStatusCode](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxjobstatus-extendedstatuscode-vb)

[IFaxOutgoingJob::get_ExtendedStatus](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutgoingjob-extendedstatus-vb)

[IFaxOutgoingJob::get_ExtendedStatusCode](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutgoingjob-extendedstatuscode-vb)