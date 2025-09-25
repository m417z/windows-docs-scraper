# TSPI_phoneGetDisplay function

## Description

The
**TSPI_phoneGetDisplay** function returns the current contents of the specified phone display.

## Parameters

### `hdPhone`

The handle to the phone to be queried.

### `lpDisplay`

A pointer to the memory location where the display content is to be stored by the provider, of type
[VARSTRING](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-varstring). Prior to calling
**TSPI_phoneGetDisplay**, the application sets the **dwTotalSize** member of this structure to indicate the amount of memory available to TAPI for returning information.

## Return value

Returns zero if the function succeeds, or an error number if an error occurs. Possible return values are as follows:

PHONEERR_INVALPHONEHANDLE, PHONEERR_RESOURCEUNAVAIL, PHONEERR_INVALPHONESTATE, PHONEERR_OPERATIONFAILED, PHONEERR_NOMEM, PHONEERR_OPERATIONUNAVAIL.

## Remarks

The *lpDisplay* memory area should be at least **dwDisplayNumRows** * **dwDisplayNumColumns** elements in size to receive all of the display information. The **dwDisplayNumRows** and **dwDisplayNumColumns** members are available in the
[PHONECAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phonecaps) structure returned by
[TSPI_phoneGetDevCaps](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_phonegetdevcaps).

The service provider fills in all the members of the
[VARSTRING](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-varstring) data structure, except for **dwTotalSize**, which is filled in by TAPI. The service provider must not overwrite the **dwTotalSize** member.

## See also

[PHONECAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phonecaps)

[TSPI_phoneGetDevCaps](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_phonegetdevcaps)

[TSPI_phoneSetDisplay](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_phonesetdisplay)

[VARSTRING](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-varstring)