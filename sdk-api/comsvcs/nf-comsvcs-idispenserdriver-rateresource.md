# IDispenserDriver::RateResource

## Description

Evaluates how well a candidate resource matches.

## Parameters

### `ResTypId` [in]

The type of resource that the Dispenser Manager is looking to match.

### `ResId` [in]

The candidate resource that the Dispenser Manager is considering.

### `fRequiresTransactionEnlistment` [in]

If **TRUE**, the candidate resource (*ResId*), if chosen, requires transaction enlistment. If enlistment is expensive, **RateResource** might rate such a resource lower than a resource that is already enlisted in the correct transaction.

### `pRating` [out]

The Dispenser's rating of this candidate. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| 0 | The candidate resource is unusable for this request. The resource is not or cannot be changed to be of type *ResTypId*. |
| 1 | The candidate is a bad fit, but usable. The Dispenser Manager will continue to suggest candidates. |
| 2 | The candidate is better than candidates rated as 1. The Dispenser Manager will continue to suggest candidates. |
| 100 | The candidate is a perfect fit. The Dispenser Manager will stop suggesting candidates. |

## Return value

If the method succeeds, the return value is S_OK. Otherwise, it is E_FAIL.

## Remarks

If *fRequiresTransactionEnlistment* is **FALSE**, an object was dispensed this resource in this transaction, the object used and then freed the resource (explicitly or implicitly at end of object lifetime). A second object in the same transaction asks for a similar resource, and the resource that the first object used is considered. This resource is a good candidate because it is already enlisted in the correct transaction.

If a particular type of resource can be used only once per transaction, a resource that has already been used once in the transaction can be identified by an *fRequiresTransactionEnlistment* of **FALSE** and can be rejected for further use by returning **pRating*=0.

## See also

[IDispenserDriver](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-idispenserdriver)