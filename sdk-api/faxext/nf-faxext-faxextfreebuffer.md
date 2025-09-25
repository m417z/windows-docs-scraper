# FaxExtFreeBuffer function

## Description

The **FaxExtFreeBuffer** callback function deallocates memory previously allocated by a successful call to the [FaxExtGetData](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxext/nf-faxext-faxextgetdata) function.

## Parameters

### `lpvBuffer`

Type: **LPVOID**

Pointer to the data retrieved by a successful call to the [FaxExtGetData](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxext/nf-faxext-faxextgetdata) function.

## Remarks

When the fax extension calls this fax service callback function, it must use the function pointer exposed by the fax service when the service calls the [FaxExtInitializeConfig](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxext/nf-faxext-faxextinitializeconfig) function.

The fax service passes a pointer to the **FaxExtFreeBuffer** callback function when the fax service calls the [FaxExtInitializeConfig](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxext/nf-faxext-faxextinitializeconfig) function. The PFAX_EXT_FREE_BUFFER data type is a pointer to a **FaxExtFreeBuffer** function.

## See also

[FaxExtGetData](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxext/nf-faxext-faxextgetdata)

[FaxExtInitializeConfig](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxext/nf-faxext-faxextinitializeconfig)