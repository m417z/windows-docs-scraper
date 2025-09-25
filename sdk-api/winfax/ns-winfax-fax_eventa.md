# FAX_EVENTA structure

## Description

The **FAX_EVENT** structure represents the contents of an I/O completion packet. The fax server sends the completion packet to notify a fax client application of an asynchronous fax server event.

To create a fax event queue, the fax client application must call the [FaxInitializeEventQueue](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nc-winfax-pfaxinitializeeventqueue) function. The queue enables the application to receive notifications of asynchronous events from the fax server.

## Members

### `SizeOfStruct`

Type: **DWORD**

Specifies the size, in bytes, of the **FAX_EVENT** structure. The fax server sets this member to **sizeof(FAX_EVENT)**.

### `TimeStamp`

Type: **[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime)**

Specifies a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that contains the time at which the fax server generated the event.

### `DeviceId`

Type: **DWORD**

Specifies a **DWORD** variable that indicates the permanent line identifier for the fax device of interest.

### `EventId`

Type: **DWORD**

Specifies a **DWORD** variable that identifies the current asynchronous event that occurred within the fax server. The following table lists the possible events and their meanings.

#### FEI_DIALING

The sending device is dialing a fax number.

#### FEI_SENDING

The sending device is transmitting a page of fax data.

#### FEI_RECEIVING

The receiving device is receiving a page of fax data.

#### FEI_COMPLETED

The device has completed a fax transmission call.

#### FEI_BUSY

The sending device has encountered a busy signal.

#### FEI_NO_ANSWER

The receiving device does not answer.

#### FEI_BAD_ADDRESS

The sending device cannot complete the call because the fax number is invalid.

#### FEI_NO_DIAL_TONE

The sending device cannot complete the call because it does not detect a dial tone.

#### FEI_DISCONNECTED

The device cannot complete the call because a fax device was disconnected, or because the fax call itself was disconnected.

#### FEI_FATAL_ERROR

The device encountered a fatal protocol error.

#### FEI_NOT_FAX_CALL

The modem device received a data call or a voice call.

#### FEI_CALL_DELAYED

The sending device received a busy signal multiple times. The device cannot retry the call because dialing restrictions exist. (Some countries/regions restrict the number of retry attempts when a number is busy.)

#### FEI_CALL_BLACKLISTED

The device cannot complete the call because the telephone number is blocked or reserved; numbers such as 911 are blocked.

#### FEI_RINGING

The receiving device is ringing.

#### FEI_ABORTING

The device is aborting a fax job.

#### FEI_ROUTING

The receiving device is routing a received fax document.

#### FEI_MODEM_POWERED_ON

The modem device was turned on.

#### FEI_MODEM_POWERED_OFF

The modem device was turned off.

#### FEI_IDLE

The device is idle.

#### FEI_FAXSVC_ENDED

The fax service has terminated. For more information, see the following Remarks section.

#### FEI_ANSWERED

The receiving device answered a new call.

#### FEI_FAXSVC_STARTED

The fax service has started. For more information, see the following Remarks section.

#### FEI_JOB_QUEUED

The fax job has been queued.

#### FEI_DELETED

The fax job has been processed. The job identifier for the job is no longer valid.

#### FEI_NEVENTS

The total number of fax events received. For more information, see the following Remarks section.

### `JobId`

Type: **DWORD**

Specifies a unique number that identifies the fax job of interest. If this member is equal to the value 0xffffffff, it indicates an inactive fax job. Note that this number is not a print spooler identification number.

## Remarks

After a fax client application receives the **FEI_FAXSVC_ENDED** message from the fax service, it will no longer receive fax events. To resume receiving fax events, the application must call the [FaxInitializeEventQueue](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nc-winfax-pfaxinitializeeventqueue) function again when the fax service restarts. The application can determine if the fax service is running by using the service control manager.

If the application receives events using notification messages, it can use the **FEI_NEVENTS** event. If the message is between the application's base window message and the base window message + **FEI_NEVENTS**, then the application can process the message as a fax window message. An application specifies the base window message using the *MessageStart* parameter to the [FaxInitializeEventQueue](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nc-winfax-pfaxinitializeeventqueue) function; the base window message must be greater than the [WM_USER](https://learn.microsoft.com/windows/desktop/winmsg/wm-user) message. For more information, see [FaxClose](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nc-winfax-pfaxclose) and [Enabling an Application to Receive Notifications of Fax Events](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-enabling-an-application-to-receive-notifications-of-fax-events).

> [!NOTE]
> The winfax.h header defines FAX_EVENT as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime)

[Fax Service Client API Structures](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-structures)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[FaxClose](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nc-winfax-pfaxclose)

[FaxInitializeEventQueue](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nc-winfax-pfaxinitializeeventqueue)