# FaxDevShutdown function

## Description

The fax service calls the **FaxDevShutdown** function to notify the fax service provider (FSP) that the service is about to unload the FSP's DLL. **FaxDevShutdown** releases the global resources allocated by the [FaxDevInitialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxdev/nf-faxdev-faxdevinitialize) function.

Exporting the **FaxDevShutdown** function is optional.

## Return value

Type: **HRESULT**

If the function succeeds, the return value is S_OK.

If the function fails, the return value is E_FAIL.

## Remarks

The fax service always unloads the FSP's DLL, even if the FSP returns failure in response to this function.

## See also

[Fax Service Provider Functions](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-provider-functions)

[FaxDevInitialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxdev/nf-faxdev-faxdevinitialize)

[Using the Fax Service Provider API](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-using-the-fax-service-provider-api)