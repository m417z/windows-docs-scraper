# TSPI_lineGatherDigits function

## Description

The
**TSPI_lineGatherDigits** function initiates the buffered gathering of digits on the specified call. TAPI specifies a buffer in which to place the digits and the maximum number of digits to be collected.

## Parameters

### `hdCall`

The service provider's handle to the call on which digit gathering is to be performed. The call state of *hdCall* can be any state except *idle*.

### `dwEndToEndID`

A unique, uninterpreted identifier of the request for its entire lifetime, that is, until the matching
[LINE_GATHERDIGITS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725229(v=vs.85)) message is sent. The service provider includes this identifier as one of the parameters in the message.

### `dwDigitModes`

The digit mode(s) that are to be monitored. This parameter uses one or more of the following LINEDIGITMODE_ constants.

| Value | Meaning |
| --- | --- |
| **LINEDIGITMODE_PULSE** | Detect digits as audible clicks that are the result of the use of rotary pulse sequences. Valid digits for pulse mode are '0' through '9'. |
| **LINEDIGITMODE_DTMF** | Detect digits as DTMF tones. Valid digits for DTMF mode are '0' through '9', 'A', 'B', 'C', 'D', '*', '#'. |

### `lpsDigits`

A pointer to the buffer where detected digits are to be stored as text characters. The service provider may, but is not required to, place digits in the buffer one at a time as they are collected. When the
[LINE_GATHERDIGITS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725229(v=vs.85)) message is sent, the content of the buffer must be complete. If *lpsDigits* is specified as **NULL** the digit gathering currently in progress on the call is canceled and the *dwNumDigits* parameter is ignored. Otherwise, *lpsDigits* is assumed to have room for *dwNumDigits* digits.

### `dwNumDigits`

The number of digits to be collected before a LINE_GATHERDIGITS message is sent to TAPI. The *dwNumDigits* parameter is ignored when *lpsDigits* is **NULL**. This function must return a LINEERR_INVALPARAM if *dwNumDigits* is zero.

### `lpszTerminationDigits`

Pointer to a **null**-terminated Unicode string of termination digits as text characters. If one of the digits in the string is detected, that termination digit is appended to the buffer, digit collection is terminated, and the
[LINE_GATHERDIGITS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725229(v=vs.85)) message is sent to TAPI.

Valid characters for pulse mode are '0' through '9'. Valid characters for DTMF mode are '0' through '9', 'A', 'B', 'C', 'D', '*', '#'. If this pointer is **NULL**, or if it points to an empty string, the function behaves as though no termination digits were supplied.

### `dwFirstDigitTimeout`

The time duration in milliseconds in which the first digit is expected. If the first digit is not received in this timeframe, digit collection is terminated and a LINE_GATHERDIGITS message is sent to TAPI. A single **NULL** character is written to the buffer, indicating no digits were received and the first digit timeout terminated digit gathering. The call's line device capabilities specifies the valid range for this parameter or indicates that timeouts are not supported. This parameter is not validated by TAPI when this function is called.

### `dwInterDigitTimeout`

The maximum time duration in milliseconds between consecutive digits. If no digit is received in this timeframe, digit collection is terminated and a
[LINE_GATHERDIGITS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725229(v=vs.85)) message is sent to TAPI. A single NULL character is written to the buffer, indicating that an interdigit timeout terminated digit gathering. The
[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps) structure must specify the valid range for this parameter or indicate that timeouts are not supported. This parameter is not validated by TAPI when this function is called.

## Return value

Returns zero if the function succeeds or an error number if an error occurs. Possible return values are as follows:

LINEERR_INVALCALLHANDLE, LINEERR_RESOURCEUNAVAIL, LINEERR_INVALCALLSTATE, LINEERR_NOMEM, LINEERR_INVALTIMEOUT, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALDIGITMODE, LINEERR_OPERATIONFAILED, LINEERR_INVALDIGITS, LINEERR_RESOURCEUNAVAIL, LINEERR_INVALPARAM.

## Remarks

The service provider returns LINEERR_INVALPARAM if the *dwNumDigits* parameter is invalid.

This function returns zero (success) if digit collection is correctly initiated; not if digit collection has terminated. In all cases where a partial buffer is returned, valid digits (if any) are followed by an Unicode NULL character.

Digit collection can be terminated in the following ways:

* The requested number of digits may have been collected.
* One of the digits detected matches a digit in *szTerminationDigits* before the specified number of digits has been collected. The detected termination digit is also placed in the buffer and the partial buffer is returned.
* One of the timeouts expires. The *dwFirstDigitTimeout* expires if the first digit is not received in this time period. The *dwInterDigitTimout* expires if the second, third, (and so forth) digit is not received within that time period from the previously detected digit, and a partial buffer is returned.
* Calling this operation again while collection is in progress. The old collection session is terminated and the contents of the old buffer is undefined. To cancel digit gathering without initiating another operation, this operation is invoked with *lpsDigits* equal to NULL.

Although this function can be invoked in any call state except *idle*, digits can typically only be gathered while the call is in the *connected* state.

The
[LINE_GATHERDIGITS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725229(v=vs.85)) message is normally sent when the digit buffer becomes filled. It is also sent when partial buffers are returned because of timeouts or matching termination digits, or when the request is canceled through another
**TSPI_lineGatherDigits** request on the call. Only one gather digits request can be active at a time. The service provider must terminate any outstanding gathering operation with a LINE_GATHERDIGITS message when
**TSPI_lineGatherDigits** is called.

When the operation associated with a call to the
**TSPI_lineGatherDigits** function is canceled (by a subsequent call to the function), the service provider copies any digits collected up to that point to the buffer specified in the original call.

TAPI can use
[TSPI_lineMonitorDigits](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linemonitordigits) to enable or disable unbuffered digit detection. Each time a digit is detected in this fashion, a
[LINE_MONITORDIGITS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725232(v=vs.85)) message is sent to TAPI. Both buffered (gather digits) and unbuffered digit detection can be enabled for the same call simultaneously.

The service provider is allowed some variation in the quality of timing it uses for this function, including not doing timings at all. The quality of timing is reported in
[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps), in the members **dwGatherDigitsMinTimeout** and **dwGatherDigitsMaxTimeout**.

The corresponding function at the TAPI level does not include the formal parameter *dwEndToEndID*. At that level, there is no end-to-end marking. TAPI uses end-to-end marking at the TSPI level to distinguish one
**TSPI_lineGatherDigits** request from another.

## See also

[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps)

[LINEDIGITMODE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linedigitmode--constants)

[LINE_GATHERDIGITS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725229(v=vs.85))

[LINE_MONITORDIGITS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725232(v=vs.85))

[TSPI_lineGetDevCaps](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegetdevcaps)

[TSPI_lineMonitorDigits](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linemonitordigits)