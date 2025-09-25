# IMFAsyncResult::GetState

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

## Remarks

The caller of the asynchronous method specifies the state object, and can use it for any caller-defined purpose. The state object can be **NULL**. If the state object is **NULL**, **GetState** returns **E_POINTER**.

If you are implementing an asynchronous method, set the state object on the through the *punkState* parameter of the [MFCreateAsyncResult](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfcreateasyncresult) function.

This interface is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[Asynchronous Callback Methods](https://learn.microsoft.com/windows/desktop/medfound/asynchronous-callback-methods)

[IMFAsyncResult](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfasyncresult)