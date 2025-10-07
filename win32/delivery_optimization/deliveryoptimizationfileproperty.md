# DeliveryOptimizationFileProperty enumeration

The DeliveryOptimizationFileProperty enumeration specifies the ID of an optional property for the Delivery Optimization file. This enumeration is used in the IDeliveryOptimizationFile2 interface where the property value of type VARIANT is passed

## Constants

DOFilePropertyId_DecryptionInfo

The DOFilePropertyId_DecryptionInfo property ID sets decryption information in the form of a JSON string. DOFilePropertyId_DecryptionInfo is a Write only property of type VT_BSTR.

DOFilePropertyId_IntegrityCheckInfo

The DOFilePropertyId_IntegrityCheckInfo property ID sets the piece hash file (PHF) location, which is used by Delivery Optimization to perform runtime integrity checks on the downloaded content. DOFilePropertyId_IntegrityCheckInfo is a Write only property of type VT_BSTR.

DOFilePropertyId_IntegrityCheckMandatory

The DOFilePropertyId_IntegrityCheckMandatory property ID sets a boolean flag indicating whether usage of the PHF is mandatory. If TRUE, the download will be aborted once the integrity check is failed. DOFilePropertyId_IntegrityCheckMandatory is a Read/Write property of type VT_BOOL.

DOFilePropertyId_DownloadSinkFilePath

The DOFilePropertyId_DownloadSinkFilePath property ID sets a fully qualified file system location where Delivery Optimization should store the downloaded pieces. DOFilePropertyId_DownloadSinkFilePath is of type VT_BSTR.

DOFilePropertyId_DownloadSinkMemoryStream

The DOFilePropertyId_DownloadSinkMemoryStream property ID is deprecated. Do not use.

DOFilePropertyId_TotalSizeBytes

The DOFilePropertyId_TotalSizeBytes property ID specifies the total download size. DOFilePropertyId_TotalSizeBytes is of type VT_UI8.

## Requirements

| Requirement | Value |
|-------------------------------|----------------------------------------------------------|
| Minimum supported client<br> | Windows 10, version 1803 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server, version 1709 \[desktop apps only\]<br> |
| Header<br> | Deliveryoptimization.h |