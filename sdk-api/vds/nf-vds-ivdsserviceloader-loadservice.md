# IVdsServiceLoader::LoadService

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Launches VDS on the specified computer and returns a pointer to the service object.

## Parameters

### `pwszMachineName` [in]

This parameter must be set to **NULL**.

**Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista and Windows Server 2003:** This parameter contains the name of the host computer. Setting it to **NULL** causes VDS to be loaded and initialized on the local host.

### `ppService` [out]

The address of an [IVdsService](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsservice) interface pointer. Callers must release the interface when it is no longer needed by calling the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The service has launched successfully. |

## Remarks

Although **S_OK** indicates that VDS has launched successfully, the service initialization can be incomplete when the method returns. For this reason, after calling this method, you must call the [IVdsService::WaitForServiceReady](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsservice-waitforserviceready) method to wait for VDS initialization to complete.

For a code example, see [Loading VDS](https://learn.microsoft.com/windows/desktop/VDS/loading-vds).

## See also

[IVdsService](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsservice)

[IVdsService::WaitForServiceReady](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsservice-waitforserviceready)

[IVdsServiceLoader](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsserviceloader)