# IVdsService::QueryDriveLetters

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Returns property details for a set of drive letters.

## Parameters

### `wcFirstLetter` [in]

The first drive letter to retrieve.

### `count` [in]

The total number of drive letters to retrieve.

### `pDriveLetterPropArray` [out]

The address of an array of [VDS_DRIVE_LETTER_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_drive_letter_prop) structures. The size of the array is *count*. Callers must allocate the memory for this array.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **VDS_E_INITIALIZED_FAILED**<br><br>0x80042401L | VDS failed to initialize. If an application calls this method before the service finishes initializing, the method is blocked until the initialization completes. If the initialization fails, this error is returned. |

## See also

[IVdsService](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsservice)

[VDS_DRIVE_LETTER_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_drive_letter_prop)