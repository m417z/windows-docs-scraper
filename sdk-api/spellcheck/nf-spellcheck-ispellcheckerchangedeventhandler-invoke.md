# ISpellCheckerChangedEventHandler::Invoke

## Description

Receives the SpellCheckerChanged event.

## Parameters

### `sender` [in]

The [ISpellChecker](https://learn.microsoft.com/windows/desktop/api/spellcheck/nn-spellcheck-ispellchecker) that fired the event.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is called when there is a change to the state of the spell checker that could cause text to be treated differently. A client should recheck the text when this event is received.

## See also

[ISpellChecker](https://learn.microsoft.com/windows/desktop/api/spellcheck/nn-spellcheck-ispellchecker)

[ISpellCheckerChangedEventHandler](https://learn.microsoft.com/windows/desktop/api/spellcheck/nn-spellcheck-ispellcheckerchangedeventhandler)