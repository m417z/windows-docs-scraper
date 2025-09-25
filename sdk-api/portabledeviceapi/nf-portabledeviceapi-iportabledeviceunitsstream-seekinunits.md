# IPortableDeviceUnitsStream::SeekInUnits

## Description

The **SeekInUnits** method performs a seek on a stream, based on alternate units.

## Parameters

### `dlibMove` [in]

The displacement to add to the location indicated by the *dwOrigin* parameter. The units for the displacement are specified by *units*. If *dwOrigin* is [STREAM_SEEK_SET](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istream-seek), this is interpreted as an unsigned value rather than a signed value.

### `units` [in]

The units of the *dlibMove* and *plibNewPosition* parameters. See [WPD_STREAM_UNITS](https://learn.microsoft.com/windows/desktop/wpd_sdk/wpd-stream-units) for more details.

### `dwOrigin` [in]

The origin for the displacement specified in *dlibMove*. The origin can be the beginning of the file (STREAM_SEEK_SET), the current seek pointer (STREAM_SEEK_CUR), or the end of the file (STREAM_SEEK_END). For more information about values, see the [STREAM_SEEK](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istream-seek) enumeration.

### `plibNewPosition` [out, optional]

A pointer to the location where this method writes the value of the new seek pointer from the beginning of the stream. The units are given by units.
You can set this pointer to NULL. In this case, this method does not provide the new seek pointer.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The seek pointer was successfully adjusted. |
| **STG_E_INVALIDPOINTER** | Indicates that the [out] parameter *plibNewPosition* points to invalid memory, because *plibNewPosition* is not read. |
| **STG_E_INVALIDFUNCTION** | The *dwUnits* or *dwOrigin* parameter contains an invalid value, or the *dlibMove* parameter contains a bad offset value. For example, the result of the seek pointer is a negative offset value. |

## See also

[IPortableDeviceUnitsStream](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledeviceunitsstream)

[WPD_STREAM_UNITS](https://learn.microsoft.com/windows/desktop/wpd_sdk/wpd-stream-units)