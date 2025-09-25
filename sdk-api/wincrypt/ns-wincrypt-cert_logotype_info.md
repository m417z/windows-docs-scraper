# CERT_LOGOTYPE_INFO structure

## Description

The **CERT_LOGOTYPE_INFO** structure contains information about logotype data.

## Members

### `dwLogotypeInfoChoice`

Specifies the type of logotype data. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CERT_LOGOTYPE_DIRECT_INFO_CHOICE** | The logotype data is available directly. The **pLogotypeDirectInfo** member contains the actual logotype data. |
| **CERT_LOGOTYPE_INDIRECT_INFO_CHOICE** | The logotype data is available through a reference. The **pLogotypeIndirectInfo** member contains a reference to the logotype information. |

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.pLogotypeDirectInfo`

The address of a [CERT_LOGOTYPE_DATA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_logotype_data) structure that contains the actual logotype data. This member is only used if the **dwLogotypeInfoChoice** member contains **CERT_LOGOTYPE_DIRECT_INFO_CHOICE**.

### `DUMMYUNIONNAME.pLogotypeIndirectInfo`

The address of a [CERT_LOGOTYPE_REFERENCE](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_logotype_reference) structure that contains references to the logotype data. This member is only used if the **dwLogotypeInfoChoice** member contains **CERT_LOGOTYPE_INDIRECT_INFO_CHOICE**.

## See also

[CERT_LOGOTYPE_EXT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_logotype_ext_info)