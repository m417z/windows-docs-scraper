# IWbemContext::GetValue

## Description

The
**IWbemContext::GetValue** method is used to retrieve a specific named context value by name.

## Parameters

### `wszName` [in]

Name for which the value is to be retrieved. This must point to a valid **BSTR**. The pointer is treated as read-only.

### `lFlags` [in]

Reserved. This parameter must be 0.

### `pValue` [out]

This parameter cannot be **NULL** and must point to an uninitialized **VARIANT**. If no error is returned, the **VARIANT** is initialized using **VariantInit**, and then set to contain the context value. The caller must call **VariantClear** on this pointer when the value is no longer required. If an error code is returned, the **VARIANT** pointed to by *pValue* is left unmodified.

It is possible that an entire
[IWbemClassObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemclassobject) object can be returned inside the **VARIANT**. If that is the case, then **VT_UNKNOWN** is the **VARIANT** type. The caller can take the **IUnknown** pointer and execute **QueryInterface** to obtain the
**IWbemClassObject** pointer.

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**.

## See also

[IWbemContext](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemcontext)

[IWbemContext::SetValue](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemcontext-setvalue)