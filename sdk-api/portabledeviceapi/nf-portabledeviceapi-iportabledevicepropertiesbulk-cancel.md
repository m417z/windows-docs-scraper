# IPortableDevicePropertiesBulk::Cancel

## Description

The **Cancel** method cancels a pending properties request.

## Parameters

### `pContext` [in]

Pointer to a context GUID that was retrieved when an asynchronous request was started by calling one of the **Queue...** methods.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IPortableDevicePropertiesBulk Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledevicepropertiesbulk)