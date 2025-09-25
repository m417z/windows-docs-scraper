# IWSDMessageParameters::GetLowerParameters

## Description

Retrieves message parameters from the layer below this layer in the protocol stack.

## Parameters

### `ppTxParams` [out]

An [IWSDMessageParameters](https://learn.microsoft.com/windows/desktop/api/wsdbase/nn-wsdbase-iwsdmessageparameters) interface that you use to communicate message specific information up and down the protocol stack.

## Return value

This method can return one of these values.

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_NOTIMPL** | The method was not implemented. |

## See also

[IWSDMessageParameters](https://learn.microsoft.com/windows/desktop/api/wsdbase/nn-wsdbase-iwsdmessageparameters)