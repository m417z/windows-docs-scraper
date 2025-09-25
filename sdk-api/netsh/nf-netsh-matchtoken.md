# MatchToken function

## Description

The
**MatchToken** function determines whether a user-entered string matches a specific string. A match exists if the user-entered string is a case-insensitive prefix of the specific string.

## Parameters

### `pwszUserToken` [in]

A string entered by the user.

### `pwszCmdToken` [in]

A string against which to check for a match.

## Return value

Returns **TRUE** if there is a match, **FALSE** if not.

## Remarks

The
**MatchToken** function is generally used by command functions. For arguments with an enumerated set of possible values, use the
[MatchEnumTag](https://learn.microsoft.com/previous-versions/windows/desktop/api/netsh/nf-netsh-matchenumtag) function instead.

One example of using
**MatchToken** is a command function that has an argument whose value can be an integer or the string "default". That command function might use
**MatchToken** to test whether the value matches the string "default" before interpreting it as an integer.

## See also

[MatchEnumTag](https://learn.microsoft.com/previous-versions/windows/desktop/api/netsh/nf-netsh-matchenumtag)