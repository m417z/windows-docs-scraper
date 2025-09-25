# ICertAdmin2::DeleteRow

## Description

The **DeleteRow** method deletes a row or set of rows from a database table. The caller specifies a database table and either a row ID or an ending date.

## Parameters

### `strConfig` [in]

Represents a valid configuration string for the [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA) in the form COMPUTERNAME\CANAME, where COMPUTERNAME is the Certificate Services server's network name, and CANAME is the common name of the certification authority, as entered during Certificate Services setup. For information about the configuration string name, see [ICertConfig](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertconfig).

**Important** **DeleteRow** does not clear the internal cache when the configuration string is changed. When you change the configuration string for the CA, you must instantiate a new [ICertAdmin](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-icertadmin2) object and call this method again with the new configuration string.

### `Flags` [in]

If not zero, specifies whether *Date* applies to an expiration date or a last modified date.

This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CDR_EXPIRED** | The rows being deleted have an expiration date less than *Date*. This flag can be used when *Table* is CVRC_TABLE_REQCERT or CVRC_TABLE_CRL. |
| **CDR_REQUEST_LAST_CHANGED** | The rows being deleted are for pending or denied requests, and their last modified date is less than *Date*. This flag can be used when *Table* is CVRC_TABLE_REQCERT. |

### `Date` [in]

Specifies an expiration date when deleting certificates or CRLs, and a last modified date when deleting certificate requests.

If this value is not zero, then *RowID* must be zero.

### `Table` [in]

A **LONG** value that specifies the Certificate Services database table from which the rows are to be deleted.

This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CVRC_TABLE_ATTRIBUTES** | The [attributes](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) table is used. |
| **CVRC_TABLE_CRL** | The [certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRL) table is used. |
| **CVRC_TABLE_EXTENSIONS** | The extensions table is used. |
| **CVRC_TABLE_REQCERT** | The table of pending requests, denied requests, issued certificates, and revoked certificates is used. |

### `RowId` [in]

Specifies the ID of the row to delete.

If this value is not zero, then *Date* must be zero.

### `pcDeleted` [out]

The number of rows successfully deleted.

## Return value

### C++

The return value is an **HRESULT**. A value of S_OK indicates the method was successful, and **pcDeleted* is set to the number of rows deleted.

### VB

The number of rows deleted.

## Remarks

*RowID* and *Date* are mutually exclusive; one and only one of them can be nonzero.

## See also

**CCertAdmin**

[ICertAdmin](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-icertadmin)

[ICertAdmin2](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-icertadmin2)