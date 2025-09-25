# WSDCreateOutboundAttachment function

## Description

Creates an [IWSDOutboundAttachment](https://learn.microsoft.com/windows/desktop/api/wsdattachment/nn-wsdattachment-iwsdoutboundattachment) object.

## Parameters

### `ppAttachment` [out]

Returns a reference to the initialized [IWSDOutboundAttachment](https://learn.microsoft.com/windows/desktop/api/wsdattachment/nn-wsdattachment-iwsdoutboundattachment) object. Cannot be **NULL**.

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_POINTER** | *attachmentOut* is **NULL**. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |