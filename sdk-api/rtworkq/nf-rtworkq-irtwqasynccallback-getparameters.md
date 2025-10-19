# IRtwqAsyncCallback::GetParameters

## Description

Provides configuration information to the dispatching thread for a callback.

## Parameters

### `pdwFlags` [out]

Receives a flag indicating the behavior of the callback object's [IRtwqAsyncCallback::Invoke](https://learn.microsoft.com/windows/desktop/api/rtworkq/nf-rtworkq-irtwqasynccallback-invoke) method. The following values are defined. The default value is zero.

| Value | Meaning |
| --- | --- |
| **Zero** | The callback does not take a long time to complete, but has no specific restrictions on what system calls it makes. The callback generally takes less than 30 milliseconds to complete. |

### `pdwQueue` [out]

Receives the identifier of the work queue on which the callback is dispatched.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_NOTIMPL** | Not implemented. Assume the default behavior. |

## See also

[IRtwqAsyncCallback](https://learn.microsoft.com/windows/desktop/api/rtworkq/nn-rtworkq-irtwqasynccallback)