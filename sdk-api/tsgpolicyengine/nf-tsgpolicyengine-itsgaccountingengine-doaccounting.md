# ITSGAccountingEngine::DoAccounting

## Description

Provides information about the creation or closing of sessions for a connection.

Remote Desktop Gateway (RD Gateway) calls this method to pass information to an authorization plug-in.

## Parameters

### `accountingDataType` [in]

A value of the [AAAccountingDataType](https://learn.microsoft.com/windows/win32/api/tsgpolicyengine/ns-tsgpolicyengine-aaaccountingdata)
enumeration type that specifies the type of event that occurred.

### `accountingData` [in]

An [AAAccountingData](https://learn.microsoft.com/windows/win32/api/tsgpolicyengine/ns-tsgpolicyengine-aaaccountingdata) structure that contains
information about the event that occurred.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITSGAccountingEngine](https://learn.microsoft.com/windows/desktop/api/tsgpolicyengine/nn-tsgpolicyengine-itsgaccountingengine)