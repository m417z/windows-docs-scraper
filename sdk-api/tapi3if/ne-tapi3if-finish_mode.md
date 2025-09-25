# FINISH_MODE enumeration

## Description

The
**FINISH_MODE** enum is used by applications to indicate the type of call finish required. Operations that the TAPI DLL performs vary depending on whether a call transfer is being completed or a call is being added to a conference.

## Constants

### `FM_ASTRANSFER:0`

A call transfer is being finished.

### `FM_ASCONFERENCE`

A call is being added to a conference call.

## See also

[ITBasicCallControl::Finish](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itbasiccallcontrol-finish)