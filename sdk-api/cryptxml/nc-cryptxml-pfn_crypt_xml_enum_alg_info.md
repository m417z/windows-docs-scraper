# PFN_CRYPT_XML_ENUM_ALG_INFO callback function

## Description

The *PFN_CRYPT_XML_ENUM_ALG_INFO* callback function enumerates predefined and registered
[CRYPT_XML_ALGORITHM_INFO](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_algorithm_info) entries.

## Parameters

### `pInfo` [in]

A pointer to a [CRYPT_XML_ALGORITHM_INFO](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_algorithm_info) structure.

### `pvArg` [in, out, optional]

A pointer to an argument that is passed to the callback function from the calling function.

## Return value

If the function succeeds, the function returns **TRUE**.

If the function fails, it returns **FALSE**.

## Remarks

If the callback function returns **FALSE**, then stop the enumeration.

 This function enumerates either the predefined and registered
entries or the structures identified by a selected URI group.