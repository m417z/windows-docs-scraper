# WSDCreateHttpAddress function

## Description

Creates an [IWSDHttpAddress](https://learn.microsoft.com/windows/desktop/api/wsdbase/nn-wsdbase-iwsdhttpaddress) object.

## Parameters

### `ppAddress`

Returns a reference to the initialized [IWSDHttpAddress](https://learn.microsoft.com/windows/desktop/api/wsdbase/nn-wsdbase-iwsdhttpaddress) object. Cannot be **NULL**.

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_POINTER** | *ppAddress* is **NULL**. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |