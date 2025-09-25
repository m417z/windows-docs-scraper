# PFAXFREEBUFFER callback function

## Description

The **FaxFreeBuffer** function releases resources associated with a buffer allocated previously as the result of a function call by a fax client application. This includes calls to the [FaxCompleteJobParams](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxcompletejobparamsa) function and to functions that begin with **FaxEnum** or **FaxGet**.

## Parameters

### `Buffer` [in]

Type: **LPVOID**

Pointer to a buffer allocated on a previous call to one of the functions named in the following See Also section.

## Remarks

When the resources allocated for a buffer are no longer needed, the calling application must free the resources. For more information, see [Freeing Fax Resources](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-freeing-fax-resources).

## See also

[Fax Service Client API Functions](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-functions)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[FaxCompleteJobParams](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxcompletejobparamsa)

[FaxEnumGlobalRoutingInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxenumglobalroutinginfoa)

[FaxEnumJobs](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxenumjobsa)

[FaxEnumPorts](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxenumportsa)

[FaxEnumRoutingMethods](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxenumroutingmethodsa)

[FaxGetConfiguration](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxgetconfigurationa)

[FaxGetDeviceStatus](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxgetdevicestatusa)

[FaxGetJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxgetjoba)

[FaxGetLoggingCategories](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxgetloggingcategoriesa)

[FaxGetPageData](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nc-winfax-pfaxgetpagedata)

[FaxGetPort](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxgetporta)

[FaxGetRoutingInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxgetroutinginfoa)