# LINETERMCAPS structure

## Description

The
**LINETERMCAPS** structure describes the capabilities of a line's terminal device. The
[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps) structure can contain an array of
**LINETERMCAPS** structures.

## Members

### `dwTermDev`

Device type of the terminal. This member uses one of the
[LINETERMDEV_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linetermdev--constants).

### `dwTermModes`

Terminal mode(s) the terminal device is able to deal with. This member uses one of the
[LINETERMMODE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linetermmode--constants).

### `dwTermSharing`

Sharing modes for the terminal device. This member uses one of the
[LINETERMSHARING_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linetermsharing--constants).

## Remarks

This structure may not be extended.

## See also

[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps)

[TSPI_lineGetDevCaps](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegetdevcaps)

[lineGetDevCaps](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetdevcaps)

[lineSetTerminal](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetterminal)