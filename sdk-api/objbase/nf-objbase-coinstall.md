# CoInstall function

## Description

[This function is not supported and may be altered or unavailable in the future.]

Installs the requested COM server application.

## Parameters

### `pbc` [in]

Reserved for future use; this value must be **NULL**.

### `dwFlags` [in]

Reserved for future use; this value must be 0.

### `pClassSpec` [in]

A pointer to a **uCLSSPEC** union. The **tyspec** member must be set to TYSPEC_CLSID and the **clsid** member must be set to the CLSID to be installed. For more information, see [TYSPEC](https://learn.microsoft.com/windows/desktop/DevNotes/tyspec).

### `pQuery` [in]

A pointer to a [QUERYCONTEXT](https://learn.microsoft.com/previous-versions/bb432414(v=vs.85)) structure. The **dwContext** field must be set to the desired [CLSCTX](https://learn.microsoft.com/windows/desktop/api/wtypesbase/ne-wtypesbase-clsctx) value. For more information, see **QUERYCONTEXT**.

### `pszCodeBase` [in]

Reserved for future use; this value must be **NULL**.

## Return value

This function supports the standard return value E_INVALIDARG, as well as the following.

| Term | Description |
| --- | --- |
| S_OK | Indicates success. |
| CS_E_PACKAGE_NOTFOUND | The **tyspec** field of *pClassSpec* was not set to TYSPEC_CLSID. |

## See also

[QUERYCONTEXT](https://learn.microsoft.com/previous-versions/bb432414(v=vs.85))

[TYSPEC](https://learn.microsoft.com/windows/desktop/DevNotes/tyspec)