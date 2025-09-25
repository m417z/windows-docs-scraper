# WsReadQualifiedName function

## Description

Reads a qualified name and separates it into its prefix, localName
and namespace based on the current namespace scope of the XML_READER.
If the ns parameter is specified, then the namespace that the prefix
is bound to will be returned, or **WS_E_INVALID_FORMAT** will be returned. (See [Windows Web Services Return Values](https://learn.microsoft.com/windows/desktop/wsw/windows-web-services-return-values).) The strings are placed in the specified heap.

## Parameters

### `reader` [in]

The reader which should read the qualified name.

### `heap` [in]

The heap on which the resulting strings should be allocated.

### `prefix`

The prefix of the qualified name is returned here.

### `localName` [out]

The localName of the qualified name is returned here.

### `ns`

The namespace to which the qualified name is bound is returned here.

### `error` [in, optional]

If the localName is missing the function will return **WS_E_INVALID_FORMAT**.
If the ns parameter is specified, but the prefix is not bound to a namespace,
**WS_E_INVALID_FORMAT** will be returned.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **WS_E_INVALID_FORMAT** | The input data was not in the expected format or did not have the expected value. |