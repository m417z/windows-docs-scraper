# IWbemContext::SetValue

## Description

The
**IWbemContext::SetValue** method creates or overwrites a named context value.

## Parameters

### `wszName` [in]

Cannot be **NULL**. It is a read-only pointer that indicates the context value name. This value must be **null**-terminated.

### `lFlags` [in]

Reserved. This parameter must be 0 (zero).

### `pValue` [in]

Must point to a valid **VARIANT**, which is treated as read-only. The value in the **VARIANT** becomes the named context value. An entire
[IWbemClassObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemclassobject) object can be stored as well as a simple value by enclosing it in a **VARIANT** that uses the **VT_UNKNOWN** type. The caller must execute [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) on the
**IWbemClassObject** object by asking for **IID_IUnknown**, and by using the returned pointer in the **VARIANT**.

If *pValue* is to contain an embedded
[IWbemClassObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemclassobject) object, the caller must call [IWbemClassObject::QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) for **IID_IUnknown** and place the resulting pointer in the **VARIANT** by using a type of **VT_UNKNOWN**. The original embedded object is copied during the write operation, and so cannot be modified by the operation.

## Return value

This method returns an **HRESULT** that indicates the status of a method call. The following list lists and describes the values contained in an **HRESULT**.

## See also

[IWbemContext](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemcontext)

[IWbemContext::GetValue](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemcontext-getvalue)