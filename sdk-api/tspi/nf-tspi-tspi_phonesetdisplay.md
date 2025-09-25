# TSPI_phoneSetDisplay function

## Description

The
**TSPI_phoneSetDisplay** function causes the specified string to be displayed on the specified open phone device.

## Parameters

### `dwRequestID`

The identifier of the asynchronous request.

### `hdPhone`

The handle to the phone on which the string is to be displayed.

### `dwRow`

The row on the display where the new text is to be displayed.

### `dwColumn`

The column position on the display where the new text is to be displayed.

### `lpsDisplay`

A pointer to the memory location where the display content is stored. The application stores the display information in the format specified as **dwStringFormat** in the phone's
[PHONECAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phonecaps) structure.

### `dwSize`

The size in bytes, including the **null** terminator, of the information pointed to by *lpDisplay*.

## Return value

Returns *dwRequestID*, or an error number if an error occurs. The *lResult* actual parameter of the corresponding
[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion) is zero if the function succeeds or it is an error number if an error occurs. Possible return values are as follows:

PHONEERR_INVALPHONEHANDLE, PHONEERR_RESOURCEUNAVAIL, PHONEERR_INVALPHONESTATE, PHONEERR_OPERATIONFAILED, PHONEERR_INVALPARAM, PHONEERR_OPERATIONUNAVAIL, PHONEERR_NOMEM.

## Remarks

The specified display information is written to the phone's display, starting at the specified positions. This operation overwrites previously displayed information. If the amount of information exceeds the size of the display, the information is truncated. The amount of information that can be displayed is at most (**dwNumRows** * **dwNumColumns**) elements in size. The **dwNumRows** and **dwNumColumns** members are available in the
[PHONECAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phonecaps) structure returned by
[TSPI_phoneGetDevCaps](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_phonegetdevcaps); they are zero-based.

## See also

[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion)

[PHONECAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phonecaps)

[TSPI_phoneGetDevCaps](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_phonegetdevcaps)

[TSPI_phoneGetDisplay](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_phonegetdisplay)