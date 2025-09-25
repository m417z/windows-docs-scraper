# IWSDUdpMessageParameters::GetRetransmitParams

## Description

Retrieves the values that WSD uses to determine how often to repeat the message transmission.

## Parameters

### `pParams` [out]

Pointer to a [WSDUdpRetransmitParams](https://learn.microsoft.com/windows/desktop/api/wsdbase/ns-wsdbase-wsdudpretransmitparams) structure. The structure contains values that determine how often WSD repeats the message transmission.

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_POINTER** | *pParams* is **NULL**. |

## See also

[IWSDUdpMessageParameters](https://learn.microsoft.com/windows/desktop/api/wsdbase/nn-wsdbase-iwsdudpmessageparameters)