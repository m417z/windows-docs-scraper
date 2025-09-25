# CRYPT_XML_KEY_INFO structure

## Description

The **CRYPT_XML_KEY_INFO** structure encapsulates key information data.

## Members

### `cbSize`

The size, in bytes, of this structure.

### `wszId`

A pointer to a null-terminated wide character string that specifies the value of the **ID** attribute of the key information element.

### `cKeyInfo`

The number of items in the array pointed to by the **rgKeyInfo** member.

### `rgKeyInfo`

A pointer to an array of [CRYPT_XML_KEY_INFO_ITEM](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_key_info_item) structures that contain key information.

### `hVerifyKey`

Optional. The handle of data derived from the first key value.