# IMFByteStreamHandler::EndCreateObject

## Description

Completes an asynchronous request to create a media source.

## Parameters

### `pResult` [in]

Pointer to the [IMFAsyncResult](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfasyncresult) interface. Pass in the same pointer that your callback object received in the [Invoke](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfasynccallback-invoke) method.

### `pObjectType` [out]

Receives a member of the [MF_OBJECT_TYPE](https://learn.microsoft.com/windows/desktop/api/mfidl/ne-mfidl-mf_object_type) enumeration, specifying the type of object that was created.

### `ppObject` [out]

Receives a pointer to the **IUnknown** interface of the media source. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_ABORT** | The operation was canceled. See [IMFByteStreamHandler::CancelObjectCreation](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfbytestreamhandler-cancelobjectcreation). |
| **MF_E_CANNOT_PARSE_BYTESTREAM** | Unable to parse the byte stream. |

## Remarks

Call this method from inside the [IMFAsyncCallback::Invoke](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfasynccallback-invoke) method.

## See also

[IMFByteStreamHandler](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfbytestreamhandler)

[Scheme Handlers and Byte-Stream Handlers](https://learn.microsoft.com/windows/desktop/medfound/scheme-handlers-and-byte-stream-handlers)