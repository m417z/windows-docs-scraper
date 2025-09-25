# IWSDMessageParameters::GetRemoteAddress

## Description

Retrieves the generic address object representing the remote address from which the message was sent.

## Parameters

### `ppAddress` [out]

An [IWSDAddress](https://learn.microsoft.com/windows/desktop/api/wsdbase/nn-wsdbase-iwsdaddress) interface that represents the remote address from which the message was sent.

## Return value

This method can return one of these values.

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_POINTER** | *ppAddress* is **NULL**. |

## Remarks

The caller is responsible for releasing memory allocated to *ppAddress*.

## See also

[IWSDMessageParameters](https://learn.microsoft.com/windows/desktop/api/wsdbase/nn-wsdbase-iwsdmessageparameters)