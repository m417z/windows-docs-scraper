# IReconcileInitiator::SetProgressFeedback

## Description

Indicates the amount of progress the briefcase reconciler has made toward completing the reconciliation. The amount is a fraction and is computed as the quotient of the *ulProgress* and *ulProgressMax* parameters. Reconcilers should call this method periodically during their reconciliation process.

## Parameters

### `ulProgress`

Type: **ULONG**

The numerator of the progress fraction.

### `ulProgressMax`

Type: **ULONG**

The denominator of the progress fraction.

## Return value

Type: **HRESULT**

Returns the S_OK value if successful, or the E_UNEXPECTED value if an unspecified error occurred.

## Remarks

The initiator typically uses this measure of progress to update a thermometer gauge or some other form of visual feedback for the user. The briefcase reconciler can change the value of *ulProgressMax* from call to call. This means successive calls to this method do not necessarily indicate steady forward progress. Backward progress is legal, although not desirable. It is the responsibility of the initiator to determine whether backward progress should be revealed to the user.

## See also

[IReconcileInitiator](https://learn.microsoft.com/windows/desktop/lwef/ireconcileinitiator)