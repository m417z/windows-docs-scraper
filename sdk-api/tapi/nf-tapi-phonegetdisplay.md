# phoneGetDisplay function

## Description

The
**phoneGetDisplay** function returns the current contents of the specified phone display.

## Parameters

### `hPhone`

Handle to the open phone device.

### `lpDisplay`

Pointer to the memory location where the display content is to be stored, of type
[VARSTRING](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-varstring).

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values are:

PHONEERR_INVALPHONEHANDLE, PHONEERR_RESOURCEUNAVAIL, PHONEERR_INVALPOINTER, PHONEERR_OPERATIONFAILED, PHONEERR_INVALPHONESTATE, PHONEERR_STRUCTURETOOSMALL, PHONEERR_OPERATIONUNAVAIL, PHONEERR_UNINITIALIZED, PHONEERR_NOMEM.

## Remarks

The **lpDisplay** memory area should be at least (**dwDisplayNumRows** * **dwDisplayNumColumns**) elements in size to receive all of the display information. The **dwDisplayNumRows** and **dwDisplayNumColumns** members are available in the
[PHONECAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phonecaps) structure returned by
[phoneGetDevCaps](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonegetdevcaps).

## See also

[PHONECAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phonecaps)

[Supplementary Phone Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-phone-service-functions)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

[VARSTRING](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-varstring)

[phoneGetDevCaps](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonegetdevcaps)