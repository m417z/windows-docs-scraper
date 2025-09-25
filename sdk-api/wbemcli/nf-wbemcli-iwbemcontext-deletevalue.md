# IWbemContext::DeleteValue

## Description

The
**IWbemContext::DeleteValue** method deletes a named context value created by
[IWbemContext::SetValue](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemcontext-setvalue).

## Parameters

### `wszName` [in]

Pointer to a valid **BSTR** containing the named context value to delete. The pointer is treated as read-only.

### `lFlags` [in]

Reserved. This parameter must be 0.

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**.

## See also

[IWbemContext](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemcontext)

[IWbemContext::GetValue](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemcontext-getvalue)

[IWbemContext::SetValue](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemcontext-setvalue)