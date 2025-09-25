## Description

The **IWiaLog::hResult** method is obsolete and is no longer supported. Use the [**Diagnostic Log Macros**](https://learn.microsoft.com/windows-hardware/drivers/image/wia-diagnostic-log-macros) instead.

The **IWiaLog::hResult** method translates an HRESULT value into a string and writes the string to *Wiaservc.log*.

## Parameters

### `hResult` [in]

Specifies the HRESULT value to translate into a string.

## Return value

If the method succeeds, it returns S_OK. If the method fails, it returns a standard COM error code.