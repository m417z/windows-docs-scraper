# IWICPersistStream::LoadEx

## Description

Loads data from an input stream using the given parameters.

## Parameters

### `pIStream` [in]

Type: **[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)***

Pointer to the input stream.

### `pguidPreferredVendor` [in]

Type: **const GUID***

Pointer to the GUID of the preferred vendor .

### `dwPersistOptions` [in]

Type: **DWORD**

The [WICPersistOptions](https://learn.microsoft.com/windows/desktop/api/wincodecsdk/ne-wincodecsdk-wicpersistoptions) used to load the stream.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

NULL can be passed in for *pguidPreferredVendor* to indicate no preference.