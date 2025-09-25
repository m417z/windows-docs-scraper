# IWMDMLogger::IsEnabled

## Description

The **IsEnabled** method determines whether logging is enabled.

## Parameters

### `pfEnabled` [out]

Pointer to a flag that is true on output if logging is enabled.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

The file WmdmLog.idl is the IDL source code for WmdmLog.dll. This file is processed by the MIDL tool to produce the type library (WmdmLog.tlb) and marshaling code.

#### Examples

```cpp

// Create logging object.
CoCreateInstance(CLSID_WMDMLogger, NULL, CLSCTX_ALL, __uuidof(IWMDMLogger), (void**)&m_pLogger);
BOOL enabled = FALSE;
hr = m_pLogger->IsEnabled(&enabled);
// TODO: Display a message that logging is either enabled or disabled.
if(!enabled)
{
    if(m_pLogger->Enable(TRUE) != S_OK)
        m_pLogger = NULL;
}

```

## See also

[Enabling Logging](https://learn.microsoft.com/windows/desktop/WMDM/enabling-logging)

[IWMDMLogger Interface](https://learn.microsoft.com/windows/desktop/api/wmdmlog/nn-wmdmlog-iwmdmlogger)