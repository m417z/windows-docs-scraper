# IRtwqAsyncResult::GetObject

## Description

Returns an object associated with the asynchronous operation. The type of object, if any, depends on the asynchronous method that was called.

## Parameters

### `ppObject` [out]

Receives a pointer to the object's **IUnknown** interface. If no object is associated with the operation, this parameter receives the value **NULL**. If the value is not **NULL**, the caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | There is no object associated with this asynchronous result. |

## See also

[IRtwqAsyncResult](https://learn.microsoft.com/windows/desktop/api/rtworkq/nn-rtworkq-irtwqasyncresult)