# IPortableDeviceResources::GetResourceAttributes

## Description

The **GetResourceAttributes** method retrieves all attributes from a specified resource in an object.

## Parameters

### `pszObjectID` [in]

Pointer to a null-terminated string that contains the object ID of the object hosting the resource.

### `Key` [in]

A **REFPROPERTYKEY** that specifies which resource to query.

### `ppResourceAttributes` [out]

Pointer to an [IPortableDeviceValues](https://learn.microsoft.com/windows/desktop/wpd_sdk/iportabledevicevalues) interface pointer that holds **PROPERTYKEY**/**PROPVARIANT** pairs that describe each attribute and its value, respectively. The value types of the attribute values vary. If a property could not be returned, the value for the returned property will be **VT_ERROR**, and the **PROPVARIANT** *scode* member will contain the **HRESULT** of that particular failure.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | All attribute values were retrieved. |
| **S_FALSE** | One or more attribute values could not be retrieved. These will have **HRESULT** values of type VT_ERROR in the retrieved *ppResourceAttributes* parameter. |
| **E_POINTER** | At least one of the required pointer arguments was **NULL**. |

## Remarks

Resource attributes describe the access rights, size, format, and other information related to a resource. For example, the attributes for an audio annotation resource on an image object may specify the bit rate, channel count, and data format of the audio.

## See also

[IPortableDeviceResources Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledeviceresources)