# IVdsProviderPrivate::OnUnload

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Prompts the provider object to uninitialize itself.

## Parameters

### `bForceUnload` [in]

If true, VDS attempts to forcibly unload the provider. If false, VDS makes no such attempt.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The provider is unloaded. |
| **S_FALSE** | The provider is unable to unload at this time. VDS tries again later. |

## Remarks

VDS calls this method immediately before releasing the reference to the provider object. When the reference count drops to zero, the provider unloads. If the [OnLoad](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsproviderprivate-onload) method fails, VDS does not call **OnUnload**.

**Notes to implementers:** You must perform all necessary clean up, even without the call to **OnUnload**.

## See also

[IVdsProviderPrivate](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsproviderprivate)

[IVdsProviderPrivate::OnLoad](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsproviderprivate-onload)