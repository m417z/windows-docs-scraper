# CryptXmlDigestReference function

## Description

The **CryptXmlDigestReference** function is used by an application to digest the resolved reference. This function applies transforms before updating the digest.

## Parameters

### `hReference` [in]

The handle of a **Reference** element.

### `dwFlags`

Specifies values that control how the process applies transforms.

Currently defined *dwFlags* are shown in the following table.

| Value | Meaning |
| --- | --- |
| **CRYPT_XML_REFERENCE_DATA_TRANSFORMED**<br><br>0x00000001 | Specifies that the processing engine will create the digest without applying the transform chain engine. |

### `pDataProviderIn` [in]

A pointer to a [CRYPT_XML_DATA_PROVIDER](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_data_provider) structure that specifies the data provider. The **CryptXmlDigestReference** function always calls the **fpnClose** function on the data provider.

## Return value

If the function succeeds, the function returns zero.

If the function fails, it returns an **HRESULT** value that indicates the error.

## Remarks

 When the **CRYPT_XML_REFERENCE_DATA_TRANSFORMED** flag is set,
the processing engine adds received data directly to the digest without
applying the transform chain engine.

**Note** The **CryptXmlDigestReference** function always calls the function pointed to by the **fpnClose** member of the [CRYPT_XML_DATA_PROVIDER](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_data_provider) structure pointed to by the *pDataProviderIn* parameter.