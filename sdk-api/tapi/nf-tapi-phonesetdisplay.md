# phoneSetDisplay function

## Description

The
**phoneSetDisplay** function causes the specified string to be displayed on the specified open phone device.

## Parameters

### `hPhone`

Handle to the open phone device. The application must be the owner of the phone.

### `dwRow`

Row position on the display where the new text is to be displayed.

### `dwColumn`

Column position on the display where the new text is to be displayed.

### `lpsDisplay`

Pointer to the memory location where the display content is stored. The display information must have the format specified in the **dwStringFormat** member of the
[PHONECAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phonecaps) structure, which describes the phone's device capabilities.

### `dwSize`

Size of the information pointed to by *lpsDisplay*, in bytes. If the *lpsDisplay* parameter is a pointer to a string, the size must include the null terminator.

## Return value

Returns a positive request identifier if the function is completed asynchronously or a negative error number if an error occurs. The *dwParam2* parameter of the corresponding
[PHONE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/phone-reply) message is zero if the function succeeds or it is a negative error number if an error occurs. Possible return values are:

PHONEERR_INVALPHONEHANDLE, PHONEERR_OPERATIONUNAVAIL, PHONEERR_NOTOWNER, PHONEERR_OPERATIONFAILED, PHONEERR_INVALPHONESTATE, PHONEERR_UNINITIALIZED, PHONEERR_INVALPOINTER, PHONEERR_NOMEM, PHONEERR_INVALPARAM, PHONEERR_RESOURCEUNAVAIL.

## Remarks

The specified display information is written to the phone's display, starting at the specified positions. This operation overwrites previously displayed information. If the amount of information exceeds the size of the display, the information is truncated. The amount of information that can be displayed is at most (**dwNumRows** * **dwNumColumns**) elements in size. **dwNumRows** and **dwNumColumns** are available in the
[PHONECAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phonecaps) structure, which is returned by
[phoneGetDevCaps](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonegetdevcaps); they are zero-based.

## See also

[PHONECAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phonecaps)

[PHONE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/phone-reply)

[Supplementary Phone Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-phone-service-functions)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

[phoneGetDevCaps](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonegetdevcaps)