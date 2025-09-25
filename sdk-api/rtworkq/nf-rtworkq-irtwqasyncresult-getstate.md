# IRtwqAsyncResult::GetState

## Description

Returns the state object specified by the caller in the asynchronous **Begin** method.

## Parameters

### `ppunkState` [out]

Receives a pointer to the state object's **IUnknown** interface. If the value is not **NULL**, the caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | There is no state object associated with this asynchronous result. |

## See also

[IRtwqAsyncResult](https://learn.microsoft.com/windows/desktop/api/rtworkq/nn-rtworkq-irtwqasyncresult)