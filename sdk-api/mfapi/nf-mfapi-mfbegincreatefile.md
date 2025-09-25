# MFBeginCreateFile function

## Description

Begins an asynchronous request to create a byte stream from a file.

## Parameters

### `AccessMode` [in]

The requested access mode, specified as a member of the [MF_FILE_ACCESSMODE](https://learn.microsoft.com/windows/win32/api/mfobjects/ne-mfobjects-mf_file_accessmode) enumeration.

### `OpenMode` [in]

The behavior of the function if the file already exists or does not exist, specified as a member of the [MF_FILE_OPENMODE](https://learn.microsoft.com/windows/win32/api/mfobjects/ne-mfobjects-mf_file_openmode) enumeration.

### `fFlags` [in]

Bitwise **OR** of values from the [MF_FILE_FLAGS](https://learn.microsoft.com/windows/win32/api/mfobjects/ne-mfobjects-mf_file_flags) enumeration.

### `pwszFilePath` [in]

Pointer to a null-terminated string containing the file name.

### `pCallback` [in]

Pointer to the [IMFAsyncCallback](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfasynccallback) interface of a callback object. The caller must implement this interface

### `pState` [in]

Pointer to the **IUnknown** interface of a state object, defined by the caller. This parameter can be **NULL**. You can use this object to hold state information. The object is returned to the caller when the callback is invoked.

### `ppCancelCookie` [out]

Receives an **IUnknown** pointer or the value **NULL**. If the value is not **NULL**, you can cancel the asynchronous operation by passing this pointer to the [MFCancelCreateFile](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfcancelcreatefile) function. The caller must release the interface. This parameter is optional and can be **NULL**.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. |

## Remarks

When the request is completed, the callback object's [IMFAsyncCallback::Invoke](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfasynccallback-invoke) method is called. The callback object should then call the [MFEndCreateFile](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfendcreatefile) function to get a pointer to the byte stream.

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)