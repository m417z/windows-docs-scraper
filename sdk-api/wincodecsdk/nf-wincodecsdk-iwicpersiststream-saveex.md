# IWICPersistStream::SaveEx

## Description

Saves the [IWICPersistStream](https://learn.microsoft.com/windows/desktop/api/wincodecsdk/nn-wincodecsdk-iwicpersiststream) to the given input [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) using the given parameters.

## Parameters

### `pIStream` [in]

Type: **[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)***

The stream to save to.

### `dwPersistOptions` [in]

Type: **DWORD**

The [WICPersistOptions](https://learn.microsoft.com/windows/desktop/api/wincodecsdk/ne-wincodecsdk-wicpersistoptions) to use when saving.

### `fClearDirty` [in]

Type: **BOOL**

Indicates whether the "dirty" value will be cleared from all metadata after saving.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.