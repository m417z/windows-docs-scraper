# IVdsAdmin::RegisterProvider

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Registers
the specified hardware provider with VDS. Hardware providers call this method.

## Parameters

### `providerId` [in]

The GUID of the hardware provider.

### `providerClsid` [in]

The COM class identifier (Clsid) of the hardware provider.

### `pwszName` [in]

The name of the hardware provider as a zero-terminated, human-readable string.

### `type` [in]

The provider types enumerated by [VDS_PROVIDER_TYPE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_provider_type).
Use the **VDS_PT_HARDWARE** value to register a hardware provider with VDS.

### `pwszMachineName` [in]

The name of the computer on which the hardware provider executes; a null-terminated, human-readable string.
Use **NULL** to reference the current computer.

### `pwszVersion` [in]

The version of the provider as a zero-terminated, human-readable string.

### `guidVersionId` [in]

The GUID for this version of the provider.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **VDS_E_ALREADY_REGISTERED**<br><br>0x80042403L | The *providerId* is already registered. Only one version of a provider can be registered at any given time. |

## Remarks

If necessary, call
[UnregisterProvider](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsadmin-unregisterprovider) to remove a provider
before registering a new version.

An in-process provider calls this method from
[DllRegisterServer](https://learn.microsoft.com/windows/desktop/api/olectl/nf-olectl-dllregisterserver); whereas, an out-of-process
provider calls from the
[WinMain](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-winmain)
function.

Hardware providers must not stop running while VDS is running.

## See also

[IVdsAdmin](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsadmin)

[IVdsAdmin::UnregisterProvider](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsadmin-unregisterprovider)

[VDS_PROVIDER_TYPE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_provider_type)