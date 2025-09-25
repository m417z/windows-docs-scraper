# CRL_DIST_POINT_NAME structure

## Description

The **CRL_DIST_POINT_NAME** structure identifies a location from which the CRL can be obtained. When **CRL_DIST_POINT_NAME** is used, different forms of the CRL distribution point name appear in the **FullName** member of the [CERT_ALT_NAME_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_alt_name_info) structure. An application need not be able to process all of the name forms in the structure. It can use a distribution point if at least one name form can be processed.

If no name forms for a distribution point can be processed, an application can still use the certificate, provided requisite revocation information can be obtained from another source such as a distribution point of the [certification authority's](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA's) directory entry.

## Members

### `dwDistPointNameChoice`

Indicates the variant used for the name data contained in the union. The following values are defined:

| Value | Meaning |
| --- | --- |
| **CRL_DIST_POINT_NO_NAME** | No distribution point name is provided. |
| **CRL_DIST_POINT_FULL_NAME** | The distribution point name is in the **FullName** member of the union. |
| **CRL_DIST_POINT_ISSUER_RDN_NAME** | Currently not implemented. |

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.FullName`

A
[CERT_ALT_NAME_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_alt_name_info) structure containing an array of alternative names specifying the CRL distribution point in one of several different forms. One of the most common uses a URL in the form "http://…" to specify the location of the CRL.

## See also

[CERT_ALT_NAME_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_alt_name_info)

[CRL_DIST_POINT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crl_dist_point)