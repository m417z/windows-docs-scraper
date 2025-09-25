# IWMDMDeviceControl::Seek

## Description

The **Seek** method seeks to a position that is used as the starting point by the [Play](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmdevicecontrol-play) or [Record](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmdevicecontrol-record) methods.

## Parameters

### `fuMode` [in]

Mode for the seek operation being performed. The *fuMode* parameter must be one of the following modes.

| Mode | Description |
| --- | --- |
| WMDM_SEEK_BEGIN | Seek to a position that is *nOffset* units after the beginning of the file. |
| WMDM_SEEK_CURRENT | Seek to a position that is *nOffset* units from the current position. |
| WMDM_SEEK_END | Seek to a position that is *nOffset* units before the end of the file. |
| WMDM_SEEK_REMOTECONTROL | Seek the removable control. |
| WMDM_SEEK_STREAMINGAUDIO | Seek the streaming audio. |

### `nOffset` [in]

Number of units by which the seek operation moves the starting position away from the origin specified by *fuMode*. The units of *nOffset* are defined by the content. They can be milliseconds for music, pages for electronic books, and so on.

A positive value for *nOffset* indicates seeking forward through the file. A negative value indicates seeking backward through the file. Any combination of *nOffset* and *fuMode* that indicates seeking to a position before the beginning of the file or after the end of the file is not valid, and causes the method to return E_INVALIDARG.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | One or more parameters are invalid. |
| **WMDM_E_NOTSUPPORTED** | Seek is not implemented on this device. |
| **E_FAIL** | An unspecified error occurred. |

## Remarks

The seek position is defined by passing either an [IWMDMStorage](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmstorage) interface pointing to a location on a storage medium of the device, or an [IWMDMOperation](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmoperation) interface that has been implemented to support streaming audio. The **IWMDMObjectInfo** interface can also be passed to describe some point within the object to which the specified interface points.

For device playback, if **Seek** is not called before [Play](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmdevicecontrol-play), then playback starts at the first audio track on the first storage medium on the media device.

For device recording, if **Seek** is not called before [Record](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmdevicecontrol-record), the record operation fails. The recording length can be limited by calling the [IWMDMObjectInfo::SetPlayLength](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmobjectinfo-setplaylength) method after returning from the **Seek** call.

## See also

[IWMDMDeviceControl Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmdevicecontrol)

[IWMDMObjectInfo Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmobjectinfo)

[IWMDMOperation Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmoperation)

[IWMDMStorage Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmstorage)