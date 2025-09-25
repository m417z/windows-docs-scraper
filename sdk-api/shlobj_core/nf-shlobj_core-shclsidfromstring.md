# SHCLSIDFromString function

## Description

[This function is available through Windows XP Service Pack 2 (SP2) and Windows Server 2003. It might be altered or unavailable in subsequent versions of Windows. Use [CLSIDFromString](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-clsidfromstring) instead.]

Takes the string form of a class identifier (CLSID) and creates the corresponding CLSID.

## Parameters

### `psz` [in]

Type: **PCWSTR**

A Unicode string that contains the CLSID in the format, `{xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx}`.

### `pclsid` [out]

Type: **CLSID***

A pointer to a CLSID value that, when this function returns successfully, receives the converted string as a CLSID.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.