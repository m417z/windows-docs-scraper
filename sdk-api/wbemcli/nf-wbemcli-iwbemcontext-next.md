# IWbemContext::Next

## Description

The
**IWbemContext::Next** method retrieves the next value in an enumeration of all context values beginning with
[IWbemContext::BeginEnumeration](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemcontext-beginenumeration).

## Parameters

### `lFlags` [in]

Reserved. This parameter must be 0.

### `pstrName` [out]

This parameter cannot be **NULL**. The pointer must not point to an active **BSTR** on entry, and ideally it should be set to point to **NULL**. If no error code is returned, it is set to point to a newly allocated **BSTR** containing the context value name.

The caller must call **SysFreeString** on the returned string when it is no longer required. If **WBEM_S_NO_MORE_DATA** returns, *pstrName* is set to point to **NULL**, in which case **SysFreeString** should not be called. Note that if *pstrName* points to a valid **BSTR** on entry, this **BSTR** is not freed, and a memory leak occurs.

### `pValue` [out]

This parameter cannot be **NULL**, and it must point to an empty or uninitialized **VARIANT**. If no error is returned, the **VARIANT** is initialized using **VariantInit**, and then set to contain the context value. The caller must call **VariantClear** on this pointer when the value is no longer required. If an error code is returned, the **VARIANT** pointed to by *pValue* is left unmodified.

If **WBEM_S_NO_MORE_DATA** returns, this parameter is set to point to a **VARIANT** of type **VT_NULL**.

It is possible that an entire
[IWbemClassObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemclassobject) object may be returned inside the **VARIANT**. If that is the case, then **VT_UNKNOWN** is the **VARIANT** type. The caller can take the **IUnknown** pointer and execute **QueryInterface** to obtain the
**IWbemClassObject** pointer.

**Note** At the end of the enumeration, **WBEM_S_NO_MORE_DATA** is returned. The returned **VARIANT** is of type **VT_NULL**, and the returned *pstrName* is **NULL**.

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**.

## See also

[IWbemContext](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemcontext)

[IWbemContext::BeginEnumeration](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemcontext-beginenumeration)

[IWbemContext::EndEnumeration](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemcontext-endenumeration)