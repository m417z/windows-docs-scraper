# IVssEnumMgmtObject::Clone

## Description

The **Clone** method creates a copy of the
specified list of enumerated elements by creating a copy of the
[IVssEnumMgmtObject](https://learn.microsoft.com/windows/desktop/api/vsmgmt/nn-vsmgmt-ivssenummgmtobject) enumerator object.

## Parameters

### `ppenum` [in, out]

Address of an [IVssEnumMgmtObject](https://learn.microsoft.com/windows/desktop/api/vsmgmt/nn-vsmgmt-ivssenummgmtobject) interface
pointer. Set the value of this parameter to **NULL** before calling this method.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IVssEnumMgmtObject](https://learn.microsoft.com/windows/desktop/api/vsmgmt/nn-vsmgmt-ivssenummgmtobject)