# IWSDMessageParameters::GetLocalAddress

## Description

Retrieves the generic address object representing the local address that received the message.

## Parameters

### `ppAddress` [out]

An [IWSDAddress](https://learn.microsoft.com/windows/desktop/api/wsdbase/nn-wsdbase-iwsdaddress) interface that represents the local address that received the message.

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