# ISpellChecker::remove_SpellCheckerChanged

## Description

Removes an event handler ([ISpellCheckerChangedEventHandler](https://learn.microsoft.com/windows/desktop/api/spellcheck/nn-spellcheck-ispellcheckerchangedeventhandler)) that has been added for the SpellCheckerChanged event.

## Parameters

### `eventCookie` [in]

The event cookie that uniquely identifies the added handler. This is the *eventCookie* that was obtained from the call to [add_SpellCheckerChanged](https://learn.microsoft.com/windows/desktop/api/spellcheck/nf-spellcheck-ispellchecker-add_spellcheckerchanged).

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ISpellChecker](https://learn.microsoft.com/windows/desktop/api/spellcheck/nn-spellcheck-ispellchecker)

[ISpellCheckerChangedEventHandler](https://learn.microsoft.com/windows/desktop/api/spellcheck/nn-spellcheck-ispellcheckerchangedeventhandler)

[add_SpellCheckerChanged](https://learn.microsoft.com/windows/desktop/api/spellcheck/nf-spellcheck-ispellchecker-add_spellcheckerchanged)