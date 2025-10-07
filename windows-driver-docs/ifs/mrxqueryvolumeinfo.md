# MRxQueryVolumeInfo routine

The *MRxQueryVolumeInfo* routine is called by [RDBSS](https://learn.microsoft.com/windows-hardware/drivers/ifs/the-rdbss-driver-and-library) to request that a network mini-redirector query volume information.

## Parameters

*RxContext* \[in, out\]
A pointer to the RX\_CONTEXT structure. This parameter contains the IRP that is requesting the operation.

## Return value

*MRxQueryVolumeInfo* returns STATUS\_SUCCESS on success or an appropriate NTSTATUS value, such as one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_ACCESS_DENIED** | The caller lacked the proper security for this operation. |
| **STATUS_BUFFER_OVERFLOW** | The buffer to receive the volume information was too small.<br><br>This return value should be considered success and as much valid data as possible should be returned in the **Info.Buffer** member of the RX_CONTEXT structure pointed to by the *RxContext* parameter. |
| **STATUS_BUFFER_TOO_SMALL** | The buffer is too small to receive the requested data.<br><br>If this value is returned, the **InformationToReturn** member of the RX_CONTEXT structure pointed to by the *RxContext* parameter should be set to the minimum size of the expected buffer for the call to succeed. |
| **STATUS_CONNECTION_DISCONNECTED** | The connection was disconnected. |
| **STATUS_INSUFFICIENT_RESOURCES** | There were insufficient resources to complete the query. |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was specified. |
| **STATUS_NETWORK_NAME_DELETED** | A network name was deleted. |
| **STATUS_NOT_IMPLEMENTED** | A feature that is requested is not implemented. |

## Remarks

RDBSS issues a call to *MRxQueryVolumeInfo* in either of the following cases:

- RDBSS receives an [**IRP\_MJ\_QUERY\_VOLUME\_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-query-volume-information) request.

- RDBSS receives an [**IRP\_MJ\_FILE\_SYSTEM\_CONTROL**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-file-system-control) request for an FSCTL\_LMR\_GET\_LINK\_TRACKING\_INFORMATION control code.

Before calling *MRxQueryVolumeInfo* in the case of an IRP\_MJ\_QUERY\_VOLUME\_INFORMATION request, RDBSS modifies the following members in the RX\_CONTEXT structure pointed to by the *RxContext* parameter:

The **Info.FsInformationClass** member is set to **IrpSp->Parameters.QueryVolume.FsInformationClass**.

The **Info.Buffer** member is set to **Irp->AssociatedIrp.SystemBuffer**.

The **Info.LengthRemaining** member is set to **IrpSp->Parameters.QueryVolume.Length**.

For an IRP\_MJ\_QUERY\_VOLUME\_INFORMATION request, if the **PostRequest** member of the RX\_CONTEXT structure is **TRUE** on return from *MRxQueryVolumeInfo*, RDBSS will call [**RxFsdPostRequest**](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxfsdpostrequest) to post the request. For this case, the IRP\_MJ\_QUERY\_VOLUME\_INFORMATION request will pass the RX\_CONTEXT structure to queue RX\_CONTEXT to a worker queue for processing by the file system process (FSP).

If the **PostRequest** member of the RX\_CONTEXT structure is **FALSE** on return from *MRxQueryVolumeInfo*, the network mini-redirector must set the **Info.LengthRemaining** member of the RX\_CONTEXT structure to the length of the volume information returned. RDBSS sets the **IoStatus.Information** member of the IRP to **IrpSp->Parameters.QueryVolume.Length** minus the **Info.LengthRemaining** member of the RX\_CONTEXT structure.

If the call to *MRxQueryVolumeInfo* is successful, the network mini-redirector should set the **Info.LengthRemaining** member of the RX\_CONTEXT structure to the **Info.Length** member minus the length of the volume information returned. If the call to *MRxQueryVolumeInfo* was successful, RDBSS sets the **IoStatus.Information** member of the IRP to **IrpSp->Parameters.QueryVolume.Length** minus the **Info.LengthRemaining** member of the RX\_CONTEXT structure.

For an IRP\_MJ\_QUERY\_VOLUME\_INFORMATION request with the **Info.FsInformationClass** member set to **FileFsDeviceInformation**, the network mini-redirector returns the following information in the RX\_CONTEXT structure pointed to by the *RxContext* parameter:

The **Info.Buffer** member contains an FILE\_FS\_DEVICE\_INFORMATION structure

The **Info.Buffer.Characteristics** member is set to the characteristics of the volume, which must include FILE\_REMOTE\_DEVICE as one of the options.

The **Info.Buffer.DeviceType** member is set to the **DeviceType** member of the associated NET\_ROOT structure. If the **Type** member of the associated NET\_ROOT is NET\_ROOT\_PIPE, **Info.Buffer.DeviceType** member is set to FILE\_DEVICE\_NAMED\_PIPE.

For an IRP\_MJ\_QUERY\_VOLUME\_INFORMATION request with the **Info.FsInformationClass** member set to **FileFsVolumeInformation**, the network mini-redirector returns the following information in the RX\_CONTEXT structure pointed to by the *RxContext* parameter:

The **Info.Buffer** member contains a FILE\_FS\_VOLUME\_INFORMATION structure.

The **Info.Buffer** member is set to the **VolumeInfo** member of the associated NET\_ROOT structure.

The **Info.LengthRemaining** member is set to the **VolumeInfoLength** member of the associated NET\_ROOT structure.

An *MRxQueryVolumeInfo* call from RDBSS for [**IRP\_MJ\_FILE\_SYSTEM\_CONTROL**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-file-system-control) is a request for the link tracking information. Before calling *MRxQueryVolumeInfo* for IRP\_MJ\_FILE\_SYSTEM\_CONTROL, RDBSS modifies the following members in the RX\_CONTEXT structure pointed to by the *RxContext* parameter:

The **Info.FsInformationClass** member is set to **FileFsObjectIdInformation**.

The **Info.Buffer** member is set to a FILE\_FS\_OBJECTID\_INFORMATION structure.

The **Info.LengthRemaining** member is set to **sizeof**(FILE\_FS\_OBJECTID\_INFORMATION).

For this case of an IRP\_MJ\_FILE\_SYSTEM\_CONTROL request, the **AssociatedIrp.SystemBuffer** member of the IRP points to a LINK\_TRACKING\_INFORMATION structure.

If a request is initiated as an IRP\_MJ\_FILE\_SYSTEM\_CONTROL to *MRxQueryVolumeInfo* with a return value of STATUS\_SUCCESS or STATUS\_BUFFER\_OVERFLOW, RDBSS copies the **ObjectId** member of the FILE\_FS\_OBJECTID\_INFORMATION structure passed in the **Info.Buffer** member of RX\_CONTEXT structure to the **NetRoot->DiskParameters.VolumeId** member of the FCB structure and to the **AssociatedIrp.SystemBuffer.VolumeId** member of the IRP. If the call to *MRxQueryVolumeInfo* was successful, RDBSS sets the **Type** member of the LINK\_TRACKING\_INFORMATION structure. If the **NetRoot->Flags** member of the FCB structure has the NETROOT\_FLAG\_DFS\_AWARE\_NETROOT bit set, the **Type** member is set by RDBSS to **DfsLinkTrackingInformation**. If the **NetRoot->Flags** member of the FCB structure does not have the NETROOT\_FLAG\_DFS\_AWARE\_NETROOT bit set, the **Type** member is set by RDBSS to **NtfsLinkTrackingInformation**. On success, RDBSS sets the **IoStatus.Information** member of the IRP to the size of a LINK\_TRACKING\_INFORMATION structure.

## Requirements

|  |  |
| --- | --- |
| Target platform | Desktop |
| Header | Mrx.h (include Mrx.h) |

## See also

[**MRxIsValidDirectory**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_chkdir_calldown)

[**MRxQueryDirectory**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxquerydirectory)

[**MRxQueryEaInfo**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxqueryeainfo)

[**MRxQueryFileInfo**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxqueryfileinfo)

[**MRxQueryQuotaInfo**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxqueryquotainfo)

[**MRxQuerySdInfo**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxquerysdinfo)

[**MRxSetEaInfo**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxseteainfo)

[**MRxSetFileInfo**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxsetfileinfo)

[**MRxSetFileInfoAtCleanup**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxsetfileinfoatcleanup)

[**MRxSetQuotaInfo**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxsetquotainfo)

[**MRxSetSdInfo**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxsetsdinfo)

[**MRxSetVolumeInfo**](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxsetvolumeinfo)

[**RxFsdPostRequest**](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxfsdpostrequest)

