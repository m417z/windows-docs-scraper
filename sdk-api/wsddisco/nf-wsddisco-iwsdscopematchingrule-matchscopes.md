# IWSDScopeMatchingRule::MatchScopes

## Description

Is called to compare two scopes to determine if they match.

## Parameters

### `pszScope1` [in]

Pointer to the first scope matching rule.

### `pszScope2` [in]

Pointer to the second scope matching rule.

### `pfMatch` [out]

Set to **TRUE** if the scopes received via *pszScope1* and *pszScope2* match, **FALSE** otherwise.

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |

## Remarks

**MatchScopes** will be called on custom scope matching rules to determine whether or not the two scopes provided match. *pfMatch* should be assigned either **TRUE** or **FALSE** to indicate the match status.

## See also

[IWSDScopeMatchingRule](https://learn.microsoft.com/windows/desktop/api/wsddisco/nn-wsddisco-iwsdscopematchingrule)