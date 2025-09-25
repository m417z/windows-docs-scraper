# IWSDAsyncResult::GetEvent

## Description

Retrieves a [WSD_EVENT](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_event) structure that contains the result of the event.

## Parameters

### `pEvent` [out]

Reference to a [WSD_EVENT](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_event) structure that provides data about the event.

## Return value

This method can return one of these values.

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_POINTER** | *pEvent* is **NULL**. |
| **E_FAIL** | Event is not yet available or the asynchronous operation has not completed. |

## Remarks

This method should only be called by [generated code](https://learn.microsoft.com/windows/desktop/WsdApi/web-services-for-devices-code-generator) and only after the [IWSDAsyncResult](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsdasyncresult) object has signaled that the operation has completed.

## See also

[IWSDAsyncResult](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsdasyncresult)