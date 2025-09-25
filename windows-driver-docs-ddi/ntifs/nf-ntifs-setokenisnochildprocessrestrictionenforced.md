# SeTokenIsNoChildProcessRestrictionEnforced function

## Description

The **SeTokenIsNoChildProcessRestrictionEnforced** routine determines if the token carries the no child process restriction.

## Parameters

### `Token` [in]

Specifies a pointer to the access token.

### `UnlessSecure` [out, optional]

Optionally provides a pointer to the value that will
be set to TRUE when secure process creation is enabled even if
process creation is restricted.

## Return value

This routine returns **TRUE** if *Token* carries the no child process restriction.