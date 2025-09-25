# TF_LANGBARITEMINFO structure

## Description

The **TF_LANGBARITEMINFO** structure is used to hold information about a language bar item.

## Members

### `clsidService`

Contains the **CLSID** of the text service that owns the language bar item. This can be CLSID_NULL if the item is not provided by a text service.

### `guidItem`

Contains a **GUID** value that identifies the language bar item.

Starting with Windows 8, this value should be GUID_LBI_INPUTMODE (or the language bar item will be ignored). For more information, see [Third-party input method editors](https://docs.microsoft.com/en-us/windows/win32/w8cookbook/third-party-input-method-editors#manifestation) in the Compatibility cookbook for Windows.

### `dwStyle`

Contains a combination of one or more of the [TF_LBI_STYLE_*](https://learn.microsoft.com/windows/desktop/TSF/tf-lbi-style--constants) values.

### `ulSort`

Specifies the sort order of the language bar item, relative to other language bar items owned by the text service. A lower number indicates that the item will be displayed prior to an item with a higher sort number.

This value is only used if **clsidService** identifies a registered text service. For more information about registering a text service, see [ITfInputProcessorProfiles::Register](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfinputprocessorprofiles-register).

### `szDescription`

Contains the description string for the item in Unicode format. The description string is displayed in the language bar options menu for menu items. This buffer can hold up to TF_LBI_DESC_MAXLEN characters.

## See also

[ITfInputProcessorProfiles::Register](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfinputprocessorprofiles-register)

[TF_LBI_STYLE_*](https://learn.microsoft.com/windows/desktop/TSF/tf-lbi-style--constants)