# QOS_SERVICE_LEVEL enumeration

## Description

The
**QOS_SERVICE_LEVEL** enum is used by the
[ITBasicCallControl::SetQOS](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itbasiccallcontrol-setqos) method to indicate quality of service requirements for a call.

## Constants

### `QSL_NEEDED:1`

Quality of service level required.

### `QSL_IF_AVAILABLE:2`

Quality of service level desired if available.

### `QSL_BEST_EFFORT:3`

Quality of service level desired is "best effort."

## See also

[ITBasicCallControl::SetQOS](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itbasiccallcontrol-setqos)

[ITQOSEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itqosevent)