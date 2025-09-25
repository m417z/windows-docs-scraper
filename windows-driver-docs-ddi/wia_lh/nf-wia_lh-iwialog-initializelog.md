## Description

The **IWiaLog::InitializeLog** method is obsolete and is no longer supported. Use the [**Diagnostic Log Macros**](https://learn.microsoft.com/windows-hardware/drivers/image/wia-diagnostic-log-macros) instead.

The **IWiaLog::InitializeLog** method initializes the **lWiaLog** interface.

## Parameters

### `hInstance` [in]

Specifies the module handle. This parameter indicates which module is calling the method.

## Return value

If the method succeeds, it returns S_OK. If the method fails, it returns a standard COM error code.

## Remarks

The minidriver should call [CoCreateInstance](https://learn.microsoft.com/windows/win32/api/combaseapi/nf-combaseapi-cocreateinstance) or [CoCreateInstanceEx](https://learn.microsoft.com/windows/win32/api/combaseapi/nf-combaseapi-cocreateinstanceex) to obtain the [**IWiaLog**](https://learn.microsoft.com/windows/win32/api/wia_xp/nn-wia_xp-iwialog) interface.