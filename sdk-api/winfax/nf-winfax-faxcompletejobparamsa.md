# FaxCompleteJobParamsA function

## Description

The FaxCompleteJobParams function creates both a [FAX_COVERPAGE_INFO](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_coverpage_infoa) structure and a [FAX_JOB_PARAM](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_job_parama) structure for a fax client application. This utility function supplies multiple members of these structures with values for the size of the structure, the sender's name, and optional billing code information.

## Parameters

### `JobParams` [in, out]

Type: **PFAX_JOB_PARAM***

Pointer to the address of a buffer to contain a [FAX_JOB_PARAM](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_job_parama) structure. On output, this structure contains members with values that are available from the fax server.

### `CoverpageInfo` [in, out]

Type: **PFAX_COVERPAGE_INFO***

Pointer to the address of a buffer to contain a [FAX_COVERPAGE_INFO](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_coverpage_infoa) structure. On output, this structure contains members with values that are available from the fax server.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

The fax client application should call the **FaxCompleteJobParams** function before calling the [FaxSendDocument](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxsenddocumenta) function. This enables the fax server to provide any values that are available for the members of the [FAX_JOB_PARAM](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_job_parama) and the [FAX_COVERPAGE_INFO](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_coverpage_infoa) structures. The application should not query the user's registry for this information because the location of the information can change. For more information, see [Transmitting Faxes](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-transmitting-faxes).

The application must call the [FaxFreeBuffer](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nc-winfax-pfaxfreebuffer) function once to deallocate the buffer pointed to by the *JobParams* parameter, and again to deallocate the buffer pointed to by the *CoverpageInfo* parameter. For more information, see [Freeing Fax Resources](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-freeing-fax-resources).

> [!NOTE]
> The winfax.h header defines FaxCompleteJobParams as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[FAX_COVERPAGE_INFO](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_coverpage_infoa)

[FAX_JOB_PARAM](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_job_parama)

[Fax Service Client API Functions](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-functions)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[FaxFreeBuffer](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nc-winfax-pfaxfreebuffer)

[FaxSendDocument](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxsenddocumenta)