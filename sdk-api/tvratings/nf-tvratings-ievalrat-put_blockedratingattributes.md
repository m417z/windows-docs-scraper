# IEvalRat::put_BlockedRatingAttributes

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_BlockedRatingAttributes** method specifies whether to block content that has a specified rating.

## Parameters

### `enSystem` [in]

Specifies the rating system, as an [EnTvRat_System](https://learn.microsoft.com/previous-versions/dd375612(v=vs.85)) enumeration type.

### `enLevel` [in]

Specifies the rating level, as an [EnTvRat_GenericLevel](https://learn.microsoft.com/previous-versions/dd375610(v=vs.85)) enumeration type. The meaning of this value depends on the rating system.

### `lbfAttrs` [in]

Bitwise combination of zero or more flags from the [BfEnTvRat_GenericAttributes](https://learn.microsoft.com/previous-versions/dd318226(v=vs.85)) enumeration. The flags specify whether the overall rating is blocked, or specific attributes within the rating are blocked.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This method should be called once for each level in a rating system, to specify viewing permissions for that level. The *lbfAttrs* parameter indicates the permissions for the specified rating level:

* If no flags are set, this rating level is unrestricted. Any program with this rating level can be viewed.
* If the **BflsBlocked** flag is set, this rating level is restricted. No program with this rating level can be viewed.
* Flags in the range **BfIsAttr_1** to **BfIsAttr_7** specify content attributes, such as violence or adult language. If one of these flags is set, it means that a program with that content attribute and the specified rating level will be blocked.

## See also

[IEvalRat Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tvratings/nn-tvratings-ievalrat)