# IPortableDeviceContent::GetObjectIDsFromPersistentUniqueIDs

## Description

The **GetObjectIDsFromPersistentUniqueIDs** method retrieves the current object ID of one or more objects, given their persistent unique IDs (PUIDs).

## Parameters

### `pPersistentUniqueIDs` [in]

Pointer to an [IPortableDevicePropVariantCollection](https://learn.microsoft.com/windows/desktop/wpd_sdk/iportabledevicepropvariantcollection) interface that contains one or more persistent unique ID (PUID) string values (type VT_LPWSTR).

### `ppObjectIDs` [out]

Pointer to an **IPortableDevicePropVariantCollection** interface pointer that contains the retrieved object IDs, as type **VT_LPWSTR**. The retrieved IDs will be in the same order as the submitted PUIDs; if a value could not be found, it is indicated by an empty string. The caller must release this interface when it is done with it.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | At least one of the required arguments was a **NULL** pointer. |

## Remarks

Windows Portable Devices Object IDs are unique across the device, but may be different across sessions. An Object ID can change when the application reconnects to the device.

Certain applications, such as synchronization engines, require a way to identify the object across connection sessions. Every object has a WPD_OBJECT_PERSISTENT_UNIQUE_ID property, which indicates an identifier that is persistent across sessions. Applications can read and save this property in their initial session, by calling the [Properties](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledevicecontent-properties) method.

#### Examples

For an example of how to use this method, see [Retrieving an Object Identifier from a Persistent Unique Identifier](https://learn.microsoft.com/windows/desktop/wpd_sdk/retrieving-an-object-identifier-from-a-persistent-unique-identifier)

## See also

[IPortableDeviceContent Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledevicecontent)

[Retrieving an Object Identifier from a Persistent Unique Identifier](https://learn.microsoft.com/windows/desktop/wpd_sdk/retrieving-an-object-identifier-from-a-persistent-unique-identifier)