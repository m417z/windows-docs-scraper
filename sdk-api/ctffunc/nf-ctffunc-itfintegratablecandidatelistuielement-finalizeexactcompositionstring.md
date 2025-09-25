# ITfIntegratableCandidateListUIElement::FinalizeExactCompositionString

## Description

Finalizes the current composition with the value currently shown to the user.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

The **FinalizeExactCompositionString** method enables an app to tell the text service that it should finalize the current composition with the exact
value currently shown to the user, with no automatic conversion of the first candidate. This enables the apps to move focus
to suggestions below the candidate list, without changing the string.

## See also

[ITfIntegratableCandidateListUIElement](https://learn.microsoft.com/windows/desktop/api/ctffunc/nn-ctffunc-itfintegratablecandidatelistuielement)