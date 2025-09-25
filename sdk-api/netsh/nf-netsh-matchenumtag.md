# MatchEnumTag function

## Description

The
**MatchEnumTag** function searches a table of legal values to find a value that matches a specific token. The
**MatchEnumTag** function is typically called by a command function when an argument is specified that has an enumerated set of possible values.

## Parameters

### `hModule`

Reserved. Set to null.

### `pwcArg` [in]

A token to match. The *pwcArg* parameter is usually an entry in the *ppwcArguments* array passed into the
[FN_HANDLE_CMD](https://learn.microsoft.com/previous-versions/windows/desktop/api/netsh/nc-netsh-fn_handle_cmd) function exposed by the helper (the command function).

### `dwNumArg` [in]

The number of entries in the *pEnumTable* array.

### `pEnumTable` [in]

An array of token:value pairs.

### `pdwValue` [out]

Upon success, the *pdwValue* parameter is filled with the value associated with the token in the *pEnumTable* array.

## See also

[FN_HANDLE_CMD](https://learn.microsoft.com/previous-versions/windows/desktop/api/netsh/nc-netsh-fn_handle_cmd)