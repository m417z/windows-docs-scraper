# IWCNDevice::GetStringAttribute

## Description

The **IWCNDevice::GetStringAttribute** method gets a cached attribute from the device as a string.

## Parameters

### `AttributeType` [in]

A **WCN_ATTRIBUTE_TYPE** value that represents a specific attribute value (for example, **WCN_PASSWORD_TYPE**). If the attribute is not natively a string data type (for example, **WCN_TYPE_VERSION** is natively an integer, and **WNC_TYPE_SSID** is natively a blob), this function will fail with **HRESULT_FROM_WIN32(ERROR_INVALID_DATATYPE)**.

### `cchMaxString` [in]

The size of the buffer *wszString*, in characters.

### `wszString` [out]

A user-allocated buffer that, on successful return, contains a **NULL**-terminated string value of the vendor extension.

## Return value

...

| Return code | Description |
| --- | --- |
| **S_OK** | The attribute was retrieved successfully. |
| **HRESULT_FROM_WIN32(ERROR_NOT_FOUND)** | The attribute specified is not available. |
| **HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER)** | The buffer specified by *wszString* is not large enough to contain the returned attribute value. |
| **HRESULT_FROM_WIN32(ERROR_INVALID_DATATYPE)** | This attribute cannot be expressed as a string. For example, if it is an integer. |

## See also

[IWCNDevice](https://learn.microsoft.com/windows/desktop/api/wcndevice/nn-wcndevice-iwcndevice)

**WCN_ATTRIBUTE_TYPE**