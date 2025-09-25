# IMFContentProtectionManager::EndEnableContent

## Description

Ends an asynchronous request to perform a content enabling action. This method is called by the protected media path (PMP) to complete an asynchronous call to [IMFContentProtectionManager::BeginEnableContent](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfcontentprotectionmanager-beginenablecontent).

## Parameters

### `pResult` [in]

Pointer to the [IMFAsyncResult](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfasyncresult) interface. This pointer is the same value that the application passed to the caller's [IMFAsyncCallback::Invoke](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfasynccallback-invoke) method.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

When the [BeginEnableContent](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfcontentprotectionmanager-beginenablecontent) method completes asynchronously, the application notifies the PMP by invoking the asynchronous callback. The PMP calls **EndEnableContent** on the application to get the result code. This method is called on the application's thread from inside the callback method. Therefore, it must not block the thread that invoked the callback.

The application must return the success or failure code of the asynchronous processing that followed the call to [BeginEnableContent](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfcontentprotectionmanager-beginenablecontent).

## See also

[IMFContentProtectionManager](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfcontentprotectionmanager)