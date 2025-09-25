# WSDCreateHttpMessageParameters function

## Description

Creates an [IWSDHttpMessageParameters](https://learn.microsoft.com/windows/desktop/api/wsdbase/nn-wsdbase-iwsdhttpmessageparameters) object.

## Parameters

### `ppTxParams`

Returns a reference to the initialized [IWSDHttpMessageParameters](https://learn.microsoft.com/windows/desktop/api/wsdbase/nn-wsdbase-iwsdhttpmessageparameters) object. Cannot be **NULL**.

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_INVALIDARG** | *ppTxParams* is **NULL**. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |