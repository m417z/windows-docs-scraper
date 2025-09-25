# FaxDevInitialize function

## Description

The fax service calls the **FaxDevInitialize** function each time the service starts, after it loads the fax service provider (FSP) DLL. Each FSP must export the **FaxDevInitialize** function.

## Parameters

### `LineAppHandle` [in]

Type: **HLINEAPP**

Specifies a handle to the fax service's registration with TAPI. For more information, see the TAPI 2.x [lineInitializeEx](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineinitializeexa) function.

### `HeapHandle` [in]

Type: **HANDLE**

Specifies a handle to a heap that the FSP must use for all memory allocations.

### `LineCallbackFunction` [out]

Type: **PFAX_LINECALLBACK***

Pointer to a variable that receives a pointer to a TAPI line callback function.

### `FaxServiceCallback` [in]

Type: **PFAX_SERVICE_CALLBACK**

Pointer to a service callback function. Although this function is not used currently, this feature is expected to be available in a future version of the fax service and will provide functionality from the fax service to the FSP.

## Return value

Type: **BOOL**

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. In this case, the current instance of the fax service does not use this FSP. All devices that this FSP supports are unable to send or receive faxes. To get extended error information, the fax service calls [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The FSP must respond to the **FaxDevInitialize** function by performing any necessary initialization.

The FSP must supply the [FaxLineCallback](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxdev/nc-faxdev-pfax_linecallback) function specified by the *LineCallbackFunction* parameter. The fax service calls this function when it needs to deliver a TAPI event to the FSP.

## See also

[Fax Service Provider Functions](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-provider-functions)

[FaxDevStartJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxdev/nf-faxdev-faxdevstartjob)

[FaxDevVirtualDeviceCreation](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxdev/nf-faxdev-faxdevvirtualdevicecreation)

[FaxLineCallback](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxdev/nc-faxdev-pfax_linecallback)

[Using the Fax Service Provider API](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-using-the-fax-service-provider-api)

[lineInitializeEx](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineinitializeexa)