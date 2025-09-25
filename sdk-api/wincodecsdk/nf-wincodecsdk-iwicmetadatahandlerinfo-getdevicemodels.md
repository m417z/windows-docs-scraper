# IWICMetadataHandlerInfo::GetDeviceModels

## Description

Retrieves the device models that support the metadata handler.

## Parameters

### `cchDeviceModels` [in]

Type: **UINT**

The length of the *wzDeviceModels* buffer.

### `wzDeviceModels` [in, out]

Type: **WCHAR***

Pointer that receives the device models supported by the metadata handler.

### `pcchActual` [out]

Type: **UINT***

The actual length needed to retrieve the device models.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.