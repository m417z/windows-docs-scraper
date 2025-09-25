# IEvalRat::TestRating

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **TestRating** method determines whether a program with the specified rating should be blocked.

## Parameters

### `enShowSystem` [in]

Specifies the rating system, as an [EnTvRat_System](https://learn.microsoft.com/previous-versions/dd375612(v=vs.85)) enumeration type.

### `enShowLevel` [in]

Specifies the rating level, as an [EnTvRat_GenericLevel](https://learn.microsoft.com/previous-versions/dd375610(v=vs.85)) enumeration type. The meaning of this value depends on the rating system.

### `lbfEnShowAttributes` [in]

Bitwise combination of zero or more flags from the [BfEnTvRat_GenericAttributes](https://learn.microsoft.com/previous-versions/dd318226(v=vs.85)) enumeration. The flags specify content attributes, such as violence or adult language. Content attributes do not apply to all rating systems.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. |
| **S_FALSE** | This program is restricted and should be blocked. |
| **S_OK** | This program is allowed and should not be blocked. |

## Remarks

The application sets viewing permissions through the [IEvalRat::put_BlockedRatingAttributes](https://learn.microsoft.com/previous-versions/windows/desktop/api/tvratings/nf-tvratings-ievalrat-put_blockedratingattributes) method. Whenever the Decrypter/Detagger filter receives a new rating in a program, it calls **TestRating** to determine whether to block the program. If **TestRating** returns S_OK, the rating is restricted under the current set of viewing permissions, and the Decrypter/Tagger filter blocks the program.

### Implementation Note:

For each supported rating system, store a table that contains bitmasks for each level within that system. On object creation, initialize each bitmask to zero. Update the bitmasks in the [put_BlockedRatingAttributes](https://learn.microsoft.com/previous-versions/windows/desktop/api/encdec/nf-encdec-idtfilter-put_blockedratingattributes) method.

In the **TestRating** method, use the *enShowSystem* and *enShowLevel* parameters to perform a table lookup and get the corresponding bitmask. Return S_FALSE if either of the following tests are true:

* The **BfIsBlocked** flag is set in the bitmask
* Any attribute flag in *lbfEnShowAttributes* is also set in the bitmask.

Use a bitwise **AND** to test the bitmask. If neither test is true, return S_OK.

The following code shows a possible implementation. It assumes that the object stores the bitmasks in a two-dimensional array named Mask:

```cpp

if ((0 != Mask[system][level] & BfIsBlocked) ||
    (0 != Mask[system][level] & attributes))
{
    return S_FALSE; // Blocked.
}
else
{
    return S_OK; // Not blocked.
}

```

## See also

[IEvalRat Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tvratings/nn-tvratings-ievalrat)