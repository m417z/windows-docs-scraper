# TAPI_GATHERTERM enumeration

## Description

The **TAPI_GATHERTERM** enum is used to describe the reasons why the TAPI Server terminated the gathering of digits on the call.

## Constants

### `TGT_BUFFERFULL:0x1`

The requested number of digits has been gathered. The buffer is full.

### `TGT_TERMDIGIT:0x2`

One of the termination digits matched a received digit. The matched termination digit is the last digit in the buffer.

### `TGT_FIRSTTIMEOUT:0x4`

The first digit timeout expired. The buffer contains no digits.

### `TGT_INTERTIMEOUT:0x8`

The interdigit timeout expired. The buffer contains at least one digit.

### `TGT_CANCEL:0x10`

The request was canceled by this application, by another application, or because the call terminated.

## See also

[ITDigitsGatheredEvent::get_GatherTermination](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itdigitsgatheredevent-get_gathertermination)