# IVdsProviderPrivate::OnLoad

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Prompts the provider to
initialize itself, and passes a callback object that the provider uses to get necessary interfaces.

## Parameters

### `pwszMachineName` [in]

This parameter is reserved.

### `pCallbackObject` [in]

Pointer to a callback object.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The provider is initialized. |
| **VDS_E_INITIALIZED_FAILED**<br><br>0x80042401L | The provider failed to initialize. |

## Remarks

VDS calls this method immediately after calling the [CoCreateInstance](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstance) method on a provider.

Implementers must implement this method. Invoke the [IUnknown::QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) method
to query for the [IVdsAdviseSink](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsadvisesink) interface.

## See also

[IVdsAdviseSink](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsadvisesink)

[IVdsProviderPrivate](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsproviderprivate)

[IVdsProviderPrivate::OnUnload](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsproviderprivate-onunload)