# LINEDIALPARAMS structure

## Description

The
**LINEDIALPARAMS** structure specifies a collection of dialing-related fields. Call the
[lineSetCallParams](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetcallparams) function or the
[TSPI_lineSetCallParams](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linesetcallparams) function to set parameters for a call using the
**LINEDIALPARAMS** structure.

## Members

### `dwDialPause`

Duration of a comma in the dialable address, in milliseconds.

### `dwDialSpeed`

Interdigit time period between successive digits, in milliseconds.

### `dwDigitDuration`

Duration of a digit, in milliseconds.

### `dwWaitForDialtone`

Maximum amount of time to wait for a dial tone when a 'W' is used in the dialable address, in milliseconds.

## Remarks

This structure may not be extended.

If zero is specified for a member, the default value is used. If a nonzero value is specified for a member that is outside the range specified by the **MinDialParams** and **MaxDialParams** members in the
[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps) structure, the nearest value within the valid range is used instead.

The
[lineMakeCall](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linemakecall) function allows an application to adjust the dialing parameters to be used for the call. The
[lineSetCallParams](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetcallparams) function can be used to adjust the dialing parameters of an existing call. The
[LINECALLINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallinfo) structure lists the call's current dialing parameters.

## See also

[LINECALLINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallinfo)

[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps)

[TSPI_lineSetCallParams](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linesetcallparams)

[lineMakeCall](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linemakecall)

[lineSetCallParams](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetcallparams)