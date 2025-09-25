# IPortableDeviceContent2::UpdateObjectWithPropertiesAndData

## Description

The **UpdateObjectWithPropertiesAndData** method updates an object by using properties and data found on the device.

## Parameters

### `pszObjectID` [in]

The identifier of the object to update.

### `pProperties` [in]

The [IPortableDeviceValues](https://learn.microsoft.com/windows/desktop/wpd_sdk/iportabledevicevalues) interface that specifies the object properties to be updated.

### `ppData` [out]

The **IStream** interface through which the object data is sent to the device.

### `pdwOptimalWriteBufferSize` [in, out]

The optimal buffer size for writing the object data to *ppData*, or **NULL** if the buffer size is ignored.

## Return value

If the method succeeds, it returns **S_OK**. Any other **HRESULT** value indicates that the call failed.

## Remarks

Device formats and object formats can derive some of their object properties from the data itself. Or, they can have property values that depend on the data. For example, a music track has a duration property that is specified when an application calls the [IPortableDeviceContent::CreateObjectWithPropertiesAndData](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledevicecontent-createobjectwithpropertiesanddata) method. If this track is stored as a default resource ([WPD_RESOURCE_DEFAULT](https://learn.microsoft.com/windows/desktop/wpd_sdk/wpd-resource-default)), the application might update it. The application additionally mighthave to update the duration property. This method lets the application perform both updates at the same time.

An update is incomplete until the **IStream::Commit** method is called on the object referenced by the *ppData* parameter.

To abandon a data transfer in progress, an application should call the **IStream::Revert** method on the object referenced by the *ppData* parameter.

The **IStream** interface object referenced by the *ppData* parameter must be released after the update operation is complete, or, is canceled.