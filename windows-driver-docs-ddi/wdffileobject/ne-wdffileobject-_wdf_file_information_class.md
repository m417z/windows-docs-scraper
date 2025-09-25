# _WDF_FILE_INFORMATION_CLASS enumeration (wdffileobject.h)

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **WDF_FILE_INFORMATION_CLASS** enumeration identifies the types of file information that a driver can obtain or set.

## Constants

### `WdfFileInformationDirectory:1`

### `WdfFileInformationFullDirectory:2`

### `WdfFileInformationBothDirectory:3`

### `WdfFileInformationBasic:4`

### `WdfFileInformationStandard:5`

### `WdfFileInformationInternal:6`

### `WdfFileInformationEa:7`

### `WdfFileInformationAccess:8`

### `WdfFileInformationName:9`

### `WdfFileInformationRename:10`

### `WdfFileInformationLink:11`

### `WdfFileInformationNames:12`

### `WdfFileInformationDisposition:13`

### `WdfFileInformationPosition:14`

### `WdfFileInformationFullEa:15`

### `WdfFileInformationMode:16`

### `WdfFileInformationAlignment:17`

### `WdfFileInformationAll:18`

### `WdfFileInformationAllocation:19`

### `WdfFileInformationEndOfFile:20`

### `WdfFileInformationAlternateName:21`

### `WdfFileInformationStream:22`

### `WdfFileInformationPipe:23`

### `WdfFileInformationPipeLocal:24`

### `WdfFileInformationPipeRemote:25`

### `WdfFileInformationMailslotQuery:26`

### `WdfFileInformationMailslotSet:27`

### `WdfFileInformationCompression:28`

### `WdfFileInformationObjectId:29`

### `WdfFileInformationCompletion:30`

### `WdfFileInformationMoveCluster:31`

### `WdfFileInformationQuota:32`

### `WdfFileInformationReparsePoint:33`

### `WdfFileInformationNetworkOpen:34`

### `WdfFileInformationAttributeTag:35`

### `WdfFileInformationTracking:36`

### `WdfFileInformationIdBothDirectory:37`

### `WdfFileInformationIdFullDirectory:38`

### `WdfFileInformationValidDataLength:39`

### `WdfFileInformationShortName:40`

### `WdfFileInformationIoCompletionNotification:41`

### `WdfFileInformationIoStatusBlockRange:42`

### `WdfFileInformationIoPriorityHint:43`

### `WdfFileInformationSfioReserve:44`

### `WdfFileInformationSfioVolume:45`

### `WdfFileInformationHardLink:46`

### `WdfFileInformationProcessIdsUsingFile:47`

### `WdfFileInformationNormalizedName:48`

### `WdfFileInformationNetworkPhysicalName:49`

### `WdfFileInformationIdGlobalTxDirectory:50`

### `WdfFileInformationIsRemoteDevice:51`

### `WdfFileInformationAttributeCache:52`

### `WdfFileInformationMaximum:`

## Remarks

The **WDF_FILE_INFORMATION_CLASS** enumeration is used as an input value to [IWDFIoRequest2::GetQueryInformationParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest2-getqueryinformationparameters) and as an output value from [IWDFIoRequest2::GetSetInformationParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest2-getsetinformationparameters).

For most values that the **WDF_FILE_INFORMATION_CLASS** enumeration defines, the wdm.h or ntifs.h header file defines a FILE_XXXX_INFORMATION-named structure that the driver can use when obtaining or setting the file information.

For more information about the enumeration value and associated structures, see the description of the *FileInformationClass* parameter of [ZwQueryInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryinformationfile) and [ZwSetInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntsetinformationfile).

## See also

[IWDFIoRequest2::GetQueryInformationParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest2-getqueryinformationparameters)

[IWDFIoRequest2::GetSetInformationParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest2-getsetinformationparameters)