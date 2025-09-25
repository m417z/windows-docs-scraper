# WSDXMLGetNameFromBuiltinNamespace function

## Description

Gets a specified name from the built-in namespace.

## Parameters

### `pszNamespace`

The namespace to match with a built-in namespace.

### `pszName`

The name to match with a built-in name.

### `ppName`

Reference to a [WSDXML_NAME](https://learn.microsoft.com/windows/desktop/api/wsdxmldom/ns-wsdxmldom-wsdxml_name) structure that contains the returned built-in name. The memory usage of *ppName* is managed elsewhere. Consequently, the calling application should not attempt to deallocate *ppName*.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_INVALIDARG** | *pszNamespace* is **NULL**, *pszName* is **NULL**, the length in characters of *pszNamespace* exceeds WSD_MAX_TEXT_LENGTH (8192), the length in characters of *pszName* exceeds WSD_MAX_TEXT_LENGTH (8192), or there was no matching name in the built-in namespace. |
| **E_POINTER** | *ppName* is **NULL**. |