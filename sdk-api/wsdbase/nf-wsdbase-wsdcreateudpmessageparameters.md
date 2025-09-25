# WSDCreateUdpMessageParameters function

## Description

Retrieves a pointer to the [IWSDUdpMessageParameters](https://learn.microsoft.com/windows/desktop/api/wsdbase/nn-wsdbase-iwsdudpmessageparameters) interface.

## Parameters

### `ppTxParams` [out]

Pointer to the [IWSDUdpMessageParameters](https://learn.microsoft.com/windows/desktop/api/wsdbase/nn-wsdbase-iwsdudpmessageparameters) interface that you use to specify how often WSD repeats the message transmission.

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_POINTER** | *ppTxParams* is **NULL**. |