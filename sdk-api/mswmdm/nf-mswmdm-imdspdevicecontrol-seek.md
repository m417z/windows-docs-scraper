# IMDSPDeviceControl::Seek

## Description

The **Seek** method seeks to a position that is used as the starting point by the [Play](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspdevicecontrol-play) or [Record](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspdevicecontrol-record) methods.

## Parameters

### `fuMode` [in]

Mode for the seek operation being performed. The *fuMode* parameter must be one of the following modes.

| Mode | Description |
| --- | --- |
| MDSP_SEEK_BOF | Seek to a position that is *nOffset* units after the beginning of the file. |
| MDSP_SEEK_CUR | Seek to a position that is *nOffset* units from the current position. |
| MDSP_SEEK_EOF | Seek to a position that is *nOffset* units before the end of the file. |

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

The seek position is defined by passing either an [IWMDMStorage](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmstorage) interface pointing to a location on a storage medium of the device, or an [IWMDMOperation](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmoperation) interface that has been implemented to support streaming audio. The [IMDSPObjectInfo](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspobjectinfo) interface can also be passed to describe some point within the object to which the specified interface points.

For device playback, if **Seek** is not called before [Play](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspdevicecontrol-play), then playback starts at the first audio track on the first storage medium on the media device.

For device recording, if **Seek** is not called before [Record](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspdevicecontrol-record), the record operation fails. After the **Record** method is called, subsequent calls to the [IMDSPObjectInfo::GetLastPlayPosition](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspobjectinfo-getlastplayposition) method report the total play length at any time, and equal the value returned from [IMDSPObjectInfo::GetTotalLength](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspobjectinfo-gettotallength). The recording length can be limited by calling the [IMDSPObjectInfo::SetPlayLength](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspobjectinfo-setplaylength) method after returning from the **Seek** call.

## See also

[IMDSPDeviceControl Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspdevicecontrol)

[IMDSPObjectInfo Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspobjectinfo)

[IWMDMOperation Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmoperation)

[IWMDMStorage Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmstorage)