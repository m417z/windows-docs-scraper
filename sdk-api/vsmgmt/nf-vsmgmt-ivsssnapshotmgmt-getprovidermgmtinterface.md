# IVssSnapshotMgmt::GetProviderMgmtInterface

## Description

The
**GetProviderMgmtInterface**
method returns an interface to further configure the system provider.

## Parameters

### `ProviderId` [in]

This must be the system provider. The **VSS_ID** for the system provider `{b5946137-7b9f-4925-af80-51abd60b20d5}`.

### `InterfaceId` [in]

Must be **IID_IVssDifferentialSoftwareSnapshotMgmt**, which represents the
[IVssDifferentialSoftwareSnapshotMgmt](https://learn.microsoft.com/windows/desktop/api/vsmgmt/nn-vsmgmt-ivssdifferentialsoftwaresnapshotmgmt)
interface.

### `ppItf` [out]

Address of an interface pointer that is filled in with the returned interface pointer.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IVssDifferentialSoftwareSnapshotMgmt](https://learn.microsoft.com/windows/desktop/api/vsmgmt/nn-vsmgmt-ivssdifferentialsoftwaresnapshotmgmt)

[IVssSnapshotMgmt](https://learn.microsoft.com/windows/desktop/api/vsmgmt/nn-vsmgmt-ivsssnapshotmgmt)