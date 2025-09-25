# ISpellChecker::add_SpellCheckerChanged

## Description

Adds an event handler ([ISpellCheckerChangedEventHandler](https://learn.microsoft.com/windows/desktop/api/spellcheck/nn-spellcheck-ispellcheckerchangedeventhandler)) for the SpellCheckerChanged event.

## Parameters

### `handler` [in]

The handler to invoke when the spell checker changes.

### `eventCookie` [out, retval]

An event cookie that uniquely identifies the added handler. This cookie must be passed to [remove_SpellCheckerChanged](https://learn.microsoft.com/windows/desktop/api/spellcheck/nf-spellcheck-ispellchecker-remove_spellcheckerchanged) to stop this handler from being invoked by spell checker changes.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The SpellCheckerChanged event fires whenever the state of the spell checker changes in a way such that any text that has been checked should be rechecked. This should happen when the contents of a word list changes, when an option changes, or when the default spell checker changes.

## See also

[ISpellChecker](https://learn.microsoft.com/windows/desktop/api/spellcheck/nn-spellcheck-ispellchecker)

[ISpellCheckerChangedEventHandler](https://learn.microsoft.com/windows/desktop/api/spellcheck/nn-spellcheck-ispellcheckerchangedeventhandler)

[remove_SpellCheckerChanged](https://learn.microsoft.com/windows/desktop/api/spellcheck/nf-spellcheck-ispellchecker-remove_spellcheckerchanged)