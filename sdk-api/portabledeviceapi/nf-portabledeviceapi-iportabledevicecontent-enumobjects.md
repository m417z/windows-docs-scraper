# IPortableDeviceContent::EnumObjects

## Description

The **EnumObjects** method retrieves an interface that is used to enumerate the immediate child objects of an object. It has an optional filter that can enumerate objects with specific properties.

## Parameters

### `dwFlags` [in]

Currently ignored; specify zero.

### `pszParentObjectID` [in]

Pointer to a null-terminated string that specifies the ID of the parent. This can be an empty string (but not a **NULL** pointer) or the defined constant **WPD_DEVICE_OBJECT_ID** to indicate the device root.

### `pFilter` [in]

This parameter is ignored and should be set to **NULL**.

### `ppEnum` [out]

Address of a variable that receives a pointer to an [IEnumPortableDeviceObjectIDs](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-ienumportabledeviceobjectids) interface that is used to enumerate the objects that are found. The caller must release this interface when it is done with it.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | At least one of the required arguments was a **NULL** pointer. |

## See also

[Enumerating Content](https://learn.microsoft.com/windows/desktop/wpd_sdk/enumerating-content)

[Enumerating Service Content](https://learn.microsoft.com/windows/desktop/wpd_sdk/enumerating-service-content)

[IPortableDeviceContent](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledevicecontent-enumobjects)

[IPortableDeviceContent Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledevicecontent)