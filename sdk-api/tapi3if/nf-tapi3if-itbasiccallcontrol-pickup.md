# ITBasicCallControl::Pickup

## Description

The
Pickup method picks up a call alerting at the specified group identification.

## Parameters

### `pGroupID` [in]

Pointer to a **BSTR** containing the group identifier to which the alerting station belongs.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_FAIL** | Pickup did not succeed. |
| **E_POINTER** | The *pGroupID* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **TAPI_E_TIMEOUT** | The operation failed because the TAPI 3 DLL timed it out. The timeout interval is two minutes. |

## Remarks

The application must use
[SysAllocString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstring) to allocate memory for the *pGroupID* parameter and use
[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) to free the memory when the variable is no longer needed.

## See also

[Call Object](https://learn.microsoft.com/windows/desktop/Tapi/call-object)

[ITBasicCallControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itbasiccallcontrol)

[Pickup overview](https://learn.microsoft.com/windows/desktop/Tapi/pickup-ovr)

[linePickup](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linepickup)