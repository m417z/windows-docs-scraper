# IMFAsyncResult::GetObject

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

## Remarks

Typically, this object is used by the component that implements the asynchronous method. It provides a way for the function that invokes the callback to pass information to the asynchronous **End...** method that completes the operation.

If you are implementing an asynchronous method, you can set the object through the *punkObject* parameter of the [MFCreateAsyncResult](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfcreateasyncresult) function.

If the asynchronous result object's internal **IUnknown** pointer is **NULL**, the method returns **E_POINTER**.

This interface is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[Asynchronous Callback Methods](https://learn.microsoft.com/windows/desktop/medfound/asynchronous-callback-methods)

[IMFAsyncResult](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfasyncresult)