# lineParkW function

## Description

The
**linePark** function parks the specified call according to the specified park mode.

## Parameters

### `hCall`

Handle to the call to be parked. The application must be an owner of the call. The call state of *hCall* must be *connected*.

### `dwParkMode`

Park mode with which the call is to be parked. This parameter can have only a single flag set, and uses one of the
[LINEPARKMODE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/lineparkmode--constants).

### `lpszDirAddress`

Pointer to a **null**-terminated string that indicates the address where the call is to be parked when using directed park. The address is in dialable number format. This parameter is ignored for nondirected park.

### `lpNonDirAddress`

Pointer to a structure of type
[VARSTRING](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-varstring). For nondirected park, the address where the call is parked is returned in this structure. This parameter is ignored for directed park. Within the
**VARSTRING** structure, **dwStringFormat** must be set to STRINGFORMAT_ASCII (an ASCII string buffer containing a **null**-terminated string), and the terminating **NULL** must be accounted for in the **dwStringSize**. Prior to calling
**linePark**, the application must set the **dwTotalSize** member of this structure to indicate the amount of memory available to TAPI for returning information.

## Return value

Returns a positive request identifier if the function is completed asynchronously, or a negative error number if an error occurs. The *dwParam2* parameter of the corresponding
[LINE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/line-reply) message is zero if the function succeeds or it is a negative error number if an error occurs. Possible return values are:

LINEERR_INVALADDRESS, LINEERR_NOTOWNER, LINEERR_INVALCALLHANDLE, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALCALLSTATE, LINEERR_OPERATIONFAILED, LINEERR_INVALPARKMODE, LINEERR_RESOURCEUNAVAIL, LINEERR_INVALPOINTER, LINEERR_STRUCTURETOOSMALL, LINEERR_NOMEM, LINEERR_UNINITIALIZED.

## Remarks

With directed park, the application determines the address at which it wants to park the call. With nondirected park, the switch determines the address and provides this to the application. In either case, a parked call can be unparked by specifying this address.

The parked call typically enters the *idle* state after it has been successfully parked, and the application should then deallocate its handle to the call. If the application performs a
[lineUnpark](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineunpark) on the parked call, a new call handle is created for the unparked call even if the application has not deallocated its old call handle.

Some switches can remind the user after a call has been parked for some long amount of time. The application sees an *offering* call with a call reason set to *reminder*.

On a nondirected park, if the **dwTotalSize** member in the
[VARSTRING](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-varstring) structure does not specify a sufficient amount of memory to receive the park address, the corresponding reply message returns a LINEERR_STRUCTURETOOSMALL error value. In such cases, there is no way to retrieve the complete park address. When a LINEERR_STRUCTURETOOSMALL error value is returned, the **dwNeededSize** member of the NonDirAddress structure does not contain a valid value. If a LINEERR_STRUCTURETOOSMALL error value is received from a nondirected
**linePark**, then increase the size of the buffer and call
**linePark** again until it returns either success or a different LINEERR_XXX result.

> [!NOTE]
> The tapi.h header defines linePark as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[LINE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/line-reply)

[Park Overview](https://learn.microsoft.com/windows/desktop/Tapi/park-ovr)

[Supplementary Line Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-line-service-functions)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

[VARSTRING](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-varstring)

[lineUnpark](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineunpark)