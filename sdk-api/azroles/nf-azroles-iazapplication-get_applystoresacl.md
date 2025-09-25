# IAzApplication::get_ApplyStoreSacl

## Description

The **ApplyStoreSacl** property sets or retrieves a value that indicates whether policy audits should be generated when the authorization store is modified.

This property is read/write.

## Parameters

## Remarks

Policy audits are generated when the underlying policy store is modified. Both success and failure audits are requested.

This property controls policy auditing only for the [IAzApplication](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazapplication) object and its child objects.