# IPortableDeviceResources::CreateResource

## Description

The **CreateResource** method creates a resource.

## Parameters

### `pResourceAttributes` [in]

Pointer to the following object parameter attributes.

| Attribute | Description |
| --- | --- |
| WPD_OBJECT_NAME | The object name. |
| WPD_RESOURCE_ATTRIBUTE_TOTAL_SIZE | The total size of the resource data stream. |
| WPD_RESOURCE_ATTRIBUTE_FORMAT | The format of the resource data stream. |
| WPD_RESOURCE_ATTRIBUTE_RESOURCE_KEY | The resource key. |

### `ppData` [out]

Pointer to a stream into which the caller can write resource data.

### `pdwOptimalWriteBufferSize` [out]

Pointer to a value that specifies the optimal buffer size when writing to the stream. This parameter is optional.

### `ppszCookie` [out]

Pointer to a cookie that identifies the resource creation request. This parameter is optional.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | At least one of the arguments was a **NULL** pointer. |

## Remarks

When an application calls this method, it must specify the resource attributes and it must write the required data to the stream that this method returns.

A resource is not created when the method returns; it is created when the application commits the data by calling the **Commit** method on the stream at which *ppData* points.

To cancel the data transfer to a resource, the application must call the **Revert** method on the stream at which *ppData* points. Once the transfer is canceled, the application must invoke **IUnknown::Release** to close the stream.

## See also

[IPortableDeviceResources Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledeviceresources)