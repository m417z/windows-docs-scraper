# IVdsAdmin::UnregisterProvider

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Removes VDS provider registration data. Hardware providers call this method.

## Parameters

### `providerId`

The GUID of the provider.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used.

## Remarks

An in-process provider calls this method from the
[DllRegisterServer](https://learn.microsoft.com/windows/desktop/api/olectl/nf-olectl-dllregisterserver) function; whereas, an out-of-process
provider calls from the
[WinMain](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-winmain)
function.

## See also

[IVdsAdmin](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsadmin)

[IVdsAdmin::RegisterProvider](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsadmin-registerprovider)