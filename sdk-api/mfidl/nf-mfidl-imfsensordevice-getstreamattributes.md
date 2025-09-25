# IMFSensorDevice::GetStreamAttributes

## Description

Gets the stream attribute store with the specified index.

## Parameters

### `eType` [in]

A member of the [MFSensorStreamType](https://learn.microsoft.com/windows/win32/api/mfidl/ne-mfidl-mfsensorstreamtype) enumeration specifying whether the attribute store is being requested for an input or output stream.

### `dwIndex` [in]

The 0-based index of the stream to be retrieved. The index must be between 0 and the value returned by [GetStreamAttributesCount](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfsensordevice-getstreamattributescount) - 1.

### `ppAttributes` [out]

The [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) interface representing a copy internal attribute store of the stream.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *pDeviceId* parameter is null. |
| **MF_E_NOT_INITIALIZED** | The sensor group has not been initialized. |

## Remarks

The object returned is a copy of the internal attribute store and so changes made to the returned attributes have no effect on the [IMFSensorDevice](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensordevice).

## See also

[IMFSensorDevice](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensordevice)