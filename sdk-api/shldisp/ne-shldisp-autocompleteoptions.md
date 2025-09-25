# AUTOCOMPLETEOPTIONS enumeration

## Description

Specifies values used by [IAutoComplete2::GetOptions](https://learn.microsoft.com/windows/desktop/api/shldisp/nf-shldisp-iautocomplete2-getoptions) and [IAutoComplete2::SetOptions](https://learn.microsoft.com/windows/desktop/api/shldisp/nf-shldisp-iautocomplete2-setoptions) for options surrounding autocomplete.

## Constants

### `ACO_NONE:0`

0x0000. Do not autocomplete.

### `ACO_AUTOSUGGEST:0x1`

0x0001. Enable the autosuggest drop-down list.

### `ACO_AUTOAPPEND:0x2`

0x0002. Enable autoappend.

### `ACO_SEARCH:0x4`

0x0004. Add a search item to the list of completed strings. When the user selects this item, it launches a search engine.

### `ACO_FILTERPREFIXES:0x8`

0x0008. Do not match common prefixes, such as "www." or "http://".

### `ACO_USETAB:0x10`

0x0010. Use the TAB key to select an item from the drop-down list.

### `ACO_UPDOWNKEYDROPSLIST:0x20`

0x0020. Use the UP ARROW and DOWN ARROW keys to display the autosuggest drop-down list.

### `ACO_RTLREADING:0x40`

0x0040. Normal windows display text left-to-right (LTR). Windows can be mirrored to display languages such as Hebrew or Arabic that read right-to-left (RTL). Typically, control text is displayed in the same direction as the text in its parent window. If [ACO_RTLREADING](https://learn.microsoft.com/windows/desktop/api/shldisp/ne-shldisp-autocompleteoptions) is set, the text reads in the opposite direction from the text in the parent window.

### `ACO_WORD_FILTER:0x80`

0x0080. **Windows Vista and later**. If set, the autocompleted suggestion is treated as a phrase for search purposes. The suggestion, *Microsoft Office*, would be treated as *"Microsoft Office"* (where both *Microsoft* AND *Office* must appear in the search results).

### `ACO_NOPREFIXFILTERING:0x100`

0x0100. **Windows Vista and later**. Disable prefix filtering when displaying the autosuggest dropdown. Always display all suggestions.