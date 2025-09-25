# IWCNDevice::GetAttribute

## Description

The **IWCNDevice::GetAttribute** method gets a cached attribute from the device.

## Parameters

### `AttributeType` [in]

A **WCN_ATTRIBUTE_TYPE** value that represents a specific attribute value (for example, **WCN_PASSWORD_TYPE**).

### `dwMaxBufferSize` [in]

The allocated size, in bytes, of *pbBuffer*.

### `pbBuffer` [out]

A user-allocated buffer that, on successful return, contains the contents of the attribute.

### `pdwBufferUsed` [out]

On return, contains the size of the attribute in bytes.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The attribute was retrieved successfully. |
| **HRESULT_FROM_WIN32(ERROR_NOT_FOUND)** | The attribute specified is not available. |
| **HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER)** | The buffer specified by *pbBuffer* is not large enough to contain the returned attribute value. |

## Remarks

To only query the size of an attribute, a value of 0 (zero) can be passed via *dwMaxBufferSize* and *pdwBufferUsed* will be filled appropriately.

## See also

[IWCNDevice](https://learn.microsoft.com/windows/desktop/api/wcndevice/nn-wcndevice-iwcndevice)

**WCN_ATTRIBUTE_TYPE**