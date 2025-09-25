# _WDF_FILE_INFORMATION_CLASS enumeration (wudfddi_types.h)

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **WDF_FILE_INFORMATION_CLASS** enumeration identifies the types of file information that a driver can obtain or set.

## Constants

### `WdfFileInformationDirectory`

### `WdfFileInformationFullDirectory`

### `WdfFileInformationBothDirectory`

### `WdfFileInformationBasic`

### `WdfFileInformationStandard`

### `WdfFileInformationInternal`

### `WdfFileInformationEa`

### `WdfFileInformationAccess`

### `WdfFileInformationName`

### `WdfFileInformationRename`

### `WdfFileInformationLink`

### `WdfFileInformationNames`

### `WdfFileInformationDisposition`

### `WdfFileInformationPosition`

### `WdfFileInformationFullEa`

### `WdfFileInformationMode`

### `WdfFileInformationAlignment`

### `WdfFileInformationAll`

### `WdfFileInformationAllocation`

### `WdfFileInformationEndOfFile`

### `WdfFileInformationAlternateName`

### `WdfFileInformationStream`

### `WdfFileInformationPipe`

### `WdfFileInformationPipeLocal`

### `WdfFileInformationPipeRemote`

### `WdfFileInformationMailslotQuery`

### `WdfFileInformationMailslotSet`

### `WdfFileInformationCompression`

### `WdfFileInformationObjectId`

### `WdfFileInformationCompletion`

### `WdfFileInformationMoveCluster`

### `WdfFileInformationQuota`

### `WdfFileInformationReparsePoint`

### `WdfFileInformationNetworkOpen`

### `WdfFileInformationAttributeTag`

### `WdfFileInformationTracking`

### `WdfFileInformationIdBothDirectory`

### `WdfFileInformationIdFullDirectory`

### `WdfFileInformationValidDataLength`

### `WdfFileInformationShortName`

### `WdfFileInformationIoCompletionNotification`

### `WdfFileInformationIoStatusBlockRange`

### `WdfFileInformationIoPriorityHint`

### `WdfFileInformationSfioReserve`

### `WdfFileInformationSfioVolume`

### `WdfFileInformationHardLink`

### `WdfFileInformationProcessIdsUsingFile`

### `WdfFileInformationNormalizedName`

### `WdfFileInformationNetworkPhysicalName`

### `WdfFileInformationIdGlobalTxDirectory`

### `WdfFileInformationIsRemoteDevice`

### `WdfFileInformationAttributeCache`

### `WdfFileInformationMaximum`

## Remarks

The **WDF_FILE_INFORMATION_CLASS** enumeration is used as an input value to [IWDFIoRequest2::GetQueryInformationParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest2-getqueryinformationparameters) and as an output value from [IWDFIoRequest2::GetSetInformationParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest2-getsetinformationparameters).

For most values that the **WDF_FILE_INFORMATION_CLASS** enumeration defines, the wdm.h or ntifs.h header file defines a FILE_XXXX_INFORMATION-named structure that the driver can use when obtaining or setting the file information.

For more information about the enumeration value and associated structures, see the description of the *FileInformationClass* parameter of [ZwQueryInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryinformationfile) and [ZwSetInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntsetinformationfile).

## See also

[IWDFIoRequest2::GetQueryInformationParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest2-getqueryinformationparameters)

[IWDFIoRequest2::GetSetInformationParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest2-getsetinformationparameters)