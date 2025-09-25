# IVssEnumMgmtObject::Next

## Description

The **Next** method
returns the specified number of objects from the specified list of enumerated objects.

## Parameters

### `celt` [in]

The number of elements to be read from the list of enumerated objects into the *rgelt* buffer.

### `rgelt` [out]

The address of a caller-allocated buffer that receives *celt*[VSS_MGMT_OBJECT_PROP](https://learn.microsoft.com/windows/desktop/api/vsmgmt/ns-vsmgmt-vss_mgmt_object_prop) structures that contain the
returned objects. This parameter is required and cannot be **NULL**.

### `pceltFetched` [out]

The number of elements that were returned in the *rgelt* buffer.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IVssEnumMgmtObject](https://learn.microsoft.com/windows/desktop/api/vsmgmt/nn-vsmgmt-ivssenummgmtobject)

[VSS_MGMT_OBJECT_PROP](https://learn.microsoft.com/windows/desktop/api/vsmgmt/ns-vsmgmt-vss_mgmt_object_prop)