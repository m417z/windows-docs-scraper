# ICertAdmin2::SetCAProperty

## Description

The **SetCAProperty** method sets a property value for the [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA).

## Parameters

### `strConfig` [in]

String value that represents a valid configuration string for the CA in the form COMPUTERNAME\CANAME, where COMPUTERNAME is the Certificate Services server's network name, and CANAME is the common name of the CA, as entered during Certificate Services setup. For information about the configuration string name, see
[ICertConfig](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertconfig).

**Important** **SetCAProperty** does not clear the internal cache when the configuration string is changed. When you change the configuration string for the CA, you must instantiate a new [ICertAdmin](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-icertadmin2) object and call this method again with the new configuration string.

### `PropId` [in]

Specifies one of the following property identifiers.

For information about all CA properties, including those that are read-only, see [ICertAdmin2::GetCAProperty](https://learn.microsoft.com/windows/desktop/api/certadm/nf-certadm-icertadmin2-getcaproperty).

| Value | Meaning |
| --- | --- |
| **CR_PROP_KRACERT** | The CA's key recovery agent (KRA) certificate.<br><br>Data format: binary, indexed. |
| **CR_PROP_KRACERTCOUNT** | Number of KRA certificates for the CA.<br><br>Data format: **Long**. |
| **CR_PROP_KRACERTUSEDCOUNT** | Number of KRA certificates used by the CA.<br><br>Data format: **Long**. |
| **CR_PROP_ROLESEPARATIONENABLED** | Value that specifies whether role separation is enabled.<br><br>Data format: **Long**. |
| **CR_PROP_TEMPLATES** | List of templates supported by the CA.<br><br>Data format: **String**. |

### `PropIndex` [in]

If the *PropId* parameter is indexed, the zero-based index to use when retrieving the property value. If *PropId* is not indexed, this value is ignored.

### `PropType` [in]

Specifies the type of the property. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **PROPTYPE_LONG** | Signed **Long** data. |
| **PROPTYPE_DATE** | Date/Time (reserved for future use). |
| **PROPTYPE_BINARY** | Binary data. |
| **PROPTYPE_STRING** | [Unicode](https://learn.microsoft.com/windows/desktop/SecGloss/u-gly) **String** data. |

### `pvarPropertyValue` [in]

|  |  |
| --- | --- |
| **C++** | A pointer to a **VARIANT** that specifies the property value. |
| **VB** | A **Variant** that specifies the property value. |

## Return value

### VB

If the function is successful, the return value is S_OK.

If the function fails, the return value is an **HRESULT** that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[ICertAdmin2](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-icertadmin2)

[ICertAdmin2::GetCAProperty](https://learn.microsoft.com/windows/desktop/api/certadm/nf-certadm-icertadmin2-getcaproperty)