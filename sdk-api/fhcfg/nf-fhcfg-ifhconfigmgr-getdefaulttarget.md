# IFhConfigMgr::GetDefaultTarget

## Description

Returns a pointer to an [IFhTarget](https://learn.microsoft.com/windows/desktop/api/fhcfg/nn-fhcfg-ifhtarget) interface that can be used to query information about the currently assigned backup target.

> [!NOTE]
> **IFhConfigMgr** is deprecated and may be altered or unavailable in future releases.

## Parameters

### `DefaultTarget` [out]

Receives a pointer to the [IFhTarget](https://learn.microsoft.com/windows/desktop/api/fhcfg/nn-fhcfg-ifhtarget) interface of an object that represents the currently assigned default target, or **NULL** if there is no default target.

## Return value

**S_OK** on success, or an unsuccessful **HRESULT** value on failure. Possible unsuccessful **HRESULT** values include values defined in the FhErrors.h header file.

## Remarks

If no backup target is currently assigned, this method returns `HRESULT_FROM_WIN32(ERROR_NOT_FOUND)`.

## See also

[FhConfigMgr](https://learn.microsoft.com/windows/desktop/DevNotes/fhconfigmgr)

[IFhConfigMgr](https://learn.microsoft.com/windows/desktop/api/fhcfg/nn-fhcfg-ifhconfigmgr)

[IFhTarget](https://learn.microsoft.com/windows/desktop/api/fhcfg/nn-fhcfg-ifhtarget)