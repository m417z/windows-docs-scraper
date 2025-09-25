# ITTAPI::SetAssistedTelephonyPriority

## Description

The
**SetAssistedTelephonyPriority** method sets the application priority to handle assisted telephony requests.

## Parameters

### `pAppFilename` [in]

Pointer to a **BSTR** containing the name of the application.

### `fPriority` [in]

Set to VARIANT_FALSE to disable, VARIANT_TRUE to enable.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

The application must use
[SysAllocString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstring) to allocate memory for the *pAppFilename* parameter and use
[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) to free the memory when the variable is no longer needed.

## See also

[ITBasicCallControl::HandoffIndirect](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itbasiccallcontrol-handoffindirect)

[ITTAPI](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ittapi)

[TAPI Object](https://learn.microsoft.com/windows/desktop/Tapi/tapi-object)