# IDsAdminNewObjExt::GetSummaryInfo

## Description

The **IDsAdminNewObjExt::GetSummaryInfo** method obtains a string that contains a summary of the data gathered by the new object wizard extension page. This string is displayed in the wizard Finish page.

## Parameters

### `pBstrText` [out]

A pointer to a **BSTR** value that receives the summary text. To allocate this value, call [SysAllocString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstring). The caller must free this memory by calling [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring).

## Return value

If the method is successful, **S_OK** is returned. If the method fails, an OLE-defined error code is returned. If the extension does not provide a summary string, this method should return **E_NOTIMPL**.

## Remarks

Support of this method is optional. If the extension does not supply summary information, it should return **E_NOTIMPL** from this method.

## See also

[IDsAdminNewObjExt](https://learn.microsoft.com/windows/desktop/api/dsadmin/nn-dsadmin-idsadminnewobjext)

[SysAllocString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstring)

[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring)