# IADsADSystemInfo::RefreshSchemaCache

## Description

The **IADsADSystemInfo::RefreshSchemaCache** method refreshes the Active Directory schema cache.

## Return value

This method supports the standard **HRESULT** return values. For more information, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## Remarks

When you call this method, it does a Put() of the **schemaUpdateNow** function on the RootDSE. Normally, when you make changes to the schema, they are not updated to the RootDSE until the next automatic update. This method does an immediate update to the schema so that you can view the changes to the schema.

## See also

[ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes)

[IADsADSystemInfo](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsadsysteminfo)