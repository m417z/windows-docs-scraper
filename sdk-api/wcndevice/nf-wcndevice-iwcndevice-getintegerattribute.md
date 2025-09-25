# IWCNDevice::GetIntegerAttribute

## Description

The [GetIntegerAttribute](https://learn.microsoft.com/windows/desktop/api/wcndevice/nf-wcndevice-iwcndevice-getstringattribute) method gets a cached attribute from the device as an integer.

## Parameters

### `AttributeType` [in]

A **WCN_ATTRIBUTE_TYPE** value that represents a specific attribute value (for example, **WCN_PASSWORD_TYPE**).

### `puInteger` [out]

Pointer to an unsigned-integer that represents the retrieved attribute value.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The attribute was retrieved successfully. |
| **HRESULT_FROM_WIN32(ERROR_NOT_FOUND)** | The attribute specified is not available. |
| **HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER)** | The buffer specified by *pbBuffer* is not large enough to contain the returned attribute value. |
| **HRESULT_FROM_WIN32(ERROR_INVALID_DATATYPE)** | This attribute cannot be expressed as an integer. For example, if it is a string. |

## See also

[IWCNDevice](https://learn.microsoft.com/windows/desktop/api/wcndevice/nn-wcndevice-iwcndevice)

**WCN_ATTRIBUTE_TYPE**