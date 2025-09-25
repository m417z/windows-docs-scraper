# IWICMetadataHandlerInfo::GetDeviceManufacturer

## Description

Retrieves the device manufacturer of the metadata handler.

## Parameters

### `cchDeviceManufacturer` [in]

Type: **UINT**

The size of the *wzDeviceManufacturer* buffer.

### `wzDeviceManufacturer` [in, out]

Type: **WCHAR***

Pointer to the buffer that receives the name of the device manufacturer.

### `pcchActual` [out]

Type: **UINT***

The actual string buffer length needed to obtain the entire name of the device manufacturer.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.