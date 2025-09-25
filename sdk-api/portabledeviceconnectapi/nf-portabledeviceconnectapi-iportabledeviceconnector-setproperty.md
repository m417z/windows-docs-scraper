# IPortableDeviceConnector::SetProperty

## Description

The **SetProperty** method sets the given property on the MTP/Bluetooth Bus Enumerator device.

## Parameters

### `pPropertyKey` [in]

A pointer to a property key for the given property.

### `PropertyType` [in]

The property type.

### `pData` [in]

A pointer to the property data.

### `cbData` [in]

The size (in bytes) of the property data.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **HRESULT_FROM_WIN32(ERROR_NOT_FOUND)** | The specified property key is not supported. |

## Remarks

Before calling this method, an application must verify that it has Administrator user rights.

## See also

[IPortableDeviceConnector](https://learn.microsoft.com/windows/desktop/api/portabledeviceconnectapi/nn-portabledeviceconnectapi-iportabledeviceconnector)